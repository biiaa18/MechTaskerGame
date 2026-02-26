// Fill out your copyright notice in the Description page of Project Settings.


#include "ui.h"
#include "Truck.h"
#include "EngineUtils.h"

void Uui::NativeConstruct()
{
	Super::NativeConstruct();

	/*DropCrimsonBerries_btn->OnClicked.AddDynamic(this, &UPlayerWidgetHUD::OnClickCrimseBerries);
	DropMoonlitDew_btn->OnClicked.AddDynamic(this, &UPlayerWidgetHUD::OnClickMoonlitDew);
	DropDrakeHerb_btn->OnClicked.AddDynamic(this, &UPlayerWidgetHUD::OnClickDrakeHerb);*/
	//FString bpResource = "/Game/Blueprints/Level1.Level1";//object path for this EFFECT BP
	//UBlueprint* GeneratedBP = Cast<UBlueprint>(StaticLoadObject(UBlueprint::StaticClass(), NULL, *bpResource));
	//if (!GeneratedBP)
	//	return;
	//UClass* BPClass=GeneratedBP->GeneratedClass;	
	//if (!BPClass)
	//	return;
	//data = Cast<UStaticDataAsset>(BPClass->GetDefaultObject());
	//if (data)
	//	setTotalPieces(data->TotalPieces);

	/*for (TActorIterator<ATruck> It(GetWorld()); It; ++It) {
		truck = *It;
		break;
	}*/
}


void Uui::makeTruck()
{
	for (TActorIterator<ATruck> It(GetWorld()); It; ++It) {
		truck = *It;
		break;
	}
}

void Uui::NativeTick(const FGeometry& geometry, float deltaTime)
{
	Super::NativeTick(geometry, deltaTime);

	if (truck) {
		//UE_LOG(LogTemp, Warning, TEXT("SETTING OVERLAPPED"));
		SetMoonlitDew(truck->getoverlapped());
	}
	

}

int Uui::setValue()
{
	FString bpResource = "/Game/Blueprints/Level1.Level1";//object path
	UStaticDataAsset* GeneratedBP = Cast<UStaticDataAsset>(StaticLoadObject(UStaticDataAsset::StaticClass(), NULL, *bpResource));
	if (!GeneratedBP) {
		UE_LOG(LogTemp, Warning, TEXT("no BP"));
		return 0;

	}
	data = GeneratedBP;

	if (data) {
		data->getTotalFromWorld(GetWorld());
		setTotalPieces(data->TotalPieces);
	}

	

	return data->TotalPieces;

	
}

void Uui::setTotalPieces(int totalPieceee)
{
	totalPieces->SetText(FText::AsNumber(totalPieceee));
}

void Uui::SetMoonlitDew(int numberMoonlitDew)
{
	AmountMoonlitDew->SetText(FText::AsNumber(numberMoonlitDew));
}
