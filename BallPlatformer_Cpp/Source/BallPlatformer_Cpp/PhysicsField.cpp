// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicsField.h"

// Sets default values
APhysicsField::APhysicsField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PhysicsField = CreateDefaultSubobject<UFieldSystemComponent>(TEXT("PhysicsField"));
	RootComponent = PhysicsField;
}

// Called when the game starts or when spawned
void APhysicsField::BeginPlay()
{
	Super::BeginPlay();

	CreatePhysicsField(GetActorLocation());
}

// Called every frame
void APhysicsField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APhysicsField::CreatePhysicsField(FVector Location)
{
	if (!PhysicsField) return;

	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Physics field ");

	FTransform BoxTransform = FTransform(FQuat::Identity, Location);

	UBoxFalloff* GravityZone = NewObject<UBoxFalloff>();
	GravityZone->SetBoxFalloff(100.f, 0.f, 100.f, 0.f, BoxTransform, EFieldFalloffType::Field_Falloff_Linear);

	UUniformVector* ZeroGravity = NewObject<UUniformVector>();
	ZeroGravity->Magnitude = 100.f;
	ZeroGravity->Direction = FVector(0.f, 0.f, 1.f);

	UCullingField* Culling = NewObject<UCullingField>();
	Culling->SetCullingField(ZeroGravity, GravityZone, EFieldCullingOperationType::Field_Culling_Outside);

	PhysicsField->ApplyPhysicsField(true, EFieldPhysicsType::Field_LinearForce, nullptr, Culling);
}