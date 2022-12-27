// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Vaus.generated.h"

class UFloatingPawnMovement;

UCLASS()
class ARKANOID_IRENE_API AVaus : public APawn
{
	GENERATED_BODY()



public:
	// Sets default values for this pawn's properties
	AVaus();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UFloatingPawnMovement* FloatPMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* PawnMesh;


public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void MoveRight(float Val);

	UFUNCTION()
	UStaticMeshComponent* GetMesh();

};
