// Fill out your copyright notice in the Description page of Project Settings.


#include "Beam.h"
#include "Connector.h"
#include "Anchor.h"

// Sets default values
ABeam::ABeam()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BeamMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BeamMesh"));
	SetRootComponent(BeamMesh);

    BeamMesh->SetSimulatePhysics(false);
    BeamMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

// Called when the game starts or when spawned
void ABeam::BeginPlay()
{
	Super::BeginPlay();

    DebugConnectors();
    if (Connector1 && Connector2)
    {
        RestLength = FVector::Distance(
            Connector1->GetActorLocation(),
            Connector2->GetActorLocation()
        );
    }
}

// Called every frame
void ABeam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (Connector1 && Connector2)
    {
        const FVector Conn1Pos = Connector1->GetActorLocation();
        const FVector Conn2Pos = Connector2->GetActorLocation();

        ApplySpringForces(Conn1Pos, Conn2Pos);

        UpdateBeamTransform(Conn1Pos, Conn2Pos);
    } 
}

void ABeam::ApplySpringForces(const FVector Conn1Pos, const FVector Conn2Pos)
{
    if (!Connector1 || !Connector2) return;

    // Hooke law (F = -k * (x - L))
    const float CurrentLength = FVector::Distance(Conn1Pos, Conn2Pos);
    const FVector ForceDir = (Conn2Pos - Conn1Pos).GetSafeNormal();
    const FVector SpringForce = SpringStiffness * (CurrentLength - RestLength) * ForceDir;

    // Apply force & damping to connectors (not anchors)
    if (!Connector1->IsA(AAnchor::StaticClass()))
    {
        Connector1->ConnectorMesh->AddForce(SpringForce);
        Connector1->ConnectorMesh->AddForce(-Connector1->ConnectorMesh->GetPhysicsLinearVelocity() * DampingFactor);
    }

    if (!Connector2->IsA(AAnchor::StaticClass()))
    {
        Connector2->ConnectorMesh->AddForce(-SpringForce);
        Connector2->ConnectorMesh->AddForce(-Connector2->ConnectorMesh->GetPhysicsLinearVelocity() * DampingFactor);
    }
}

void ABeam::UpdateBeamTransform(const FVector& Conn1Pos, const FVector& Conn2Pos)
{
    SetActorLocation((Conn1Pos + Conn2Pos) * 0.5f);

    const FRotator NewRotation = (Conn2Pos - Conn1Pos).Rotation();
    SetActorRotation(NewRotation);
}

void ABeam::DebugConnectors() const
{
    if (GEngine)
    {
        if (Connector1)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green,
                FString::Printf(TEXT("Connector 1: %s"), *Connector1->GetName()));
        }
        else
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Connector 1 not assigned!"));
        }

        if (Connector2)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green,
                FString::Printf(TEXT("Connector 2: %s"), *Connector2->GetName()));
        }
        else
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Connector 2 not assigned!"));
        }
    }
}