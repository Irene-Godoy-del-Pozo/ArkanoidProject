// Fill out your copyright notice in the Description page of Project Settings.


#include "Vaus_Controller.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "Vaus.h"

void AVaus_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);

	//Bind the Axis on the input window to the method to Move
	InputComponent->BindAxis("MoveRight", this, &AVaus_Controller::MoveRight);
}

void AVaus_Controller::BeginPlay()
{
	//Get ALL Camera actors of the scene. In this case it will be only one 
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	//Bind the camerato the actor
	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

}

void AVaus_Controller::MoveRight(float Val)
{
	auto auxPawn = Cast<AVaus>(GetPawn());

	if (auxPawn)
		auxPawn->MoveRight(Val);


}
