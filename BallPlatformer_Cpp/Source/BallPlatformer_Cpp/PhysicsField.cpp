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

	//CreatePhysicsField(GetActorLocation(), 500.f);
}

// Called every frame
void APhysicsField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void APhysicsField::CreatePhysicsField(FVector Location, float Radius)
//{
//	if (!PhysicsField) return;

//	URadialVector* ZeroGravity = NewObject<URadialVector>();
//	ZeroGravity->Magnitude = 1000.f;
//	ZeroGravity->Position = Location;
	//ZeroGravity->Radius = Radius;

//	PhysicsField->ApplyPhysicsField(true, EFieldPhysicsType::Field_LinearForce, nullptr, ZeroGravity);
//}

