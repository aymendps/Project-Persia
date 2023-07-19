#pragma once

UENUM(BlueprintType)
enum class EDamageTypeIdentifier : uint8
{
	// Damage caused by falling from a great height.
	Falling,
	// Damage caused by walking into spikes.
	Spikes,
	// Damage caused by getting hit by a sword.
	Sword,
};
