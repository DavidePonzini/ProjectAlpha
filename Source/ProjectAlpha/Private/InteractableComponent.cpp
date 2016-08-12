// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "InteractableComponent.h"


// Sets default values for this component's properties
UInteractableComponent::UInteractableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

	// Set default values
	bBlockInteraction = false;
}


// Called when the game starts
void UInteractableComponent::BeginPlay()
{
	Super::BeginPlay();

	RootComponent = Cast<UPrimitiveComponent>(GetAttachmentRoot());
	
}

void UInteractableComponent::OnBeginFocus()
{
	if (bBlockInteraction)
		return;

	if (RootComponent)
		RootComponent->SetRenderCustomDepth(true);
}

void UInteractableComponent::OnEndFocus()
{
	if (bBlockInteraction)
		return;

	if (RootComponent)
		RootComponent->SetRenderCustomDepth(false);
}

void UInteractableComponent::BlockInteraction(bool Block)
{
	bBlockInteraction = Block;
}

bool UInteractableComponent::IsInteractionBlocked() const
{
	return bBlockInteraction;
}

void UInteractableComponent::OnInteract(ABaseCharacter * Cause)
{
	LOG_ACTOR(Log, GetAttachmentRootActor(), "Activated by %s", *(AActor::GetDebugName(Cause)));

	if (bBlockInteraction)
		LOG_ACTOR(Log, GetAttachmentRootActor(), "Interaction is blocked!");
}

FString UInteractableComponent::GetInteractionMessage() const
{
	return (bBlockInteraction) ? "" : InteractionMessage;
}