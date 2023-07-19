// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "DamageTypeBase.generated.h"

enum class EDamageTypeIdentifier : uint8;

/**
 * Base class for damage types.
 */
UCLASS()
class PROJECTPERSIA_API UDamageTypeBase : public UDamageType
{
	GENERATED_BODY()

protected:
	// Is used to identify the damage type when handling specific logic in switch statements.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage Type Settings")
	EDamageTypeIdentifier DamageTypeIdentifier;

	// The death animation montage to play when the character dies from this damage type.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage Type Settings")
	UAnimMontage* DeathAnimationMontage;

	// The delay before the level reloads after the character dies. This is used to give the death animation time to play.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage Type Settings")
	float DeathAnimationDelayBeforeReload;
};
