// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PickupActor.h"
#include "BaseCharacter.h"


APickupActor::APickupActor()
{
}

void APickupActor::BeginPlay()
{
}

void APickupActor::Tick(float DeltaSeconds)
{
}

void APickupActor::InteractImplementation(APawn* Instigator)
{
	ABaseCharacter* p = Cast<ABaseCharacter>(Instigator);
	p->AddItem(InventoryItem->GetDefaultObject<UBaseItem>());
	
	//SetActorHiddenInGame(true);

}

void APickupActor::BeginFocus(APawn* Instigator)
{
	Super::BeginFocus(Instigator);
}

void APickupActor::EndFocus(APawn* Instigator)
{
	Super::EndFocus(Instigator);


}