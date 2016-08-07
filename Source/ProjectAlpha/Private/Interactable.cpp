#include "ProjectAlpha.h"
#include "Interactable.h"

UInteractable::UInteractable(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Nothing to do here
}

IInteractable::IInteractable()
{
	LOG(Warning, "IInteractable", "Called constructor without any arguments!");

	Init(nullptr);
}

IInteractable::IInteractable(AActor* thisActor)
{
	Init(thisActor);
}

void IInteractable::Init(AActor* thisActor)
{
	InteractableActor = thisActor;
	
	bBlockInteraction = false;
}

void IInteractable::OnBeginFocus()
{
	if (bBlockInteraction)
		return;

	USceneComponent* RootSceneComp = InteractableActor->GetRootComponent();
	UPrimitiveComponent* RootPrimitiveComp = Cast<UPrimitiveComponent>(RootSceneComp);

	if (RootPrimitiveComp)
		RootPrimitiveComp->SetRenderCustomDepth(true);
}

void IInteractable::OnEndFocus()
{
	if (bBlockInteraction)
		return;

	USceneComponent* RootSceneComp = InteractableActor->GetRootComponent();
	UPrimitiveComponent* RootPrimitiveComp = Cast<UPrimitiveComponent>(RootSceneComp);

	if (RootPrimitiveComp)
		RootPrimitiveComp->SetRenderCustomDepth(false);
}

void IInteractable::BlockInteraction(bool Block)
{
	bBlockInteraction = Block;
}

bool IInteractable::IsInteractionBlocked() const
{
	return bBlockInteraction;
}

void IInteractable::OnInteract(APawn * Cause)
{
	LOG_ACTOR(Log, InteractableActor, "Activated by %s", *(AActor::GetDebugName(Cause)));
	
	if (bBlockInteraction)
		LOG_ACTOR(Log, InteractableActor, "Interaction is blocked!");

}

FString IInteractable::GetInteractableName() const
{
	return "Missing Interactable Name";
}