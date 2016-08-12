#pragma once

#include "Object.h"
#include "Interactable.generated.h"




UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UInteractable : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IInteractable
{
	GENERATED_IINTERFACE_BODY()

private:
	AActor* InteractableActor;
	bool bBlockInteraction;

protected:
	IInteractable();
	IInteractable(AActor* thisActor);
	void Init(AActor* thisActor);

public:
	virtual void OnBeginFocus();
	virtual void OnEndFocus();

	UFUNCTION(BlueprintCallable, Category = "Interaction")
		virtual void OnInteract(APawn* Cause);

	UFUNCTION(BlueprintCallable, Category = "Interaction")
		virtual void BlockInteraction(bool Block);

	UFUNCTION(BlueprintCallable, Category = "Interaction")
		virtual bool IsInteractionBlocked() const;

	UFUNCTION(BlueprintCallable, Category = "Interaction")
		virtual FString GetInteractableName() const;
};