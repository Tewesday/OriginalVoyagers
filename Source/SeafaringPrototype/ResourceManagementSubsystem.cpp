// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceManagementSubsystem.h"

void UResourceManagementSubsystem::AddRegion(FString RegionName) {
	TMap<FString, int32> Resources;
	FTNestedMap NestedMap;
	NestedMap.NestedMap = Resources;

	RegionResourceMap.Add(RegionName, NestedMap);
}

void UResourceManagementSubsystem::AddResource(FString RegionName, FString ResourceName) {
	RegionResourceMap.Find(RegionName)->NestedMap.Add(ResourceName);
}

int32 UResourceManagementSubsystem::IncrementResource(FString RegionName, FString ResourceName) {
	int32* ResourceValue = RegionResourceMap.Find(RegionName)->NestedMap.Find(ResourceName);
	int32 UpdatedValue = *(ResourceValue) + 1;
	RegionResourceMap.Find(RegionName)->NestedMap.Emplace(ResourceName, UpdatedValue);

	return UpdatedValue;
}

int32 UResourceManagementSubsystem::IncrementResourceByAmount(FString RegionName, FString ResourceName, int32 ValueIncrease) {
	int32* ResourceValue = RegionResourceMap.Find(RegionName)->NestedMap.Find(ResourceName);
	int32 UpdatedValue = *(ResourceValue) + ValueIncrease;
	RegionResourceMap.Find(RegionName)->NestedMap.Emplace(ResourceName, UpdatedValue);

	return UpdatedValue;
}

int32 UResourceManagementSubsystem::DecrementResource(FString RegionName, FString ResourceName) {
	int32* ResourceValue = RegionResourceMap.Find(RegionName)->NestedMap.Find(ResourceName);
	int32 UpdatedValue = *(ResourceValue) - 1;
	RegionResourceMap.Find(RegionName)->NestedMap.Emplace(ResourceName, UpdatedValue);

	return UpdatedValue;
}

int32 UResourceManagementSubsystem::DecrementResourceByAmount(FString RegionName, FString ResourceName, int32 ValueDecrease) {
	int32* ResourceValue = RegionResourceMap.Find(RegionName)->NestedMap.Find(ResourceName);
	int32 UpdatedValue = *(ResourceValue) - ValueDecrease;
	RegionResourceMap.Find(RegionName)->NestedMap.Emplace(ResourceName, UpdatedValue);

	return UpdatedValue;
}

int32 UResourceManagementSubsystem::RetrieveResourceValue(FString RegionName, FString ResourceName) {
	int32 ResourceValue = *RegionResourceMap.Find(RegionName)->NestedMap.Find(ResourceName);

	return ResourceValue;
}