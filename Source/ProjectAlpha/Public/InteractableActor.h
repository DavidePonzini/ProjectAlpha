// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"
class ABaseCharacter;


UCLASS(ABSTRACT)
class PROJECTALPHA_API AInteractableActor : public AActor
{
	GENERATED_BODY()

public:
	/* Sets default values for this actor's properties */
	AInteractableActor();


	/***** COMPONENTS *****/
public:
	/* TO BE REMOVED */
	UPROPERTY(EditAnywhere, Category = "Text")
		UTextRenderComponent* Text;

	UPROPERTY(EditAnywhere, Category = "MeshComponent")
		UStaticMeshComponent* MeshComp;

	UStaticMeshComponent* GetMeshComponent() const;

	
	/***** FOCUS *****/
protected:
	bool bIsFocused;

public:
	virtual void BeginFocus(ABaseCharacter* Instigator);
	virtual void EndFocus(ABaseCharacter* Instigator);

	
	/***** INTERACTION *****/
protected:
	/* Blocks interaction */
	UPROPERTY(EditAnywhere, Category = "Interaction")
		bool bBlockInteraction;
	
	/* Actual code called when interacting */
	virtual void InteractImplementation(ABaseCharacter* Instigator);

public:
	UFUNCTION(BlueprintNativeEvent, Category = "Interaction")
		void Interact(ABaseCharacter* WhoInteracted);

	/* Returns true is activation is not blocked and this actor is focused */
	UFUNCTION(BlueprintCallable, Category = "Interaction")
		bool CanBeInteracted() const;

};
