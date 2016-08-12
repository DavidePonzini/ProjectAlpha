#include "ProjectAlpha.h"
#include "Interactable.h"

UInteractable::UInteractable(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

IInteractable::IInteractable()
{
}

UInteractableComponent* IInteractable::GetInteractableComponent() const
{
	LOG(Error, "IInteractable", "Function 'GetInteractableComponent()' not overridden!");

	return nullptr;
}