// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "PopulationSubsystem.generated.h"


USTRUCT()
struct SEAFARINGPROTOTYPE_API FTNestedMap2
{
	GENERATED_BODY()
public:
	UPROPERTY()
		TMap<FString, int32> NestedMap;

	bool operator==(const FTNestedMap2& Other) const {
		return NestedMap.OrderIndependentCompareEqual(Other.NestedMap);
	}
	bool operator!=(const FTNestedMap2& Other) const {
		return !(*this == Other);
	}

	friend inline uint32 GetTypeHash(const FTNestedMap2& Key) {
		uint32 Hash = FCrc::MemCrc32(&Key, sizeof(FTNestedMap2));
		return Hash;
	}
};

/**
 * 
 */
UCLASS()
class SEAFARINGPROTOTYPE_API UPopulationSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	//virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	// Name of Region -> NestedMap -> Name of Population -> Value in Region
	UPROPERTY()
	TMap<FString, FTNestedMap2> RegionPopulationMap;

	UFUNCTION(BlueprintCallable)
	void AddRegion(FString RegionName);

	UFUNCTION(BlueprintCallable)
	void AddPopulationName(FString RegionName, FString PopulationName);

	UFUNCTION(BlueprintCallable)
	int32 IncrementPopulation(FString RegionName, FString PopulationName);

	UFUNCTION(BlueprintCallable)
	int32 IncrementPopulationByAmount(FString RegionName, FString PopulationName, int32 ValueIncrease);

	UFUNCTION(BlueprintCallable)
	int32 DecrementPopulation(FString RegionName, FString PopulationName);

	UFUNCTION(BlueprintCallable)
	int32 DecrementPopulationByAmount(FString RegionName, FString PopulationName, int32 ValueDecrease);

	UFUNCTION(BlueprintCallable)
	int32 TransferPopulationByAmount(FString RegionNameFrom, FString RegionNameTo, FString PopulationName, int32 ValueTransfer);

	UFUNCTION(BlueprintCallable)
	int32 ClampValue(int32 Value);

	UFUNCTION(BlueprintCallable)
	int32 RetrievePopulationValue(FString RegionName, FString PopulationName);
	
};
