// Fill out your copyright notice in the Description page of Project Settings.


#include "Truck.h"
#include "Pickup.h"


// Sets default values
ATruck::ATruck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//IMPORTANT: ROOT COMPONENT IN BP SHOULD BE COLLISION
	//AND OVERLAP DOESNT TRIGGER UNTIL THERE IS SOME MOVEMENT
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Colision root"));
	RootComponent = CollisionBox;
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionBox->SetCollisionResponseToAllChannels(ECR_Overlap);
	CollisionBox->SetHiddenInGame(false);

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ATruck::OnOverlap);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ATruck::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ATruck::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATruck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATruck::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 BodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{

	if (OtherActor && OtherActor->IsA( APickup::StaticClass())) {
		overlappedActors++;
		UE_LOG(LogTemp, Warning, TEXT("begin OVERLAP and +1"));
	}
}

void ATruck::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 BodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("END OVERLAP"));
	if (OtherActor && OtherActor->IsA(APickup::StaticClass())) {

		overlappedActors--;
		UE_LOG(LogTemp, Warning, TEXT("DECREASEEEEEEEEEEEED overlapps"));
	}
}

