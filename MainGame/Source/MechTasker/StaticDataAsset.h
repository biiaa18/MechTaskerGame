// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StaticDataAsset.generated.h"

/**
 this is where we have every possible value we need for the levels
 we want values to be uproperty editanywhere, because:
 1. we use INSTANCE of this data asset for corresponding levels
 2. we need different starting values for each level 
 */
UCLASS(BlueprintType)
class MECHTASKER_API UStaticDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	//variables
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int TotalPieces;

	//visibility bools
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bTotalPieces=true;

	void getTotalFromWorld(UWorld* world);

};
