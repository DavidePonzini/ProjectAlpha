// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "ToggleLight.h"


// Sets default values
AToggleLight::AToggleLight()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Initialise components
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

/*
	LightComp = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightComp"));
	LightComp->AttachTo(RootComponent);
	LightComp->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	LightComp->bVisible = false;
*/

	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));
	AudioComp->AttachTo(RootComponent);
	AudioComp->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	AudioComp->bAutoActivate = false;

	ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComp"));
	ParticleComp->AttachTo(RootComponent);
	ParticleComp->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	ParticleComp->bAutoActivate = false;

	// Set default values
	bIsLit = false;
	bStartsLit = false;
}

// Called when the game starts or when spawned
void AToggleLight::BeginPlay()
{
		Super::BeginPlay();

	// Turn on light if we need to
	if (bStartsLit)
		TurnOn();
}

// Is the light currenlty lit?
bool AToggleLight::IsLit()
{
	return bIsLit;
}

// Turn the light on
void AToggleLight::TurnOn()
{
	if (!bIsLit)
	{
		bIsLit = true;
		
		// Turn on light and sound
//		LightComp->SetVisibility(true);
		AudioComp->Play();
		ParticleComp->Activate();
	}
}

// Turn the light off
void AToggleLight::TurnOff()
{
	if (bIsLit)
	{
		bIsLit = false;
		
		// Turn off light and sound
//		LightComp->SetVisibility(false);
		AudioComp->Stop();
		ParticleComp->Deactivate();
	}
}

// Toggle light
void AToggleLight::Toggle()
{
	if (IsLit())
		TurnOff();
	else
		TurnOn();
}
