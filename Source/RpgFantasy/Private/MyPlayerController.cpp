// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Engine.h"


AMyPlayerController::AMyPlayerController()
{
	bShowCurrentWidget = false;
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (PlayerHud != nullptr)
	{
		ToggleWidget(PlayerHud, false, false, true);
	}
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Main Menu widget
	InputComponent->BindAction("MainMenu", IE_Pressed, this, &AMyPlayerController::ToggleMainMenuWidget);

	// Equipment
	InputComponent->BindAction("Equipment", IE_Pressed, this, &AMyPlayerController::ToggleEquipmentWidget);

	//Skills
	InputComponent->BindAction("Skills", IE_Pressed, this, &AMyPlayerController::ToggleSkillsWidget);

	//Quests
	InputComponent->BindAction("Quests", IE_Pressed, this, &AMyPlayerController::ToggleQuestsWidget);
}

void AMyPlayerController::ToggleWidget(TSubclassOf<UUserWidget> NewWidgetClass, bool bShowMouse, bool bSetPause, bool BInputModeGameOnly)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromParent();
		CurrentWidget = nullptr;
	}
	if (NewWidgetClass)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);

		if (bShowCurrentWidget == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, FString("Add Widget"));
			CurrentWidget->AddToViewport();
			if (BInputModeGameOnly == true)
			{
				SetInputMode(FInputModeGameOnly());
			}
			else
			{
				SetInputMode(FInputModeGameAndUI());
			}
			bShowMouseCursor = bShowMouse;
			SetPause(bSetPause);
			bShowCurrentWidget = true;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, FString("remove Widget"));
			CurrentWidget->RemoveFromParent();
			SetInputMode(FInputModeGameOnly());
			bShowMouseCursor = false;
			SetPause(false);
			bShowCurrentWidget = false;
		}
	}
}

void AMyPlayerController::ToggleMainMenuWidget()
{
	if (MainMenuWidget != nullptr)
	{
		ToggleWidget(MainMenuWidget, true, true, false);
	}
}
void AMyPlayerController::ToggleEquipmentWidget()
{
	if (EquipmentWidget != nullptr)
	{
		ToggleWidget(EquipmentWidget, true, true, false);
	}
}
void AMyPlayerController::ToggleSkillsWidget()
{
	if (SkillsWidget != nullptr)
	{
		ToggleWidget(SkillsWidget, true, true, false);
	}
}
void AMyPlayerController::ToggleQuestsWidget()
{
	if (QuestsWidget != nullptr)
	{
		ToggleWidget(QuestsWidget, true, true, false);
	}
}