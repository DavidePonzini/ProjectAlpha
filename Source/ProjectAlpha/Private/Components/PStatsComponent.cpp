// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PStatsComponent.h"

// Sets default values for this component's properties
UPStatsComponent::UPStatsComponent()
	: Super()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UPStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UPStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UPStatsComponent::GetStatMax(EPStatValue stat) const
{
	switch (stat)
	{
	case EPStatValue::Health:
		return Health.Max;
	case EPStatValue::Ki:
		return Ki.Max;
	case EPStatValue::Stamina:
		return Stamina.Max;
	default:
		LOG(Warning, "CharacterStats", "GetStatMax() -- invalid value %d", (int)stat);
		return 0.0f;
	}
}

float UPStatsComponent::GetStat(EPStatValue stat) const
{
	switch (stat)
	{
	case EPStatValue::Health:
		return Health.Current;
	case EPStatValue::Ki:
		return Ki.Current;
	case EPStatValue::Stamina:
		return Stamina.Current;
	default:
		LOG(Warning, "CharacterStats", "GetStat() -- invalid value %d", (int)stat);
		return 0.0f;
	}
}

float UPStatsComponent::GetStatBuff(EPStatValue stat) const
{
	return 0.0f;
}

void UPStatsComponent::ChangeStatMax(EPStatValue stat, float amount)
{

}

void UPStatsComponent::ChangeStat(EPStatValue stat, float amount)
{

}

void UPStatsComponent::ChangeStatBuff(EPStatValue stat, float amount)
{

}

void UPStatsComponent::ClearStatBuff(EPStatValue stat)
{

}
