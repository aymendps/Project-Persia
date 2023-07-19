// Fill out your copyright notice in the Description page of Project Settings.


#include "FallingDamageComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UFallingDamageComponent::UFallingDamageComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UFallingDamageComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UFallingDamageComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentFallingSpeed = abs(GetOwner()->GetVelocity().Z);
}

/**
 * Applies fall damage to the owner of this component using the SpeedToDamage curve.
 */
void UFallingDamageComponent::ApplyFallDamage()
{
	UGameplayStatics::ApplyDamage(GetOwner(), SpeedToDamageCurve->GetFloatValue(CurrentFallingSpeed),
		nullptr, nullptr, FallDamageType);
}

