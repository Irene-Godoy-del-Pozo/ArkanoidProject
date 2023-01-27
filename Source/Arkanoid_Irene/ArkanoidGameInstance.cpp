// Fill out your copyright notice in the Description page of Project Settings.


#include "ArkanoidGameInstance.h"

UArkanoidGameInstance::UArkanoidGameInstance()
{
	//TODO: Init variables from save 

	maxScore = 0;

	maxStreak = 0;

	gamesPlayed = 0;
}



int32& UArkanoidGameInstance::GetmaxScore()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, TEXT("maxScore Getter accesed"));
	return maxScore;
}

int32& UArkanoidGameInstance::GetmaxStreak()
{
	return maxStreak;
}

int32& UArkanoidGameInstance::GetgamesPlayed()
{
	return gamesPlayed;
}


void UArkanoidGameInstance::GameFinished(int32 _maxScore, int32 _maxStreak)
{
	if (_maxScore > maxScore) maxScore = _maxScore;

	if (_maxStreak > maxStreak) maxStreak = _maxStreak;

	gamesPlayed++;

}