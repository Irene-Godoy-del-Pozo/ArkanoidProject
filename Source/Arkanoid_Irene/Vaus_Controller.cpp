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
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	//Bind the camerato the actor
	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

	MyVaus = Cast<AVaus>( GetPawn());

	SpawnNewBullet();
}

void AVaus_Controller::MoveRight(float Val)
{
	

	if (MyVaus)
		MyVaus->MoveRight(Val);


}
void AVaus_Controller::SpawnNewBullet()
{
	if (!MyBullet)
		MyBullet = nullptr;

	if (BulletObj)
		MyBullet = GetWorld()->SpawnActor<ABullet>(BulletObj, SpawnLocation, SpawnRotation, SpawnInfo);

	MyBullet->SetPawn(*MyVaus);
}


void AVaus_Controller::ShootBullet()
{
	MyBullet->Shoot();
}
