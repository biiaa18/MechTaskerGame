// Fill out your copyright notice in the Description page of Project Settings.


#include "RightHand.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"

// Sets default values
ARightHand::ARightHand()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RightHandMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Right Hand Mesh"));

}

// Called when the game starts or when spawned
void ARightHand::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARightHand::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr) {
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void ARightHand::Grab()
{

}

// Called every frame
void ARightHand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARightHand::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

