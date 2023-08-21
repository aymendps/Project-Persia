#pragma once

/**
 * These are the tutorial stages for the weapon tutorial in the order that they should be completed.
 */
UENUM(BlueprintType)
enum class EWeaponTutorialStage : uint8
{
	NotStarted,
	EquipWeapon,
	Move,
	SlowMove,
	TurnAround,
	Attack,
	DashForward,
	DashBackward,
	Parry,
	Complete,
};
