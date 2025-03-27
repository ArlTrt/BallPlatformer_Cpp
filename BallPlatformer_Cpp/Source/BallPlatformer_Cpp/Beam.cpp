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

    BeamMesh->SetSimulatePhysics(true);
    BeamMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

    BeamMesh->BodyInstance.bOverrideMass = true;
    BeamMesh->BodyInstance.SetMassOverride(BeamMass);

}

// Called when the game starts or when spawned
void ABeam::BeginPlay()
{
	Super::BeginPlay();

    DebugConnectors();
    RestingPosition = GetActorLocation();
	
}

// Called every frame
void ABeam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (Connector1 && Connector2)
    {
        ApplySpringForces();
    } 
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

void ABeam::ApplySpringForces()
{
    if (!Connector1 || !Connector2) return;

    FVector Conn1Pos = Connector1->GetActorLocation();
    FVector Conn2Pos = Connector2->GetActorLocation();
    FVector BeamPos = GetActorLocation();

    float RestLength = FVector::Distance(Conn1Pos, Conn2Pos);

    // compute directions
    FVector BeamToConn1 = (Conn1Pos - BeamPos);
    FVector BeamToConn2 = (Conn2Pos - BeamPos);
    float DistToConn1 = BeamToConn1.Size();
    float DistToConn2 = BeamToConn2.Size();
    FVector DirToConn1 = BeamToConn1.GetSafeNormal();
    FVector DirToConn2 = BeamToConn2.GetSafeNormal();

    // Hooke law (F = -k * (x - L))
    FVector ForceOnBeamFrom1 = SpringStiffness * (DistToConn1 - (RestLength / 2)) * DirToConn1;
    FVector ForceOnBeamFrom2 = SpringStiffness * (DistToConn2 - (RestLength / 2)) * DirToConn2;

    // apply virtual anchor force
    FVector AnchorReactionForce = FVector::ZeroVector;

    if (Connector1->IsA(AAnchor::StaticClass()))
    {
        AnchorReactionForce += -ForceOnBeamFrom1; // anchor1
    }
    else
    {
        Connector1->ConnectorMesh->AddForce(-ForceOnBeamFrom1);
    }

    if (Connector2->IsA(AAnchor::StaticClass()))
    {
        AnchorReactionForce += -ForceOnBeamFrom2; // anchor2
    }
    else
    {
        Connector2->ConnectorMesh->AddForce(-ForceOnBeamFrom2);
    }

    // apply force
    FVector TotalBeamForce = ForceOnBeamFrom1 + ForceOnBeamFrom2 + AnchorReactionForce;
    BeamMesh->AddForce(TotalBeamForce);

    // add damping
    FVector BeamVelocity = BeamMesh->GetPhysicsLinearVelocity();
    FVector LocalDamping = -BeamVelocity * DampingFactor;

    if (FMath::Abs(DistToConn1 - (RestLength / 2)) < 10.0f)
    {
        LocalDamping *= 2.0f;
    }

    BeamMesh->AddForce(LocalDamping);

    // debug
    DrawDebugLine(GetWorld(), BeamPos, BeamPos + TotalBeamForce * 0.01f, FColor::Green, false, -1, 0, 1.0f);
    DrawDebugLine(GetWorld(), BeamPos, BeamPos + LocalDamping * 0.01f, FColor::Blue, false, -1, 0, 1.0f);
}