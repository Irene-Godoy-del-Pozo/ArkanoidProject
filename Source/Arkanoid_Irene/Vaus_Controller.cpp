// Fill out your copyright notice in the Description page of Project Settings.


#include "Vaus_Controller.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "Vaus.h"
#include "Bullet.h"



void AVaus_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);

	//Bind the Axis on the input window to the method to Move
	InputComponent->BindAxis("MoveRight", this, &AVaus_Controller::MoveRight);
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AVaus_Controller::ShootBullet);
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

	//Suscribe to delegate of Vaus
	myVaus->OnVausDead.AddDynamic(this, &AVaus_Controller::StopVaus);
	

	SpawnNewBullet();

	
}

void AVaus_Controller::MoveRight(float Val)
{	
	if (myVaus)
		myVaus->MoveRight(Val);
}

void AVaus_Controller::SpawnNewBullet()
{
	if (!myBullet)
		myBullet = nullptr;

	if (bulletObj)
		myBullet = GetWorld()->SpawnActor<ABullet>(bulletObj, SpawnLocation, SpawnRotation, spawnInfo);

	myBullet->SetPawn(*myVaus);

	//Suscribe to delegate of Brick
	myBullet->OnBrickDestroy.AddDynamic(this, &AVaus_Controller::BreakBrik);
}


void AVaus_Controller::ShootBullet()
{
	myBullet->Shoot();
}

AVaus* AVaus_Controller::GetMyVaus()
{
	return myVaus;
}

void AVaus_Controller::StopVaus()
{
	Pause();
}

void AVaus_Controller::BreakBrik()
{
	myVaus->BrickDestroyed();

}
