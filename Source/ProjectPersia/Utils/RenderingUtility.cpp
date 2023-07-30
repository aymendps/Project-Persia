// Fill out your copyright notice in the Description page of Project Settings.


#include "RenderingUtility.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Returns whether the actor is on the viewport or not
bool URenderingUtility::IsOnViewport(AActor* Actor)
{
	if(Actor == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow,
			TEXT("IsOnViewport: Actor is null"));
		return false;
	}

	// Get the actor's location on the screen
	FVector2D ActorScreenLocation;
	const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(Actor->GetWorld(), 0);
	PlayerController->ProjectWorldLocationToScreen(Actor->GetActorLocation(), ActorScreenLocation);
	
	const FVector2D ViewportSize = UWidgetLayoutLibrary::GetViewportSize(Actor->GetWorld());

	// If the actor is on the viewport, its screen location will be between (0, 0) and (ViewportSize.X, ViewportSize.Y)
	return UKismetMathLibrary::InRange_FloatFloat(ActorScreenLocation.X, 0, ViewportSize.X) &&
		UKismetMathLibrary::InRange_FloatFloat(ActorScreenLocation.Y, 0, ViewportSize.Y);
}
