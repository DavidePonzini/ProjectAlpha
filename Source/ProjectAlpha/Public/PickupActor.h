// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractableActor.h"
#include "BaseInventoryItem.h"
#include "PickupActor.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTALPHA_API APickupActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	APickupActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;


	//BaseInventoryItem;// *InventoryItem;

	virtual void InteractImplementation(APawn* Instigator) override;

	
	
};
