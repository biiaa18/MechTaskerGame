// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
void AMyGameModeBase::BeginPlay() {
	Super::BeginPlay();

	if (levelData) {
		//better memory management than new UActiveLevelDataAsset()
		runtimeLevelData = NewObject<UActiveLevelDataAsset>(this);
		//will be specific values from the instance we assigned in the editor
		runtimeLevelData->loadAllStarterValues(levelData);
	}
}
