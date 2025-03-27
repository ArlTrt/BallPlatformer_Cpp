// Fill out your copyright notice in the Description page of Project Settings.


#include "Anchor.h"

AAnchor::AAnchor()
{

    ConnectorMesh->SetSimulatePhysics(false);
    ConnectorMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    ConnectorMesh->SetGenerateOverlapEvents(false);

}