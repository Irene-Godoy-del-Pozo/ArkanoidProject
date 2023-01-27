// Copyright Epic Games, Inc. All Rights Reserved.


#include "Arkanoid_IreneGameModeBase.h"
#include "ArkanoidGameStateBase.h"
#include "Vaus.h"
#include "Vaus_Controller.h"
#include "ArkanoidGameInstance.h"

AArkanoid_IreneGameModeBase::AArkanoid_IreneGameModeBase()
{

	GameStateClass = AArkanoidGameStateBase::StaticClass();
	DefaultPawnClass = AVaus::StaticClass();
	PlayerControllerClass = AVaus_Controller::StaticClass();

	isVictory = false;

	bPauseable = false;
}

void AArkanoid_IreneGameModeBase::InitializeGame()
{
	UArkanoidGameInstance* mymode = Cast<UArkanoidGameInstance>(GetGameInstance());

	if (mymode != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, TEXT("Game Instance exists"));
		maxScore = mymode->GetmaxScore();
	}
	bPauseable = true;
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

	

		//StopGame();
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &AArkanoid_IreneGameModeBase::FinishGame,.1f, false);

		//FinishGame();
	}
}

bool AArkanoid_IreneGameModeBase::CheckVictory()
{
	return GetGameState< AArkanoidGameStateBase >()->GetBricksDestroyed() >= maxBricks;
}

AVaus_Controller* AArkanoid_IreneGameModeBase::GetController()
{
	AVaus_Controller* vausController = Cast<AVaus_Controller>(GEngine->GetFirstLocalPlayerController(GetWorld()));

	return vausController;
}

void AArkanoid_IreneGameModeBase::FinishGame()
{
	AVaus_Controller* vausController = GetController();

	if (vausController != NULL)
	{
		vausController->Pause();
		vausController->UnBindPauseAction();
	}
	//Update max score
	int32 finalScore = GetGameState< AArkanoidGameStateBase >()->currentScore;
	if (finalScore > maxScore)
		maxScore = finalScore;

	//TODO : Save maxScore
	UArkanoidGameInstance* mymode = Cast<UArkanoidGameInstance>(GetGameInstance());

	if (mymode != NULL)
	{
		mymode->GameFinished(maxScore,1);
	}
}

void AArkanoid_IreneGameModeBase::PauseGame(bool isPaused)
{
	AVaus_Controller* vausController = GetController();

	if (vausController != NULL)
	{
		vausController->SetPause(!isPaused);
		
	}
}
