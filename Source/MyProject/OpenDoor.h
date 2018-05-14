// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Classes/Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	void openDoor();
	void closeDoor();
	AActor * m_actorOwner;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// Visible and uneditable.
	UPROPERTY(VisibleAnywhere)
		float openAngle = 90.f;
	UPROPERTY(EditAnywhere)
	ATriggerVolume *pressurePalete;

	//UPROPERTY(EditAnywhere)
		AActor *triggerAtor;

		FRotator m_actorRotator;
		FVector m_openRotationVector = {0.f, 40.f, 0.f};
		FVector m_closeRotationVector;

		float m_openDoorTime;

		float closeDoorDelay = 1.f;

};
