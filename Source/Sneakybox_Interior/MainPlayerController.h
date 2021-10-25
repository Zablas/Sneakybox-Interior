// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Furniture.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SNEAKYBOX_INTERIOR_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Design")
	AFurniture* SelectedFurniture;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Logic")
	bool bIsSelectMode;
	
	virtual void SetupInputComponent() override;

	AMainPlayerController();
	void DetermineClickLogic();
	void GetClickedActor();
	void PlaceActor();
};
