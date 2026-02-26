// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticDataAsset.h"
#include "Pickup.h"
#include "EngineUtils.h"

void UStaticDataAsset::getTotalFromWorld(UWorld* world)
{
	int count = 0;
	for (TActorIterator<APickup> It(world); It; ++It) {
		count++;
	}

	TotalPieces = count;
}
