// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicsField.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APhysicsField::APhysicsField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FieldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FieldMesh"));
	RootComponent = FieldMesh;

	FieldSystem = CreateDefaultSubobject<UFieldSystemComponent>(TEXT("FieldSystem"));
	FieldSystem->SetupAttachment(FieldMesh);
}

// Called when the game starts or when spawned
void APhysicsField::BeginPlay()
{
	Super::BeginPlay();

	CreatePhysicsField();
}

// Called every frame
void APhysicsField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APhysicsField::CreatePhysicsField()
{
	if (!FieldSystem) return;

	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Physics field ");

	URadialVector* UpwardForce = NewObject<URadialVector>();
	UpwardForce->Magnitude = 1000.0f;

	FTransform BoxTransform = FieldMesh->GetRelativeTransform();
	

	UBoxFalloff* GravityZone = NewObject<UBoxFalloff>();
	GravityZone->SetBoxFalloff(10.f, 0.f, 10.f, 0.f, BoxTransform, EFieldFalloffType::Field_Falloff_Linear);

	//UUniformVector* ZeroGravity = NewObject<UUniformVector>();
	//ZeroGravity->Magnitude = 100.f;
	//ZeroGravity->Direction = FVector(0.f, 0.f, 1.f);

	UCullingField* Culling = NewObject<UCullingField>();
	Culling->SetCullingField(GravityZone, UpwardForce, EFieldCullingOperationType::Field_Culling_Outside);

	//FieldSystem->ApplyPhysicsField(true, EFieldPhysicsType::Field_LinearForce, nullptr, Culling);
	FieldSystem->AddPersistentField(true, EFieldPhysicsType::Field_LinearForce, nullptr, Culling);
}

void APhysicsField::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Physics field begin overlap ");
}

void APhysicsField::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Physics field end overlap ");
}
