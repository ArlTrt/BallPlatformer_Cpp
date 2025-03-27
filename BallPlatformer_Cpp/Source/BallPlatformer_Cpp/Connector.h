// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Connector.generated.h"

class ABeam;

UCLASS(Blueprintable)
class BALLPLATFORMER_CPP_API AConnector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConnector();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Beams")
	TArray<ABeam*> ConnectedBeams;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* ConnectorMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
