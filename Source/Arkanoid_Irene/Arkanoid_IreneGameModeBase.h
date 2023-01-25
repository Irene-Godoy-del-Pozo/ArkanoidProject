// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Arkanoid_IreneGameModeBase.generated.h"

/**
 * 
 */



UCLASS()
class ARKANOID_IRENE_API AArkanoid_IreneGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

public:

	AArkanoid_IreneGameModeBase();
	virtual ~AArkanoid_IreneGameModeBase() = default;

	UFUNCTION()
		void BrickDestroyed();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 maxBricks = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int32 maxScore;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool isVictory = false;

private:

	bool CheckVictory();
};
