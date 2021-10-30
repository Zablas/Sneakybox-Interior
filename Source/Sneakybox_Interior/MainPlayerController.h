// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Furniture.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

UENUM()
enum class EMode : uint8
{
	SELECT UMETA(DisplayName = "SELECT"),
	PLACE UMETA(DisplayName = "PLACE"),
	COLOR UMETA(DisplayName = "COLOR"),
	MOVE UMETA(DisplayName = "MOVE")
};

UCLASS()
class SNEAKYBOX_INTERIOR_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Design")
	AFurniture* SelectedFurniture;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Logic")
	EMode Mode;
	
	virtual void SetupInputComponent() override;

	AMainPlayerController();
	
	UFUNCTION(BlueprintImplementableEvent)
	void PlaceFurnitureAtClickLocation(const FVector& Location);

	UFUNCTION(BlueprintImplementableEvent)
	void CloseColorWheel();
	
	void DetermineClickLogic();
	void DetermineReleaseLogic();
	void GetClickedActor();
	void PlaceActor();
};
