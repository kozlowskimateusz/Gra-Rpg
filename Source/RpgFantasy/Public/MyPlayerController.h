// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RPGFANTASY_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Toggle Widget")
		void ToggleWidget(TSubclassOf<UUserWidget>* NewWidgetClass);

protected:

	AMyPlayerController();

	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UUserWidget>* PlayerHud;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UUserWidget>* PlayerHud;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UUserWidget>* PlayerHud;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UUserWidget>* PlayerHud;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UUserWidget>* PlayerHud;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UUserWidget>* PlayerHud;

	UPROPERTY()
	UUserWidget* CurrentWidget;

	bool bShowCurrentWidget = false;

	void ToggleMainMenuWidget();

	void ToggleEquipmentWidget();

	void ToggleSkillsWidget();

	void ToggleMapWidget();

	void ToggleQuestsWidget();
};
