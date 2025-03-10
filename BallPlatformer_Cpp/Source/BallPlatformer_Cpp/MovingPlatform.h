// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class BALLPLATFORMER_CPP_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector MoveDirection = FVector(1, 0, 0); // X axis by default

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveDistance = 500.0f;
};
