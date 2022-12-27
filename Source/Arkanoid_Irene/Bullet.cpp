// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/EngineTypes.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));

	RootComponent = BulletMesh;

	//------------Mesh Configuration----------------------------
	 
	//Define the movement limits of the bullet(No gravity no Y axis)
	BulletMesh->SetConstraintMode(EDOFMode::XZPlane);
	BulletMesh->SetEnableGravity(false);

	//Configure the collision detection
	BulletMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BulletMesh->SetCollisionProfileName(TEXT("PhysicsActor"));

	//Activate Physics
	BulletMesh->SetSimulatePhysics(true);

	//-----------Projectile Movement Variables----------------------------------------

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));

	//Bounce settings
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.1f;

	//Movement settings
	ProjectileMovement->Friction = 0.0f;
	ProjectileMovement->Velocity.Y = 0.0f;

	/*Respawn(0, 0, 0);*/
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UStaticMeshComponent* ABullet::GetBullet()
{
	return BulletMesh;
}

void ABullet::Shoot()
{
	//Prevents to shoot the ball when its alredy shot
	if (is_Shot == false)
	{
		BulletMesh->AddImpulse(FVector(140.0f, 0.0f, 130.0f), FName(), true);

		is_Shot = true;
	}

}

void ABullet::Respawn(float x, float y, float z)
{
	SetActorLocation(FVector(x, y, z));
	
}

