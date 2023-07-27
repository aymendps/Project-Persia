#pragma once

UENUM(BlueprintType)
enum class EFightingActionType : uint8
{
	QuickTurnAround,
	Dash,
	Parry,
	Attack,
	None,
};
