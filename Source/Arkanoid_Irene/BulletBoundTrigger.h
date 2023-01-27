// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletBoundTrigger.generated.h"

class UBoxComponent;
class AVaus_Controller;

UCLASS()
class ARKANOID_IRENE_API ABulletBoundTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletBoundTrigger();
	~ABulletBoundTrigger() = default;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* Box_Collision;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
							class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, 
							bool bFromSweep, const FHitResult& SweepResult);



	AVaus_Controller* _vausController;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
