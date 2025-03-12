// Fill out your copyright notice in the Description page of Project Settings.


#include "GravityFieldSystem.h"

AGravityFieldSystem::AGravityFieldSystem()
{
    PrimaryActorTick.bCanEverTick = false;

    FieldSystem = CreateDefaultSubobject<UFieldSystemComponent>(TEXT("FieldSystem"));
    SetRootComponent(FieldSystem);

    BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
    BoxCollision->SetupAttachment(FieldSystem);
    BoxCollision->SetCollisionProfileName(TEXT("Trigger"));

    //BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AGravityFieldSystem::SetupPhysicsField);
}

void AGravityFieldSystem::BeginPlay()
{
    SetupPhysicsField();
}

void AGravityFieldSystem::SetupPhysicsField()
{
    if (!FieldSystem || !BoxCollision) return;

    FTransform BoxTransform = BoxCollision->GetComponentTransform();

    BoxFalloff = NewObject<UBoxFalloff>();
    BoxFalloff->SetBoxFalloff(1.0f, 0.0f, 1.0f, 0.0f, BoxTransform, EFieldFalloffType::Field_FallOff_None);

    CullingField = NewObject<UCullingField>();
    CullingField->SetCullingField(BoxFalloff, nullptr, EFieldCullingOperationType::Field_Culling_Outside);

    FieldSystem->ApplyPhysicsField(true, EFieldPhysicsType::Field_ExternalClusterStrain, nullptr, CullingField);
}
