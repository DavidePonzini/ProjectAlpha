// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "BaseCharacter.h"
#include "InteractableComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTALPHA_API UInteractableComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractableComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPrimitiveComponent* RootComponent;

public:
	UPROPERTY(EditAnywhere, Category = "Interaction")
		bool bBlockInteraction;
	UPROPERTY(EditAnywhere, Category = "Interaction")
		FString InteractionMessage;

public:
	virtual void OnBeginFocus();
	virtual void OnEndFocus();

	UFUNCTION(BlueprintCallable, Category = "Interaction")
		virtual void OnInteract(ABaseCharacter* Cause);

	UFUNCTION(BlueprintCallable, Category = "Interaction")
		void BlockInteraction(bool Block);

	UFUNCTION(BlueprintCallable, Category = "Interaction")
		bool IsInteractionBlocked() const;

	UFUNCTION(BlueprintCallable, Category = "Interaction")
		FString GetInteractionMessage() const;
	
};
