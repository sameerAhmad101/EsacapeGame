// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	m_actorOwner = GetOwner();
	triggerAtor = GetWorld()->GetFirstPlayerController()->GetPawn();
	// ...
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (pressurePalete->IsOverlappingActor(triggerAtor))
	{
		openDoor();
	}
	else if((GetWorld()->GetTimeSeconds() - m_openDoorTime) > closeDoorDelay)
	{
		closeDoor();
	}
}


void UOpenDoor::openDoor()
{
	// Find owning actor.
	m_actorRotator.Yaw = openAngle;
	m_actorRotator.Pitch = 0.f;
	m_actorRotator.Roll = 0.f;
	m_actorOwner->SetActorRotation(m_actorRotator);
    m_openDoorTime = GetWorld()->GetTimeSeconds();
	
}
void UOpenDoor::closeDoor()
{
	m_actorRotator.Yaw = 0.f;
	m_actorRotator.Pitch = 0.f;
	m_actorRotator.Roll = 0.f;
	m_actorOwner->SetActorRotation(m_actorRotator);
}