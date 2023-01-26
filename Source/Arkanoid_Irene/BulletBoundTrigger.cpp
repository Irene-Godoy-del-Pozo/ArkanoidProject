// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletBoundTrigger.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

#include "Vaus_Controller.h"
#include "Vaus.h"

// Sets default values
ABulletBoundTrigger::ABulletBoundTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	RootComponent = Box_Collision;

	Box_Collision->SetBoxExtent(FVector(380.0f, 10.0f, 50.0f));

	
}

// Called when the game starts or when spawned
void ABulletBoundTrigger::BeginPlay()
{
	Super::BeginPlay();

	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &ABulletBoundTrigger::OnOverlapBegin);

	_vausController = Cast<AVaus_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	
}

void ABulletBoundTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Bullet")) {

		//OtherActor->Destroy();

		_vausController->SpawnNewBullet();

		AVaus* aux = _vausController->GetMyVaus();

		aux->BulletMissed();

	}
}

// Called every frame
void ABulletBoundTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

