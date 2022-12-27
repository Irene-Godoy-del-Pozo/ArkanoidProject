// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Vaus_Controller.generated.h"


class ABullet;
class AVaus;

UCLASS()
class ARKANOID_IRENE_API AVaus_Controller : public APlayerController
{
	GENERATED_BODY()

public :
		AVaus_Controller() {};

		void SpawnNewBullet();
private:
	UFUNCTION()
		virtual void SetupInputComponent() override;

	


protected:

	virtual void BeginPlay() override;

	void MoveRight(float Val);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		AVaus* MyVaus;

	void ShootBullet();

	//References the bluprint of bullet. TSubclassof references the TYPE of data. It permit to Create new objects of the class
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABullet> BulletObj;

	ABullet* MyBullet;

	FVector SpawnLocation = FVector(10.0f, 0.0f, 40.0f);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
};
