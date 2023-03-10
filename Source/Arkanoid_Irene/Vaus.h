// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Delegates/Delegate.h"
#include "Vaus.generated.h"

class UFloatingPawnMovement;
class UHealthComponent;


//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVausIsDead);


UCLASS()
class ARKANOID_IRENE_API AVaus : public APawn
{
	GENERATED_BODY()


public:
	// Sets default values for this pawn's properties
	AVaus();
	~AVaus() = default;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void BulletMissed();

	//Used for GameHUD widget to show player health
	UFUNCTION(BlueprintPure)
	float GetHealth();

	/*UFUNCTION(BlueprintPure)
		int GetBricks();

	UFUNCTION(BlueprintPure)
		int GetMaxBricks();*/

	/*UFUNCTION()
		bool IsDead();*/

	//UFUNCTION()
	//	void BrickDestroyed();

	//UPROPERTY()
	//	FVausIsDead OnVausDead;


	void MoveRight(float Val);

	UFUNCTION()
		UStaticMeshComponent* GetMesh();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//bool is_dead;
	//UPROPERTY(VisibleAnywhere)
	//int bricksBroken;
	//UPROPERTY(VisibleAnywhere)
	//int maxBricks;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UFloatingPawnMovement* FloatPMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* PawnMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UHealthComponent* healthComponent;

};
