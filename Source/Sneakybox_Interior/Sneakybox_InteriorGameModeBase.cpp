// Copyright Epic Games, Inc. All Rights Reserved.


#include "Sneakybox_InteriorGameModeBase.h"

void ASneakybox_InteriorGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	auto controller = GetWorld()->GetFirstPlayerController();
	if(controller)
	{
		FInputModeGameAndUI inputMode;
		inputMode.SetHideCursorDuringCapture(false);
		inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockInFullscreen);
		controller->SetInputMode(inputMode);
		
		controller->SetShowMouseCursor(true);
		controller->SetIgnoreMoveInput(true);
		controller->SetIgnoreLookInput(true);
	}
}
