// Fill out your copyright notice in the Description page of Project Settings.


#include "PopulationSubsystem.h"


void UPopulationSubsystem::AddRegion(FString RegionName) {
	TMap<FString, int32> Resources;
	FTNestedMap2 NestedMap;
	NestedMap.NestedMap = Resources;

	RegionPopulationMap.Add(RegionName, NestedMap);
}

void UPopulationSubsystem::AddPopulationName(FString RegionName, FString PopulationName) {
	RegionPopulationMap.Find(RegionName)->NestedMap.Add(PopulationName);
}

int32 UPopulationSubsystem::IncrementPopulation(FString RegionName, FString PopulationName) {
	int32* PopulationValue = RegionPopulationMap.Find(RegionName)->NestedMap.Find(PopulationName);
	int32 UpdatedValue = *(PopulationValue)+1;
	RegionPopulationMap.Find(RegionName)->NestedMap.Emplace(PopulationName, UpdatedValue);

	return UpdatedValue;
}

int32 UPopulationSubsystem::IncrementPopulationByAmount(FString RegionName, FString PopulationName, int32 ValueIncrease) {
	int32* PopulationValue = RegionPopulationMap.Find(RegionName)->NestedMap.Find(PopulationName);
	int32 UpdatedValue = *(PopulationValue)+ValueIncrease;
	RegionPopulationMap.Find(RegionName)->NestedMap.Emplace(PopulationName, UpdatedValue);

	return UpdatedValue;
}

int32 UPopulationSubsystem::DecrementPopulation(FString RegionName, FString PopulationName) {
	int32* PopulationValue = RegionPopulationMap.Find(RegionName)->NestedMap.Find(PopulationName);
	int32 UpdatedValue = *(PopulationValue)-1;
	RegionPopulationMap.Find(RegionName)->NestedMap.Emplace(PopulationName, UpdatedValue);

	return UpdatedValue;
}

int32 UPopulationSubsystem::DecrementPopulationByAmount(FString RegionName, FString PopulationName, int32 ValueDecrease) {
	int32* PopulationValue = RegionPopulationMap.Find(RegionName)->NestedMap.Find(PopulationName);
	int32 UpdatedValue = *(PopulationValue)-ValueDecrease;
	RegionPopulationMap.Find(RegionName)->NestedMap.Emplace(PopulationName, UpdatedValue);

	return UpdatedValue;
}

void UPopulationSubsystem::TransferPopulationByAmount(FString RegionNameFrom, FString RegionNameTo, FString PopulationName, int32 ValueTransfer) {
	DecrementPopulationByAmount(RegionNameFrom, PopulationName, ValueTransfer);
	IncrementPopulationByAmount(RegionNameTo, PopulationName, ValueTransfer);
}

int32 UPopulationSubsystem::RetrievePopulationValue(FString RegionName, FString PopulationName) {
	int32 PopulationValue = *RegionPopulationMap.Find(RegionName)->NestedMap.Find(PopulationName);

	return PopulationValue;
}
