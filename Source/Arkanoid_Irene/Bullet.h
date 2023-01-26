// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"
//#include "GameFramework/PlayerController.h"

class AVaus;
class UProjectileMovementComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBrickDestroy);

UCLASS()
class ARKANOID_IRENE_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	void Shoot();

	UPROPERTY()
		FBrickDestroy OnBrickDestroy;
	
	bool is_Shot;
	UPROPERTY(VisibleAnywhere)
		int32 same = 0;

	void Reset();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* BulletMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UProjectileMovementComponent* ProjectileMovement;

	//Pointer to the Vaus posses for the vausController
	AVaus* SceneVaus;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		UStaticMeshComponent* GetBullet();

		void SetPawn(AVaus& _Vaus);

		
};
