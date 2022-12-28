// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"
//#include "GameFramework/PlayerController.h"

class AVaus;
class UProjectileMovementComponent;

UCLASS()
class ARKANOID_IRENE_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	virtual void Shoot();


	bool is_Shot;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* BulletMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UProjectileMovementComponent* ProjectileMovement;

	
		AVaus* SceneVaus;////

		FVector direction = FVector(1.f,1.f, 1.f);///

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
		UStaticMeshComponent* GetBullet();

		void SetPawn(AVaus& _Vaus);


		/*void StopBullet();*/
	
		
};
