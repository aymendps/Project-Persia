// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActorDiedDelegate, const UDamageType*, DamageType,
	AController*, Instigator, AActor*, DamageCauser);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnActorDamagedDelegate, const UDamageType*, DamageType,
	AController*, Instigator, AActor*, DamageCauser, float, DamageAmount, float, RemainingHealth);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorHealedDelegate, float, HealAmount, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorMaxHealthGainedDelegate, float, HealthGained, float, NewMaxHealth);
	

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

private:
	/**
	 * Called when the actor takes damage.
	 * @param DamagedActor The actor that took damage.
	 * @param Damage The amount of damage taken.
	 * @param DamageType The type of damage taken (physical, fall damage..).
	 * @param Instigator The controller that caused the damage (enemy, player..).
	 * @param DamageCauser The actor that caused the damage (spikes, sword..).
	 */
	UFUNCTION()
	void OnDamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health Stats")
	float MaxHealth = 3.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health Stats")
	float CurrentHealth = 3.0f;

	/**
	 * Heals the actor by the given amount.
	 * @param HealAmount The amount to heal the actor by.
	 */
	UFUNCTION(BlueprintCallable, Category="Health Component")
	void HealActor(const float HealAmount);

	/**
	 * Increases the actor's max health by the given amount.
	 * @param HealthGained The amount to increase the actor's max health by.
	 */
	UFUNCTION(BlueprintCallable, Category="Health Component")
	void GainMaxHealth(const float HealthGained);
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
	 * Event that's invoked when the actor dies, so when the health reaches 0 or below.
	 */
	UPROPERTY(BlueprintAssignable, Category="Health Component")
	FOnActorDiedDelegate OnActorDied;

	/**
	 * Event that's invoked when the actor takes damage.
	 */
	UPROPERTY(BlueprintAssignable, Category="Health Component")
	FOnActorDamagedDelegate OnActorDamaged;

	/**
    * Event that's invoked when the actor is healed.
    */
	UPROPERTY(BlueprintAssignable, Category="Health Component")
	FOnActorHealedDelegate OnActorHealed;

	/**
	* Event that's invoked when the actor gains max health.
	*/
	UPROPERTY(BlueprintAssignable, Category="Health Component")
	FOnActorMaxHealthGainedDelegate OnActorMaxHealthGained;
};
