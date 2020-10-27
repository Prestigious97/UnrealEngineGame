// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GreatSaveGame.generated.h"

USTRUCT(BlueprintType) // Expose a struct to blueprints through the UE's reflection system
struct FCharacterStats
{
	GENERATED_BODY() // Generates boiler plate code

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	float Health;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	float MaxHealth;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	float Stamina;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	float MaxStamina;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	int32 Coins;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	FVector Location;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	FRotator Rotation;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	FString WeaponName;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	FString LevelName;

};

/**
 * 
 */
UCLASS()
class GREAT_API UGreatSaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	UGreatSaveGame();

	UPROPERTY(VisibleAnywhere, Category = Basic) // Category needs to be "Basic" in order to save it 
	FString PlayerName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 UserIndex;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FCharacterStats CharacterStats;

};
