// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MouseClick", IE_Pressed, this, &AMainPlayerController::DetermineClickLogic);
	InputComponent->BindAction("MouseClick", IE_Released, this, &AMainPlayerController::DetermineReleaseLogic);
}

void AMainPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(Mode == EMode::MOVE && GrabbedComponent)
	{
		FVector WorldLocation;
		FVector WorldDirection;
		DeprojectMousePositionToWorld(WorldLocation, WorldDirection);
		WorldDirection *= DistanceToComponent;
		MoveActor(WorldLocation, WorldDirection);
	}
}

AMainPlayerController::AMainPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
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
		CalculateActorMovementProperties();
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
		else if(SelectedFurniture)
		{
			SelectedFurniture->Outline->SetVisibility(false);
			SelectedFurniture = nullptr;
		}
	}
}

void AMainPlayerController::PlaceActor()
{
	FHitResult hitResult;
	auto success = GetHitResultUnderCursor(ECC_Visibility, true, hitResult);
	if(success) PlaceFurnitureAtClickLocation(hitResult.Location);
}

void AMainPlayerController::CalculateActorMovementProperties()
{
	FHitResult hitResult;
	auto success = GetHitResultUnderCursor(ECC_Visibility, true, hitResult);
	if(success)
	{
		auto furniture = Cast<AFurniture>(hitResult.Actor);
		if(furniture)
		{
			auto component = hitResult.Component;
			if(component->Mobility == EComponentMobility::Movable)
			{
				GrabbedComponent = component.Get();
				DistanceToComponent = hitResult.Distance;
				SetGrabbedLocation(hitResult.Location);
			}
			ToggleActorOutline(furniture);
		}
	}
}

void AMainPlayerController::StopMovingActor()
{
	if(SelectedFurniture)
	{
		SelectedFurniture->Outline->SetVisibility(false);
		SelectedFurniture = nullptr;
		GrabbedComponent = nullptr;
	}
}

void AMainPlayerController::ToggleActorOutline(AFurniture* furniture)
{
	if(SelectedFurniture) SelectedFurniture->Outline->SetVisibility(false);
	SelectedFurniture = furniture;
	SelectedFurniture->Outline->SetVisibility(true);
}
