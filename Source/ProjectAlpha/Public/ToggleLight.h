// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ToggleLight.generated.h"

UCLASS()
class PROJECTALPHA_API AToggleLight : public AActor
{
	GENERATED_BODY()

public:
	// Components
	UPROPERTY(EditAnywhere, Category = "ToggleLight | Mesh")
		UStaticMeshComponent* MeshComp;

//	UPROPERTY(EditAnywhere, Category = "ToggleLight | Light")
//		UPointLightComponent* LightComp;

	UPROPERTY(EditAnywhere, Category = "ToggleLight | Sound")
		UAudioComponent* AudioComp;

	UPROPERTY(EditAnywhere, Category = "ToggleLight | Light")
		bool bStartsLit;

	UPROPERTY(EditAnywhere, Category = "ToggleLight | Particles")
		UParticleSystemComponent* ParticleComp;

private:
	// Is the light currently lit?
	bool bIsLit;

public:

	// Sets default values for this actor's properties
	AToggleLight();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Is the light currenlty lit?
	UFUNCTION(BlueprintCallable, Category = "ToggleLight")
		bool IsLit();

	// Turn the light on
	UFUNCTION(BlueprintCallable, Category = "ToggleLight")
		void TurnOn();

	// Turn the light off
	UFUNCTION(BlueprintCallable, Category = "ToggleLight")
		void TurnOff();

	// Toggle light
	UFUNCTION(BlueprintCallable, Category = "ToggleLight")
		void Toggle();
};
