// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StaticDataAsset.h"
#include "Components/TextBlock.h"
#include "ui.generated.h"

/**
 * 
 */
UCLASS()
class MECHTASKER_API Uui : public UUserWidget
{
	GENERATED_BODY()

public:
	//UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UStaticDataAsset> data;


	virtual void NativeConstruct() override;

public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* totalPieces;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* AmountMoonlitDew;


	UFUNCTION(BlueprintCallable)
	int setValue();


	void setTotalPieces(int totalPieceee);
	void SetMoonlitDew(int numberMoonlitDew);
	//void SetDrakeHerb(int numberDrakeHerb);
};
