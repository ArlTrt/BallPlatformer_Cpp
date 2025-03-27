// Fill out your copyright notice in the Description page of Project Settings.


#include "Connector.h"
#include "Beam.h"

// Sets default values
AConnector::AConnector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConnectorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ConnectorMesh"));
	SetRootComponent(ConnectorMesh);

	ConnectorMesh->SetSimulatePhysics(true);
	ConnectorMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	ConnectorMesh->BodyInstance.bOverrideMass = true;
	ConnectorMesh->BodyInstance.SetMassOverride(1000.0f);
}

// Called when the game starts or when spawned
void AConnector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConnector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

