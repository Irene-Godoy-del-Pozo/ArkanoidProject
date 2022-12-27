// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Vaus.h"

#include "GameFramework/Controller.h"
#include "DrawDebugHelpers.h"

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
	//ProjectileMovement->Velocity.X = 0.0f;

	
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

	//If its not shot , it follows thw Vaus
	if (is_Shot == false && SceneVaus)
	{
		SetActorLocation(SceneVaus->GetActorLocation() + FVector(0.f, 0.f, 10.f));

	}
	//If is shot throw a raycast to detect the Vause
	else
	{
		FHitResult OutHit;

		//Set The start and end vectors
		FVector Start = GetActorLocation() -FVector(0.f, 0.f, 4.f);
		FVector DownVector = -GetActorUpVector();
		FVector End = ((DownVector * 7.f) + Start);

		DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 0.5f, 0, 3);

		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);

		FCollisionObjectQueryParams ObjParams;
		ObjParams.AddObjectTypesToQuery(ECollisionChannel::ECC_PhysicsBody);


		bool is_hit = GetWorld()->LineTraceSingleByObjectType(OutHit, Start, End, ObjParams, CollisionParams);

		if (is_hit)//(ActorLineTraceSingle(OutHit, Start, End, ECC_WorldStatic, CollisionParams))
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.3f, FColor::Red, FString::Printf(TEXT("Dio")));
			GEngine->AddOnScreenDebugMessage(-1, 0.3f, FColor::Green, FString::Printf(TEXT("The Component Being Hit is: %s"), *OutHit.GetComponent()->GetName()));
		}


	}

}

UStaticMeshComponent* ABullet::GetBullet()
{
	return BulletMesh;
}

void ABullet::SetPawn(AVaus& _Vaus)
{
	SceneVaus = &_Vaus;
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



