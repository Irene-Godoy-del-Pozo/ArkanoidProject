// Fill out your copyright notice in the Description page of Project Settings.


#include "Vaus_Controller.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "Vaus.h"
#include "Bullet.h"
#include "Arkanoid_IreneGameModeBase.h"


void AVaus_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);

	//Bind the Axis on the input window to the method to Move
	InputComponent->BindAxis("MoveRight", this, &AVaus_Controller::MoveRight);
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AVaus_Controller::ShootBullet);
	toggle = &InputComponent->BindAction("Pause", IE_Pressed, this, &AVaus_Controller::PauseGame);
	toggle->bExecuteWhenPaused = true;
}



void AVaus_Controller::BeginPlay()
{
	//Get ALL Camera actors of the scene. In this case it will be only one 
	TArray<AActor*> cameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), cameraActors);

	//Bind the camerato the actor
	FViewTargetTransitionParams params;
	SetViewTarget(cameraActors[0], params);

	myVaus = Cast<AVaus>( GetPawn());

	//isPaused = false;
	////Suscribe to delegate of Vaus
	//myVaus->OnVausDead.AddDynamic(this, &AVaus_Controller::StopVaus);
	

	SpawnNewBullet();

	
}

void AVaus_Controller::MoveRight(float Val)
{	
	if (myVaus)
		myVaus->MoveRight(Val);
}

void AVaus_Controller::SpawnNewBullet()
{
	/*if (!myBullet)
		myBullet = nullptr;*/

	if (myBullet == NULL)
	{
		if (bulletObj)
			myBullet = GetWorld()->SpawnActor<ABullet>(bulletObj, SpawnLocation, SpawnRotation, spawnInfo);

		myBullet->SetPawn(*myVaus);
	}
	else
	{
		/*myBullet->is_Shot = false;
		myBullet->same++;
		myBullet->GetBullet()->SetPhysicsLinearVelocity(FVector(0, 0, 0), true);*/

		myBullet->Reset();
	}


	////Suscribe to delegate of Brick
	//myBullet->OnBrickDestroy.AddDynamic(this, &AVaus_Controller::BreakBrik);
}


void AVaus_Controller::ShootBullet()
{
	myBullet->Shoot();
}

AVaus* AVaus_Controller::GetMyVaus()
{
	return myVaus;
}

//TODO:make a pause input
void AVaus_Controller::PauseGame()
{
	AArkanoid_IreneGameModeBase* mymode = Cast<AArkanoid_IreneGameModeBase>(GetWorld()->GetAuthGameMode());
	mymode->PauseGame(IsPaused());
	
	//Unpause();
}

void AVaus_Controller::UnBindPauseAction()
{
	InputComponent->RemoveActionBinding("Pause", IE_Pressed);

}

//void AVaus_Controller::BreakBrik()
//{
//	myVaus->BrickDestroyed();
//
//}
