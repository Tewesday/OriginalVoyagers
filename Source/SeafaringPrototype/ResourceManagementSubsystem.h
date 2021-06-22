// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Containers/Map.h"
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
//#include "TNestedMap.h"
#include "ResourceManagementSubsystem.generated.h"

USTRUCT()
struct SEAFARINGPROTOTYPE_API FTNestedMap
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TMap<FString, int32> NestedMap;

	bool operator==(const FTNestedMap& Other) const {
		return NestedMap.OrderIndependentCompareEqual(Other.NestedMap);
	}
	bool operator!=(const FTNestedMap& Other) const {
		return !(*this == Other);
	}

	friend inline uint32 GetTypeHash(const FTNestedMap& Key) {
		uint32 Hash = FCrc::MemCrc32(&Key, sizeof(FTNestedMap));
		return Hash;
	}
};

/**
 * 
 */
UCLASS()
class SEAFARINGPROTOTYPE_API UResourceManagementSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()


public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	// Name of Region -> NestedMap -> Name of Resource -> Value in Region
	UPROPERTY()
	TMap<FString, FTNestedMap> RegionResourceMap;

	UPROPERTY(BlueprintReadOnly)
	TArray<FString> ResourceNames;

	UFUNCTION(BlueprintCallable)
	void AddRegion(FString RegionName);

	UFUNCTION(BlueprintCallable)
	void AddResource(FString RegionName, FString ResourceName);

	UFUNCTION(BlueprintCallable)
	int32 IncrementResource(FString RegionName, FString ResourceName);

	UFUNCTION(BlueprintCallable)
	int32 IncrementResourceByAmount(FString RegionName, FString ResourceName, int32 ValueIncrease);

	UFUNCTION(BlueprintCallable)
	int32 DecrementResource(FString RegionName, FString ResourceName);

	UFUNCTION(BlueprintCallable)
	int32 DecrementResourceByAmount(FString RegionName, FString ResourceName, int32 ValueDecrease);

	UFUNCTION(BlueprintCallable)
	int32 RetrieveResourceValue(FString RegionName, FString ResourceName);


};