// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "InteractableActor.h"
#include "BaseCharacter.h"

AInteractableActor::AInteractableActor()
	: Super(), IInteractable(this)
{
	

}

void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
	//SetInteractableActor(this);
}

FString AInteractableActor::GetInteractableName() const
{
	return InteractableName;
}