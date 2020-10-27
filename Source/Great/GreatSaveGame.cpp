// Fill out your copyright notice in the Description page of Project Settings.


#include "GreatSaveGame.h"

UGreatSaveGame::UGreatSaveGame()
{
	PlayerName = TEXT("Default");
	UserIndex = 0;

	/** Sets default to empty string */
	CharacterStats.WeaponName = TEXT("");
	CharacterStats.LevelName = TEXT("");
}