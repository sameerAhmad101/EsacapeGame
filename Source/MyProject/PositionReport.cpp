/**
*\file PositionReport.cpp.
*\brief implementation of PositionReport component class.

*\author Sameer Ahmad.  
*/

#include "PositionReport.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

	FString name = GetOwner()->GetName();
	FTransform position = GetOwner()->GetTransform();
	FVector transformVector;
	position.TransformVector(transformVector);
	UE_LOG(LogTemp,Warning,TEXT("%s position report %s"), *name,*transformVector.ToString());
	// ...
	
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

