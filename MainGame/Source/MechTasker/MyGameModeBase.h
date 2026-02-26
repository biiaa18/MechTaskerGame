// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "ActiveLevelDataAsset.h"
#include "StaticDataAsset.h"
#include "MyGameModeBase.generated.h"

/**
 each level will use this game mode and will be able to assign specific  level starter data (instance BP of static data set)
game mode will make runtime data asset only during the level being active and ui can display it and all the changes
 */
UCLASS()
class MECHTASKER_API AMyGameModeBase : public AGameMode
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	//we want to read starter values only, for the runtime data
	//edit anywhere is for access
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Game Mode")
	UStaticDataAsset* levelData;

	//we want ui to read from runtime data
	UPROPERTY(BlueprintReadOnly, Category = "Level Data")
	UActiveLevelDataAsset* runtimeLevelData;
};
