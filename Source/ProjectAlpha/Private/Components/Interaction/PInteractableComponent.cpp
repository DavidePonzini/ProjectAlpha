// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PInteractableComponent.h"


// Sets default values for this component's properties
UPInteractableComponent::UPInteractableComponent(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

	// Set default values
	bBlockInteraction = false;
}


// Called when the game starts
void UPInteractableComponent::BeginPlay()
{
	Super::BeginPlay();

	RootComponent = Cast<UPrimitiveComponent>(GetAttachmentRoot());

}

void UPInteractableComponent::OnInteract(APCharacter* Cause)
{
	LOG_ACTOR(Log, GetOwner(), "Activated by %s. OnInteractDelegate is %s",
		*AActor::GetDebugName(Cause),
		(OnInteractDelegate.IsBound()) ? TEXT("bound") : TEXT("not bound"));

	OnInteractDelegate.Broadcast(Cause);
}

void UPInteractableComponent::OnBeginFocus()
{
	if (bBlockInteraction)
		return;

	if (RootComponent)
	{
		RootComponent->SetRenderCustomDepth(true);
		RootComponent->CustomDepthStencilValue = OutlineColor.GetValue();
	}

}

void UPInteractableComponent::OnEndFocus()
{
	if (bBlockInteraction)
		return;

	if (RootComponent)
		RootComponent->SetRenderCustomDepth(false);
}

void UPInteractableComponent::BlockInteraction(bool Block)
{
	bBlockInteraction = Block;
}

bool UPInteractableComponent::IsInteractionBlocked() const
{
	return bBlockInteraction;
}


FString UPInteractableComponent::GetInteractionMessage() const
{
	return (bBlockInteraction) ? "" : InteractionMessage;
}
