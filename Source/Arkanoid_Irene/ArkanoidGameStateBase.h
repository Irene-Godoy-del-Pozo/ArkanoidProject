// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ArkanoidGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_IRENE_API AArkanoidGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	AArkanoidGameStateBase();
	virtual ~AArkanoidGameStateBase() = default;


	UFUNCTION()
		int32 GetBricksDestroyed();

	UFUNCTION()
		void BrickDestroyed();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int32 currentBricksDestroyed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int32 currentScore;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int32 maxScore;
private:
};
