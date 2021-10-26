// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MouseClick", IE_Pressed, this, &AMainPlayerController::DetermineClickLogic);
}

AMainPlayerController::AMainPlayerController()
{
	bIsSelectMode = true;
}

void AMainPlayerController::DetermineClickLogic()
{
	if(bIsSelectMode) GetClickedActor();
	else PlaceActor();
}

void AMainPlayerController::GetClickedActor()
{
	FHitResult hitResult;
	auto success = GetHitResultUnderCursor(ECC_Visibility, true, hitResult);
	if(success)
	{
		auto furniture = Cast<AFurniture>(hitResult.Actor);
		if(furniture)
		{
			if(SelectedFurniture) SelectedFurniture->Outline->SetVisibility(false);
			SelectedFurniture = furniture;
			SelectedFurniture->Outline->SetVisibility(true);
		}
	}
}

void AMainPlayerController::PlaceActor()
{
	FHitResult hitResult;
	auto success = GetHitResultUnderCursor(ECC_Visibility, true, hitResult);
	if(success) PlaceFurnitureAtClickLocation(hitResult.Location);
}