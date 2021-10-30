// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MouseClick", IE_Pressed, this, &AMainPlayerController::DetermineClickLogic);
	InputComponent->BindAction("MouseClick", IE_Released, this, &AMainPlayerController::DetermineReleaseLogic);
}

AMainPlayerController::AMainPlayerController()
{
	Mode = EMode::SELECT;
}

void AMainPlayerController::DetermineClickLogic()
{
	switch (Mode)
	{
	case EMode::SELECT:
		GetClickedActor();
		break;
	case EMode::PLACE:
		PlaceActor();
		break;
	case EMode::MOVE:
		MoveActor();
		break;
	default:
		break;
	}
}

void AMainPlayerController::DetermineReleaseLogic()
{
	switch (Mode)
	{
	case EMode::COLOR:
		CloseColorWheel();
		break;
	case EMode::MOVE:
		StopMovingActor();
		break;
	default:
		break;
	}
}

void AMainPlayerController::GetClickedActor()
{
	FHitResult hitResult;
	auto success = GetHitResultUnderCursor(ECC_Visibility, true, hitResult);
	if(success)
	{
		auto furniture = Cast<AFurniture>(hitResult.Actor);
		if(furniture) ToggleActorOutline(furniture);
	}
}

void AMainPlayerController::PlaceActor()
{
	FHitResult hitResult;
	auto success = GetHitResultUnderCursor(ECC_Visibility, true, hitResult);
	if(success) PlaceFurnitureAtClickLocation(hitResult.Location);
}

void AMainPlayerController::MoveActor()
{
	FHitResult hitResult;
	auto success = GetHitResultUnderCursor(ECC_Visibility, true, hitResult);
	if(success)
	{
		auto furniture = Cast<AFurniture>(hitResult.Actor);
		if(furniture) ToggleActorOutline(furniture);
	}
}

void AMainPlayerController::StopMovingActor()
{
	if(SelectedFurniture)
	{
		SelectedFurniture->Outline->SetVisibility(false);
		SelectedFurniture = nullptr;
	}
}

void AMainPlayerController::ToggleActorOutline(AFurniture* furniture)
{
	if(SelectedFurniture) SelectedFurniture->Outline->SetVisibility(false);
	SelectedFurniture = furniture;
	SelectedFurniture->Outline->SetVisibility(true);
}
