#pragma once

UENUM(BlueprintType)
enum class EInteractableFinder : uint8
{
	// Found an interactable actor that the player is overlapping with.
	Found,
	// Did not find an interactable actor that the player is overlapping with.
	NotFound,
};
