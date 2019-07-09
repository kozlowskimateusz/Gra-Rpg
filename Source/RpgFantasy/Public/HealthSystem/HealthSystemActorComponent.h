// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthSystemActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGFANTASY_API UHealthSystemActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthSystemActorComponent();

	UFUNCTION(BlueprintPure, Category = "Health System")
	float GetInitialHealth();

	UFUNCTION(BlueprintPure, Category = "Health System")
	float GetCurrentHealth();

	UFUNCTION(BlueprintPure, Category = "Health System")
	float GetMaxHealth();

	UFUNCTION(BlueprintCallable, Category = "Health System")
	void HealthUpdate(float Health);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health System")
	float InitialHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health System")
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health System")
	float MaxHealth;

	UFUNCTION()
	void TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
