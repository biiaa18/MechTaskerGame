// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StaticDataAsset.h"
#include "ActiveLevelDataAsset.generated.h"

/**
 this is "copy" of the static asset, but in this class values change based on the level and player activity 

 we get starter values from the instance of level we need (instance of StaticDataAsset)
 */
UCLASS(Blueprintable)
class MECHTASKER_API UActiveLevelDataAsset : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	int TotalPieces;
	

	void loadAllStarterValues(UStaticDataAsset* levelDataInstance);
};
