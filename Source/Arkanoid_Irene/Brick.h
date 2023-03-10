// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"

class UBoxComponent;

UCLASS()
class ARKANOID_IRENE_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();
	~ABrick() = default;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp	, class AActor* OtherActor,
							class UPrimitiveComponent* OtherComp		, int32 OtherBodyIndexType, 
							bool bFromSweep								,const FHitResult& SweepResult);

	void DestroyBrick();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* BrickMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* Box_Collision;

	UPROPERTY(EditAnywhere)
	float bounceSpeed = 1.7f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
