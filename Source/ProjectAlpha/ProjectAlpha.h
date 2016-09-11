// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"

// Custom trace channels
#define ECC_Interactable ECC_GameTraceChannel1

// Logging
#define LOG_ACTOR(Verbosity, thisInstance, Message, ...) \
	UE_LOG(LogTemp,\
		Verbosity,\
		TEXT(">> %s@%s: " Message),\
			*AActor::GetDebugName(thisInstance),\
			*(thisInstance->GetWorld()->GetMapName()),\
		##__VA_ARGS__)

#define LOG(Verbosity, ID, Message, ...) \
	UE_LOG(LogTemp,\
		Verbosity,\
		TEXT(">> " ID ": " Message),\
		##__VA_ARGS__)

#define LOG_SCREEN(Message, Color) \
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, Color, Message)

// Interfaces

/** 
 *	Executes a function on a IInterface
 *	@param	Interface	the interface to call the function on
 *	@param	Function	the name of the function to invoke, without parenthesis or arguments
 *	@param	VAR_ARGS	the function arguments
 *	@return				the return value of the function invoked
 */
#define INTERFACE_EXEC(Interface, Function, ...) \
	Interface->Execute_##Function(Cast<UObject>(Interface), ##__VA_ARGS__)


// Components
#define GET_COMPONENT_BY_CLASS(Actor, ComponentClass) \
	Cast<ComponentClass>(Actor->GetComponentByClass(ComponentClass::StaticClass()))

#define GET_INTERACTABLE_COMPONENT(Actor) \
	GET_COMPONENT_BY_CLASS(Actor, UPInteractableComponent)