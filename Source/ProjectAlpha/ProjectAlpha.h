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


