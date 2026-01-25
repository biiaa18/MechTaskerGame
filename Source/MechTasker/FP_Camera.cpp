// Fill out your copyright notice in the Description page of Project Settings.


#include "FP_Camera.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AFP_Camera::AFP_Camera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComp->SetupAttachment(RootComponent);
	CameraComp->bUsePawnControlRotation = true;

}

// Called when the game starts or when spawned
void AFP_Camera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFP_Camera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

