// Fill out your copyright notice in the Description page of Project Settings.


#include "Bumper.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABumper::ABumper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BumperMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BumperMesh"));
	RootComponent = BumperMesh;

	BumperMesh->SetSimulatePhysics(false);
	BumperMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BumperMesh->SetNotifyRigidBodyCollision(true);
}

// Called when the game starts or when spawned
void ABumper::BeginPlay()
{
	Super::BeginPlay();

}

void ABumper::NotifyHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "NotifyHit detected");

	if (OtherActor && OtherActor != this)
	{
		UPrimitiveComponent* OtherComponent = OtherActor->FindComponentByClass<UPrimitiveComponent>();
		if (OtherComponent && OtherComponent->IsSimulatingPhysics())
		{
			FString ActorName = OtherActor->GetName();
			//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::Printf(TEXT("Overlap with: %s"), *ActorName));

			FVector BounceDirection = (HitLocation - GetActorLocation()).GetSafeNormal();
			OtherComponent->AddImpulse(BounceDirection * BounceStrength, NAME_None, true);
		}
	}
}

// Called every frame
void ABumper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
