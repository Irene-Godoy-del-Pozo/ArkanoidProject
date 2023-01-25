// Copyright Epic Games, Inc. All Rights Reserved.


#include "Arkanoid_IreneGameModeBase.h"
#include "ArkanoidGameStateBase.h"
#include "Vaus.h"
#include "Vaus_Controller.h"

AArkanoid_IreneGameModeBase::AArkanoid_IreneGameModeBase()
{

	GameStateClass = AArkanoidGameStateBase::StaticClass();
	DefaultPawnClass = AVaus::StaticClass();
	PlayerControllerClass = AVaus_Controller::StaticClass();


}


void AArkanoid_IreneGameModeBase::BrickDestroyed()
{
	//Add brick destroyed to de count and score
	GetGameState< AArkanoidGameStateBase >()->BrickDestroyed();

	if (CheckVictory() == true)
	{
		//Cambia el widget etc
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, TEXT("Victory!!!"));

		isVictory = true;
	}
}

bool AArkanoid_IreneGameModeBase::CheckVictory()
{
	return GetGameState< AArkanoidGameStateBase >()->GetBricksDestroyed() >= maxBricks;
}