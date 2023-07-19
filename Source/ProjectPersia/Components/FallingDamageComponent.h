// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FallingDamageComponent.generated.h"

/**
 * Component that applies falling damage.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTPERSIA_API UFallingDamageComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFallingDamageComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Whether to apply fall damage or not
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Falling Data")
	bool bApplyFallDamage = true;

	// Used to get the amount of damage to apply based on the falling speed
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Falling Data")
	UCurveFloat* SpeedToDamageCurve;

	UPROPERTY(BlueprintReadOnly, Category="Falling Data")
	float CurrentFallingSpeed = 0.0f;
	
	UFUNCTION(BlueprintCallable, Category="Falling Data", meta=(DevelopmentOnly))
	void PrintFallingSpeed() const;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
