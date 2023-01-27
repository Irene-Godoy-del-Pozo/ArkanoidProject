// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "DrawDebugHelpers.h"

#include "Bullet.h"
#include "Arkanoid_IreneGameModeBase.h"


// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//---------------------Mesh-------------------------------------------
	BrickMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BrickMesh"));

	BrickMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);


	//---------------------Box Collision----------------------------------
	Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	Box_Collision->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));

	RootComponent = Box_Collision;
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	
	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);
}

void ABrick::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult)
{
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("Overlap event")));
	if (OtherActor->ActorHasTag("Bullet")) {

		//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString::Printf(TEXT("Is Bullet")));

		ABullet* MyBullet = Cast<ABullet>(OtherActor);

		FVector BulletVelocity = MyBullet->GetVelocity();
		BulletVelocity *= bounceSpeed ;

		MyBullet->GetBullet()->SetPhysicsLinearVelocity(BulletVelocity, false);
	
		AArkanoid_IreneGameModeBase* mymode = Cast<AArkanoid_IreneGameModeBase>(GetWorld()->GetAuthGameMode());
		mymode->BrickDestroyed();

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrick::DestroyBrick, 0.05f, false);

		//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString::Printf(TEXT("reach")));

		MyBullet->OnBrickDestroy.Broadcast();

	}
}

void ABrick::DestroyBrick()
{
	this->Destroy();
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

