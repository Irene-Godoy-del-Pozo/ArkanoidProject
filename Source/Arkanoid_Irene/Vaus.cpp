// Fill out your copyright notice in the Description page of Project Settings.


#include "Vaus.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

#include "HealthComponent.h"

// Sets default values
AVaus::AVaus()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));

	RootComponent = PawnMesh;

	//Set gravity to false and fix it to the XY axis
	PawnMesh->SetConstraintMode(EDOFMode::XZPlane);
	PawnMesh->SetEnableGravity(false);

	PawnMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	PawnMesh->SetCollisionProfileName(TEXT("PhysicsActor"));//||||||||||||||||||||||||||||||||||||
	
	FloatPMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));

	//-------------Health----------

	healthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));


}

// Called when the game starts or when spawned
void AVaus::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVaus::MoveRight(float Val)
{
	AddMovementInput(FVector(1.f, 0.f, 0.f), Val , false);

}

UStaticMeshComponent* AVaus::GetMesh()
{
	return PawnMesh;
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

void AVaus::TakeDamage()
{
	healthComponent->TakeDamage();

	if (healthComponent->GetHealth() <= 0)
	{
		//Death
	}
}
