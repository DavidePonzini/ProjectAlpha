// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "InteractableActor.generated.h"

class ABaseCharacter;


UCLASS()
class PROJECTALPHA_API AInteractableActor : public AActor, public IInteractable
{
	GENERATED_BODY()


public:
	AInteractableActor();

	UPROPERTY(EditAnywhere, Category = "Interaction")
		FString InteractableName;

	virtual void BeginPlay() override;

	virtual FString GetInteractableName() const override;

};
