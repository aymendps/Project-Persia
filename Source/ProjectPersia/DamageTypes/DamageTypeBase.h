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
};
