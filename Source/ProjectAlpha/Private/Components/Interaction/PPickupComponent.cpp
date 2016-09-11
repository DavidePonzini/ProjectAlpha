// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PPickupComponent.h"


// Sets default values for this component's properties
UPPickupComponent::UPPickupComponent(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer)
{
}

void UPPickupComponent::OnInteract(APCharacter* Cause)
{
	Super::OnInteract(Cause);

	if (Item)
	{
		LOG_ACTOR(Log, GetOwner(), "Adding item %s to %s", *Item.GetDefaultObject()->Name, *AActor::GetDebugName(Cause));

		Cause->Inventory->AddItem(Item);
	}

	GetOwner()->Destroy();
}