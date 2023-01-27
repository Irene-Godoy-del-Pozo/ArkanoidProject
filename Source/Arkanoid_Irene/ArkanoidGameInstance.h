// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ArkanoidGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_IRENE_API UArkanoidGameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:

	UArkanoidGameInstance();
	~UArkanoidGameInstance() = default;

	UFUNCTION(BlueprintCallable)
		int32& GetmaxScore();

	UFUNCTION(BlueprintCallable)
		int32& GetmaxStreak();

	UFUNCTION(BlueprintCallable)
		int32& GetgamesPlayed();

	void GameFinished(int32 _maxScore, int32 _maxStreak);

private:

	int32 maxScore;

	int32 maxStreak;

	int32 gamesPlayed;

};
