// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Field/FieldSystemActor.h"
#include "Field/FieldSystemComponent.h"
//#include "Field/FieldSystemObjects.h"
#include "Components/BoxComponent.h"
#include "GravityFieldSystem.generated.h"

/**
 * 
 */
UCLASS()
class BALLPLATFORMER_CPP_API AGravityFieldSystem : public AFieldSystemActor
{
	GENERATED_BODY()

public:
    AGravityFieldSystem();

protected:
    virtual void BeginPlay() override;

private:

    UPROPERTY(VisibleAnywhere)
    UFieldSystemComponent* FieldSystem;

    UPROPERTY(VisibleAnywhere)
    UBoxComponent* BoxCollision;

    UPROPERTY()
    UBoxFalloff* BoxFalloff;

    UPROPERTY()
    UCullingField* CullingField;

    void SetupPhysicsField();
	
};
