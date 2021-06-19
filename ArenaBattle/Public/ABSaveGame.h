// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/SaveGame.h"
#include "ABSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UABSaveGame();

public:
	UPROPERTY()
	int32 CharacterIndex;

	UPROPERTY()
	int32 Exp;

	UPROPERTY()
	int32 Level;

	UPROPERTY()
	int32 HighScore;

	UPROPERTY()
	FString PlayerName;
};
