// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "InteractableActor.h"
#include "ToggleLight.generated.h"

UCLASS()
class PROJECTALPHA_API AToggleLight : public AInteractableActor
{
	GENERATED_BODY()

public:
	// Defaults
	/** Does the light starts lit? */
	UPROPERTY(EditAnywhere, Category = "ToggleLight | Defaults")
		bool bStartsLit;

	/** Mesh component */
/*	UPROPERTY(EditDefaultsOnly, Category = "ToggleLight | Mesh")
		UStaticMeshComponent* MeshComp;

	/** Sound component */
	UPROPERTY(EditDefaultsOnly, Category = "ToggleLight | Sound")
		UAudioComponent* AudioComp;

	/** Particle system component */
	UPROPERTY(EditDefaultsOnly, Category = "ToggleLight | Particles")
	UParticleSystemComponent* ParticleComp;

protected:
	/** Is the light currently lit? */
	bool bIsLit;

public:

	/** Sets default values for this actor's properties */
	AToggleLight();

	/** Called when the game starts or when spawned */
	virtual void BeginPlay() override;

	/** Is the light currenlty lit? */
	UFUNCTION(BlueprintCallable, Category = "Toggle")
		bool IsLit() const;

	/** Turn the light on or off */
	UFUNCTION(BlueprintCallable, Category = "Toggle")
		virtual void TurnOn();
	UFUNCTION(BlueprintCallable, Category = "Toggle")
		virtual void TurnOff();
	UFUNCTION(BlueprintCallable, Category = "Toggle")
		void Toggle();

	virtual void InteractImplementation(ABaseCharacter* Instigator) override;
};
