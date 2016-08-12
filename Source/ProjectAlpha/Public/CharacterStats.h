#pragma once

#include "Components/ActorComponent.h"
#include "CharacterStats.generated.h"

/** Module for Character Stats.
 * TODO -- add buff/debuff support
 */

 // Stat type definitions
UENUM(BlueprintType)
enum EStatValue
{
	Health,
	Ki,
	Stamina,
	NO_ELEMS
};

USTRUCT()
struct FStatData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Stats|Stats")
		float Max;
	UPROPERTY(EditAnywhere, Category = "Stats|Stats")
		float Current;
	UPROPERTY(EditAnywhere, Category = "Stats|Stats")
		float Buff;
};

USTRUCT()
struct FSkillData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Stats|Skills")
		float Value;
	UPROPERTY(EditAnywhere, Category = "Stats|Skills")
		float Buff;
};

UCLASS()
class PROJECTALPHA_API UCharacterStats : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCharacterStats();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

// Values
public:

	UPROPERTY(EditAnywhere, Category = "Stats|Stats")
		FStatData Health;
	UPROPERTY(EditAnywhere, Category = "Stats|Stats")
		FStatData Ki;
	UPROPERTY(EditAnywhere, Category = "Stats|Stats")
		FStatData Stamina;

	UPROPERTY(EditAnywhere, Category = "Stats|Stats")
		int Experience;

	UPROPERTY(EditAnywhere, Category = "Stats|Skills")
		FSkillData Archery;
	UPROPERTY(EditAnywhere, Category = "Stats|Skills")
		FSkillData Swordmanship;
	
// Getters
public:

	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetStatMax(EStatValue stat) const;
	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetStat(EStatValue stat) const;
	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetStatBuff(EStatValue stat) const;

// Setters
public:
	// Changers -- increment or decrement a stat
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void ChangeStatMax(EStatValue stat, float amount);
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void ChangeStat(EStatValue stat, float amount);
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void ChangeStatBuff(EStatValue stat, float amount);

	// Clear buffs
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void ClearStatBuff(EStatValue stat);

/*				ARE THESE NEEDED?

	// Setters -- set directly a stat
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetStatMax(EStatValue stat, float amount);
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void SetStat(EStatValue stat, float amount);
*/
};
