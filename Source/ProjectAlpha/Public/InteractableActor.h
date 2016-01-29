// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

UCLASS(ABSTRACT)
class PROJECTALPHA_API AInteractableActor : public AActor
{
	GENERATED_BODY()

private:
	UTextRenderComponent* Text;


protected:
	// Sets default values for this actor's properties
	AInteractableActor(); 
	
	UPROPERTY(EditAnywhere, Category = "MeshComponent")
		UStaticMeshComponent* MeshComp;
	
public:	
	virtual void BeginFocus();

	virtual void EndFocus();

	virtual void Interact(APawn* Instigator);
	
	UStaticMeshComponent* GetMeshComponent() const;
};
