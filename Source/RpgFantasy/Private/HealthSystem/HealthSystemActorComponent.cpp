// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthSystemActorComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UHealthSystemActorComponent::UHealthSystemActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	InitialHealth = 50.f;
	CurrentHealth = 20.f;
	MaxHealth = 100.f;
}


float UHealthSystemActorComponent::GetInitialHealth()
{
	return InitialHealth;
}

float UHealthSystemActorComponent::GetCurrentHealth()
{
	return CurrentHealth;
}

float UHealthSystemActorComponent::GetMaxHealth()
{
	return MaxHealth;
}

void UHealthSystemActorComponent::HealthUpdate(float Health)
{
	CurrentHealth = CurrentHealth + Health;
}

// Called when the game starts
void UHealthSystemActorComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();

	if (Owner != nullptr)
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthSystemActorComponent::TakeDamage);
	}
	
}


void UHealthSystemActorComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0)
	{
		return;
	}

	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);
}

// Called every frame
void UHealthSystemActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	HealthUpdate(DeltaTime * 0.02f * (InitialHealth));
}

