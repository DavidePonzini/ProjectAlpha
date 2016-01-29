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
	Text->SetRelativeLocation(FVector(0, 0, -30));
	Text->SetText("A");
	Text->SetVisibility(false);
}

void AInteractableActor::Interact(APawn* Instigator)
{
	// Nothing to do here...
}

void AInteractableActor::BeginFocus()
{
	if (MeshComp)
	{
		MeshComp->SetRenderCustomDepth(true);
		Text->SetVisibility(true);
	}
}


void AInteractableActor::EndFocus()
{
	if (MeshComp)
	{
		MeshComp->SetRenderCustomDepth(false);
		Text->SetVisibility(false);
	}
}

UStaticMeshComponent* AInteractableActor::GetMeshComponent() const
{
	return MeshComp;
}
