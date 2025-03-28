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
	float SpringStiffness = 1000.0f;

	UPROPERTY(EditAnywhere, Category = "Physics")
	float DampingFactor = 50.0f;

	UPROPERTY(VisibleAnywhere, Category = "Physics")
	float RestLength;

	UPROPERTY(EditAnywhere, Category = "Physics")
	float MaxForceThreshold = 10000.0f;

	UPROPERTY(VisibleAnywhere, Category = "Physics")
	float CurrentForce = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Materials")
	class UMaterialInstanceDynamic* BeamMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	FLinearColor MinColor = FLinearColor::Green;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	FLinearColor MaxColor = FLinearColor::Red;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* BeamMesh;

	UFUNCTION(BlueprintCallable, Category = "Physics")
	void ApplySpringForces(const FVector Conn1Pos, const FVector Conn2Pos);

	UFUNCTION(BlueprintCallable, Category = "Physics")
	void UpdateBeamTransform(const FVector& Conn1Pos, const FVector& Conn2Pos);

	UFUNCTION(BlueprintCallable, Category = "Visual")
	void UpdateBeamColor();

	UFUNCTION(BlueprintCallable, Category = "Debug")
	void DebugConnectors() const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
