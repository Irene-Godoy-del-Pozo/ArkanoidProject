// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Vaus_Controller.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_IRENE_API AVaus_Controller : public APlayerController
{
	GENERATED_BODY()

public :
		AVaus_Controller() {};

private:
	UFUNCTION()
		virtual void SetupInputComponent() override;

protected:

	virtual void BeginPlay() override;

	void MoveRight(float Val);
};
