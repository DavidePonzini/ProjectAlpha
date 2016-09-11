#pragma once

#include "Components/ActorComponent.h"
#include "PStatsComponent.generated.h"

/** Module for Character Stats.
* TODO -- add buff/debuff support
*/

// Stat type definitions
UENUM(BlueprintType)
enum class EPStatValue
{
	Health,
	Ki,
	Stamina,
	NO_ELEMS
};

USTRUCT()
struct FPStatData
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
struct FPSkillData
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Category = "Stats|Skills")
		float Value;
	UPROPERTY(EditAnywhere, Category = "Stats|Skills")
		float Buff;
};

UCLASS()
class PROJECTALPHA_API UPStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPStatsComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Values
public:

	UPROPERTY(EditAnywhere, Category = "Stats|Stats")
		FPStatData Health;
	UPROPERTY(EditAnywhere, Category = "Stats|Stats")
		FPStatData Ki;
	UPROPERTY(EditAnywhere, Category = "Stats|Stats")
		FPStatData Stamina;

	UPROPERTY(EditAnywhere, Category = "Stats|Stats")
		int Experience;

	UPROPERTY(EditAnywhere, Category = "Stats|Skills")
		FPSkillData Archery;
	UPROPERTY(EditAnywhere, Category = "Stats|Skills")
		FPSkillData Swordmanship;

	// Getters
public:

	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetStatMax(EPStatValue stat) const;
	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetStat(EPStatValue stat) const;
	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetStatBuff(EPStatValue stat) const;

	// Setters
public:
	// Changers -- increment or decrement a stat
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void ChangeStatMax(EPStatValue stat, float amount);
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void ChangeStat(EPStatValue stat, float amount);
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void ChangeStatBuff(EPStatValue stat, float amount);

	// Clear buffs
	UFUNCTION(BlueprintCallable, Category = "Stats")
		void ClearStatBuff(EPStatValue stat);

	/*				ARE THESE NEEDED?

	// Setters -- set directly a stat
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetStatMax(EPStatValue stat, float amount);
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void SetStat(EPStatValue stat, float amount);
	*/
};
