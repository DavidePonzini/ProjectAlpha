// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "Character/PCharacter.h"
#include "OutlineColor.h"
#include "PInteractableComponent.generated.h"


UCLASS(ClassGroup = (Interaction), meta = (BlueprintSpawnableComponent))
class PROJECTALPHA_API UPInteractableComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	// Constructor
	UPInteractableComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPrimitiveComponent* RootComponent;

	// OnInteract Delegate
public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractDelegate, APCharacter*, Cause);
	UPROPERTY(BlueprintAssignable, Category = "Interaction")
		FOnInteractDelegate OnInteractDelegate;
	//UFUNCTION(BlueprintCallable, Category = "Interaction")
	void SetOnInteractDelegate(const FOnInteractDelegate& intdel);


public:
	UPROPERTY(EditAnywhere, Category = "Interaction|Block")
		bool bBlockInteraction;
	UPROPERTY(EditAnywhere, Category = "Interaction|Message")
		FString InteractionMessage;
	UPROPERTY(EditAnywhere, Category = "Interaction|Focus")
		TEnumAsByte<EOutlineColor> OutlineColor;

public:
	UFUNCTION(BlueprintCallable, Category = "Interaction")
		virtual void OnInteract(APCharacter* Cause);

	UFUNCTION(BlueprintCallable, Category = "Interaction|Focus")
		virtual void OnBeginFocus();

	UFUNCTION(BlueprintCallable, Category = "Interaction|Focus")
		virtual void OnEndFocus();

	UFUNCTION(BlueprintCallable, Category = "Interaction|Block")
		void BlockInteraction(bool Block);

	UFUNCTION(BlueprintCallable, Category = "Interaction|Block")
		bool IsInteractionBlocked() const;

	UFUNCTION(BlueprintCallable, Category = "Interaction|Message")
		FString GetInteractionMessage() const;

};
