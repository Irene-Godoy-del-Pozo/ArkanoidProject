// Fill out your copyright notice in the Description page of Project Settings.


#include "Vaus.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AVaus::AVaus()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set this pawn to be controlled by the lowest-numbered player|||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	AutoPossessPlayer = EAutoReceiveInput::Player0;




	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));

	RootComponent = PawnMesh;

	//Set gravity to false and fix it to the XY axis
	PawnMesh->SetConstraintMode(EDOFMode::XYPlane);
	PawnMesh->SetEnableGravity(false);

	PawnMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	PawnMesh->SetCollisionProfileName(TEXT("PhysicsActor"));//||||||||||||||||||||||||||||||||||||
	


}

// Called when the game starts or when spawned
void AVaus::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVaus::MoveRight(float Val)
{
	AddMovementInput(FVector(0.f, -1.f, 0.f), Val, false);
}

// Called every frame
void AVaus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVaus::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

