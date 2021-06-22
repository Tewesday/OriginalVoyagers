// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StaticDatabase.generated.h"

/**
 * 
 */
UCLASS()
class SEAFARINGPROTOTYPE_API UStaticDatabase : public UObject
{
	GENERATED_BODY()
public:

	//UPROPERTY(BlueprintReadOnly)
	static const FString ResourceFood;

	//UPROPERTY(BlueprintReadOnly)
	static const FString ResourceWood;
};
