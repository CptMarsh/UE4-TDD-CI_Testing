// Fill out your copyright notice in the Description page of Project Settings.


#include "AcceleratingPawnTest.h"

#include "AcceleratingPawn.h"//the class we are testing.
#include "Mocks/AcceleratingPawnMOCK.h"//class mock to implement methods that aren't related with the class but with the tests.

#include "Misc/AutomationTest.h"




#if WITH_DEV_AUTOMATION_TESTS


//each one of this tests should test something of the project class that this test class references to.
//Each project class should have a test class for it. It's something kind of necessary for TDD.

//It's nice if the prettyname follows a pattern like: Game.Unit.ClassToTest.TestName
//TestName should express what you expect from a test given a scenario.
//Pay attention to the automation flags because they're needed to run the tests without UI errors.


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAnAcceleratingPawnShouldntBeNullWhenInstantiatedTest, "Game.Unit.AcceleratingPawnTests.ShouldntBeNullWhenInstantiated", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FAnAcceleratingPawnShouldntBeNullWhenInstantiatedTest::RunTest(const FString& Parameters)
{
	{
		AAcceleratingPawn* testPawn = NewObject<AAcceleratingPawn>();
		
		TestNotNull(TEXT("The pawn shouldn't be null after instantiating it."), testPawn);
	}

	return true;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAnAcceleratingPawnShouldHaveAStaticMeshTest, "Game.Unit.AcceleratingPawnTests.ShouldHaveAStaticMesh", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FAnAcceleratingPawnShouldHaveAStaticMeshTest::RunTest(const FString& Parameters)
{
	{
		AAcceleratingPawn* testPawn = NewObject<AAcceleratingPawn>();
		
		TestTrue(TEXT("The pawn static mesh shouldn't be null if it has one."), testPawn->hasAStaticMesh());
	}

	return true;
}


//uses a mock
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAnAcceleratingPawnMeshShouldBeTheRootComponentTest, "Game.Unit.AcceleratingPawnTests.MeshShouldBeTheRootComponent", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FAnAcceleratingPawnMeshShouldBeTheRootComponentTest::RunTest(const FString& Parameters)
{
	{
		AAcceleratingPawnMOCK* testPawnMock = NewObject<AAcceleratingPawnMOCK>();
		
		TestTrue(TEXT("The pawn static mesh should be the root component."), testPawnMock->isMeshTheRootComponent());
	}

	return true;
}


//uses a mock
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAnAcceleratingPawnShouldHaveGravityEnabledTest, "Game.Unit.AcceleratingPawnTests.ShouldHaveGravityEnabled", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FAnAcceleratingPawnShouldHaveGravityEnabledTest::RunTest(const FString& Parameters)
{
	{
		AAcceleratingPawnMOCK* testPawn = NewObject<AAcceleratingPawnMOCK>();
		
		TestTrue(TEXT("The pawn should have gravity enabled."), testPawn->hasGravityEnabled());
	}

	return true;
}


//uses a mock
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAnAcceleratingPawnShouldntAffectNavigationVolumeTest, "Game.Unit.AcceleratingPawnTests.ShouldntAffectNavigationVolume", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FAnAcceleratingPawnShouldntAffectNavigationVolumeTest::RunTest(const FString& Parameters)
{
	{
		AAcceleratingPawnMOCK* testPawn = NewObject<AAcceleratingPawnMOCK>();
		
		TestFalse(TEXT("The pawn shouldn't affect the navigation volume."), testPawn->isAffectingNavigation());
	}

	return true;
}


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAnAcceleratingPawnShouldBeMovableTest, "ProjectR.Unit.AcceleratingPawnTests.ShouldBeMovable", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FAnAcceleratingPawnShouldBeMovableTest::RunTest(const FString& Parameters)
{
	{
		AAcceleratingPawn* testPawn = NewObject<AAcceleratingPawn>();
		
		TestTrue(TEXT("The pawn's root component should be movable."), testPawn->IsRootComponentMovable());
	}

	return true;
}

#endif //WITH_DEV_AUTOMATION_TESTS
