// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractableComponent.h"
#include "Interactable.generated.h"

UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UInteractable : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IInteractable
{
	GENERATED_IINTERFACE_BODY()

protected:
	IInteractable();

public:
	UFUNCTION(BlueprintCallable, Category = "Interaction")
		virtual UInteractableComponent* GetInteractableComponent() const;
	
};