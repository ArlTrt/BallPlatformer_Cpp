// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FVector NextLocation = CurrentLocation + (MoveDirection * MoveSpeed * DeltaTime);

	float TraveledDistance = FVector::Dist(StartLocation, NextLocation);

	if (TraveledDistance > MoveDistance)
	{
		MoveDirection *= -1; // Invert direction
		StartLocation = NextLocation; // Reload startpoint
	}

	SetActorLocation(NextLocation);
}

