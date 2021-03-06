// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitManagementSubsystem.h"

void UUnitManagementSubsystem::AddSelection(TArray<ABasicPawn*> SelectionToAdd) {
	Units.Append(SelectionToAdd);
}

void UUnitManagementSubsystem::RemoveSelection() {
	Units.Empty();
	/*for (int i = Units.Num(); i > 0; i--) {
		Units.Pop(true);
	}*/
}

//void UUnitManagementSubsystem::InstructUnits(TFunction<void(ABasicPawn* Unit)> InstructionFunction) {
//	for (auto unit : Units)
//	{
//		InstructionFunction(unit);
//	}
//}

void UUnitManagementSubsystem::InstructUnits() {
	for (ABasicPawn* unit : Units)
	{
		unit->ExecuteInstruction();
	}
}


//void UUnitManagementSubsystem::InstructUnits(FunctionDelegate InstructionFunction) {
//	for (auto unit : Units)
//	{
//		InstructionFunction.ExecuteIfBound();
//		//InstructionFunction(unit);
//	}
//}

//void UUnitManagementSubsystem::AssignPathToUnits() {
//	for (ABasicPawn* unit : Units)
//	{
//		unit->AssignPath(Path);
//	}
//}

void UUnitManagementSubsystem::AssignPathToUnits(ABasicRail* PathToAssign) {
	for (ABasicPawn* unit : Units)
	{
		unit->AssignPath(PathToAssign);
	}
}