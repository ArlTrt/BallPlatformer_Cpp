// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Beam.generated.h"

class AConnector;

UCLASS(Blueprintable)
class BALLPLATFORMER_CPP_API ABeam : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABeam();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connectors")
	class AConnector* Connector1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Connectors")
	class AConnector* Connector2;

	UPROPERTY(EditAnywhere, Category = "Physics")
	float SpringStiffness = 100000.0f;

	UPROPERTY(EditAnywhere, Category = "Physics")
	float DampingFactor = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Physics")
	float BeamMass = 100.0f;

	UPROPERTY(VisibleAnywhere, Category = "Physics")
	FVector RestingPosition;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* BeamMesh;

	UFUNCTION(BlueprintCallable, Category = "Physics")
	void ApplySpringForces();

	UFUNCTION(BlueprintCallable, Category = "Debug")
	void DebugConnectors() const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
