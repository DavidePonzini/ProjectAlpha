// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PickupActor.h"


APickupActor::APickupActor()
{
}

void APickupActor::BeginPlay()
{
}

void APickupActor::Tick(float DeltaSeconds)
{
}

void APickupActor::InteractImplementation(ABaseCharacter* Instigator)
{
	ABaseCharacter* p = Cast<ABaseCharacter>(Instigator);
	p->AddItem(InventoryItem->GetDefaultObject<UItem>());
	
	//SetActorHiddenInGame(true);

}

void APickupActor::BeginFocus(ABaseCharacter* Instigator)
{
	Super::BeginFocus(Instigator);
}

void APickupActor::EndFocus(ABaseCharacter* Instigator)
{
	Super::EndFocus(Instigator);


}