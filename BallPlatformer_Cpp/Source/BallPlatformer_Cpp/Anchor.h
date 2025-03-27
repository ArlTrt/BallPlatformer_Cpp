// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Connector.h"
#include "Anchor.generated.h"


UCLASS(Blueprintable)
class BALLPLATFORMER_CPP_API AAnchor : public AConnector
{
	GENERATED_BODY()
	
public:
    AAnchor();

    UFUNCTION(BlueprintCallable, Category = "Anchor")
    bool IsLocked() const { return true; }
};
