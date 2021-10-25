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
	
	virtual void SetupInputComponent() override;
	
	void GetClickedActor();
};
