// Fill out your copyright notice in the Description page of Project Settings.


#include "ArkanoidGameStateBase.h"

AArkanoidGameStateBase::AArkanoidGameStateBase()
{
	currentBricksDestroyed = 0;
	currentScore = 0;
	maxScore = 0;
}

int32 AArkanoidGameStateBase::GetBricksDestroyed()
{
	return currentBricksDestroyed;
}

void AArkanoidGameStateBase::BrickDestroyed()
{
	currentBricksDestroyed++;

	currentScore += 10; 

}