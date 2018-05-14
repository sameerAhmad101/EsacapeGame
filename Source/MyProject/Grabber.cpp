// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Public/DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	m_playerController = GetWorld()->GetFirstPlayerController();
	m_actorOwner = GetOwner();
	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// get viewpoint for pawn every tick.
	m_playerController->GetPlayerViewPoint(m_playerPoisition, m_playerRotator);
	//UE_LOG(LogTemp, Error, TEXT("pwans rotation:  %s and position t %s"), *m_playerRotator.ToString(), *m_playerPoisition.ToString());
	DrawDebugLine(
		GetWorld(),
		m_playerPoisition,
		m_playerPoisition + (m_playerRotator.Vector() * 100),
		FColor(0,100,200),
		false,
		0.f,
		0.f,
		10.f
	);
}

