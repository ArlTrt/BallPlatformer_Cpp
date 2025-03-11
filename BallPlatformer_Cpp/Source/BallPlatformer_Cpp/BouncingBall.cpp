// Fill out your copyright notice in the Description page of Project Settings.


#include "BouncingBall.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABouncingBall::ABouncingBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BouncingBallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BouncingBallMesh"));
	RootComponent = BouncingBallMesh;

	BouncingBallMesh->SetSimulatePhysics(true);
	BouncingBallMesh->SetEnableGravity(true);

	BouncingBallMesh->SetCollisionResponseToAllChannels(ECR_Block);
	BouncingBallMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BouncingBallMesh->SetCollisionProfileName(TEXT("PhysicsActor"));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = BouncingBallMesh;
	ProjectileMovement->InitialSpeed = 2000.f;
	ProjectileMovement->MaxSpeed = 5000.f;
	ProjectileMovement->bShouldBounce = true;

	ProjectileMovement->Bounciness = 1.0f;
	ProjectileMovement->Friction = 0.1f;

	ProjectileMovement->Velocity = FVector(0.f, 0.f, 500.f);

}

// Called when the game starts or when spawned
void ABouncingBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABouncingBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

