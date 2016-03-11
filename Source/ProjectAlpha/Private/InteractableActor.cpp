// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "InteractableActor.h"


// Sets default values
AInteractableActor::AInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

	Text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));
	Text->SetWorldSize(50.f);
	Text->SetHorizontalAlignment(EHTA_Center);
	Text->AttachTo(RootComponent);
	Text->SetText(TEXT("."));
	Text->SetVisibility(false);

	MeshComp->SetRenderCustomDepth(false);

	bBlockInteraction = false;
	bIsFocused = false;
}

bool AInteractableActor::CanBeInteracted() const
{
	return bIsFocused && !bBlockInteraction;
}

// Bluepring function
void AInteractableActor::Interact_Implementation(APawn* Instigator)
{
	if (CanBeInteracted())
	{
		InteractImplementation(Instigator);
	}
}

// Overridable function
void AInteractableActor::InteractImplementation(APawn* Instigator)
{
	// Nothing to do here...
}

void AInteractableActor::BeginFocus(APawn* Instigator)
{
	if (!bIsFocused && !bBlockInteraction)
	{
		bIsFocused = true;

		if (MeshComp)
		{
			MeshComp->SetRenderCustomDepth(true);
			Text->SetVisibility(true);
		}

		if (Instigator)
		{

		}
	}
}

void AInteractableActor::EndFocus(APawn* Instigator)
{
	if (bIsFocused)
	{
		bIsFocused = false;
		
		if (MeshComp)
		{
			MeshComp->SetRenderCustomDepth(false);
			Text->SetVisibility(false);
		}

		if (Instigator)
		{

		}
	}
}

UStaticMeshComponent* AInteractableActor::GetMeshComponent() const
{
	return MeshComp;
}
