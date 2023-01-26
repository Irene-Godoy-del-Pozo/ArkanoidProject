// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	maxHealth = 0;
	currentHealth = maxHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


void UHealthComponent::TakeDamage()
{
	currentHealth = FMath::Clamp(currentHealth - 1, 0.f , maxHealth);
}

float UHealthComponent::GetHealth()
{
	return currentHealth;
}

void UHealthComponent::SetMaxHealth(float health)
{
	maxHealth = health;
	currentHealth = maxHealth;
}

bool UHealthComponent::IsDead()
{
	return currentHealth <=0;
}

