// Copyright Epic Games, Inc. All Rights Reserved.


#include "Sneakybox_InteriorGameModeBase.h"

void ASneakybox_InteriorGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	auto controller = GetWorld()->GetFirstPlayerController();
	if(controller)
	{
		controller->SetInputMode(FInputModeGameAndUI());
		controller->SetShowMouseCursor(true);
	}
}
