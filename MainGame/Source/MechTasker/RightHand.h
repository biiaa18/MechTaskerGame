// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RightHand.generated.h"

struct FInputActionValue;

UCLASS()
class MECHTASKER_API ARightHand : public ACharacter
{
	GENERATED_BODY()



public:
	// Sets default values for this character's properties
	ARightHand();

	UPROPERTY(EditAnywhere, Category = "Hand Components")
	USkeletalMeshComponent* RightHandMesh;

	UPROPERTY(EditAnywhere, Category = "Hand Components")
	UStaticMeshComponent* PlaceholderMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Hand Attributes")
	float speed = 200.f;


	/// Input

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	class UInputMappingContext* RightHandIMC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	class UInputAction* GrabAction;

	void Move(const FInputActionValue& Value);

	UFUNCTION()
	void Grab();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
