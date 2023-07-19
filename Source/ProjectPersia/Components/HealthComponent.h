// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActorDiedDelegate, const UDamageType*, DamageType,
	AController*, Instigator, AActor*, DamageCauser);

/**
 * Component that handles actor's health and damage taken.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTPERSIA_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category="Health")
	float MaxHealth = 3.0f;
	
	UPROPERTY(BlueprintReadOnly, Category="Health")
	float CurrentHealth = 0.0f;

private:
	/**
	 * Called when the actor takes damage
	 * @param DamagedActor The actor that took damage
	 * @param Damage The amount of damage taken
	 * @param DamageType The type of damage taken (physical, fall damage..)
	 * @param Instigator The controller that caused the damage (enemy, player..)
	 * @param DamageCauser The actor that caused the damage (spikes, sword..)
	 */
	UFUNCTION()
	void OnDamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser);
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
	 * Event that is invoked when the actor dies, so when the health reaches 0 or below.
	 */
	UPROPERTY(BlueprintAssignable, Category="Health")
	FOnActorDiedDelegate OnActorDied;
};
