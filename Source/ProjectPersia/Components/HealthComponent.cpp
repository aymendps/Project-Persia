// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	CurrentHealth = MaxHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// Bind the OnDamageTaken function to the OnTakeAnyDamage event.
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OnDamageTaken);
}

// Called when the actor takes damage.
void UHealthComponent::OnDamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* Instigator, AActor* DamageCauser)
{
	// If damage is invalid or player is already dead, return.
	if(Damage <= 0.0f || CurrentHealth <= 0.0f) return;

	CurrentHealth -= Damage;
	OnActorDamaged.Broadcast(DamageType, Instigator, DamageCauser, Damage, CurrentHealth);

	// If the player dies due to this damage
	if(CurrentHealth <= 0.0f)
	{
		OnActorDied.Broadcast(DamageType, Instigator, DamageCauser);
	}
}

// Heals the actor by the given amount.
void UHealthComponent::HealActor(const float HealAmount)
{
	// If heal is invalid or player is already dead, return.
	if(HealAmount <= 0.0f || CurrentHealth <= 0.0f) return;

	// Heal the player by the given amount, but don't exceed the max health.
	CurrentHealth = CurrentHealth + HealAmount > MaxHealth ? MaxHealth : CurrentHealth + HealAmount;
	OnActorHealed.Broadcast(HealAmount, CurrentHealth);
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

