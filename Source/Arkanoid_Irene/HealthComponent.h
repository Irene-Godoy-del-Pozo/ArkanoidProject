// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARKANOID_IRENE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	~UHealthComponent()=default;

	UFUNCTION(BlueprintPure)
		float GetHealth();

	void SetMaxHealth(float health);

	void TakeDamage();

	bool IsDead();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,Category = "Health")
		float maxHealth;

	UPROPERTY(VisibleAnywhere, Category = "Health")
		float currentHealth;
		
	
	
};
