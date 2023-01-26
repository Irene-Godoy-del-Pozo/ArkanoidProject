// Fill out your copyright notice in the Description page of Project Settings.


#include "Vaus.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "DrawDebugHelpers.h"

#include "HealthComponent.h"
#include "Bullet.h"
#include "Arkanoid_IreneGameModeBase.h"

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
	healthComponent->SetMaxHealth(3);

	/*is_dead = false;*/

	/*maxBricks = 18;

	bricksBroken = 0;*/
}

// Called when the game starts or when spawned
void AVaus::BeginPlay()
{
	Super::BeginPlay();
	
}

//bool AVaus::IsDead()
//{
//	
//	return is_dead;
//}

//void AVaus::BrickDestroyed()
//{
//	bricksBroken++;
//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("Brick destroy")));
//	if (bricksBroken >= maxBricks)
//	{
//		OnVausDead.Broadcast();
//	}
//}


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

void AVaus::BulletMissed()
{
	healthComponent->TakeDamage();

	if (healthComponent->IsDead())
	{
		//TODO: Call GameMode function
		AArkanoid_IreneGameModeBase* mymode = Cast<AArkanoid_IreneGameModeBase>(GetWorld()->GetAuthGameMode());
		mymode->FinishGame();

		/*is_dead = true;*/

		/*OnVausDead.Broadcast();*/

	}
}

float AVaus::GetHealth()
{
	return healthComponent->GetHealth();
}

void AVaus::MoveRight(float Val)
{
	AddMovementInput(FVector(1.f, 0.f, 0.f), Val , false);

}
//int AVaus::GetBricks()
//{
//	return bricksBroken;
//}
//
//int AVaus::GetMaxBricks()
//{
//	return maxBricks;
//}



