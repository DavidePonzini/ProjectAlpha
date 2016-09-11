// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PInteractableComponent.h"
#include "PItem.h"
#include "PPickupComponent.generated.h"

/**
*
*/
UCLASS(ClassGroup = (Interaction), meta = (BlueprintSpawnableComponent))
class PROJECTALPHA_API UPPickupComponent : public UPInteractableComponent
{
	GENERATED_BODY()

public:
	UPPickupComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup")
		TSubclassOf<UPItem> Item;

	void OnInteract(APCharacter* Cause) override;

};
