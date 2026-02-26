// Fill out your copyright notice in the Description page of Project Settings.


#include "ActiveLevelDataAsset.h"

void UActiveLevelDataAsset::loadAllStarterValues(UStaticDataAsset* levelDataInstance)
{
	TotalPieces = levelDataInstance->TotalPieces;
}
