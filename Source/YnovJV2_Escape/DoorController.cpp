// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"


// Sets default values for this component's properties
UDoorController::UDoorController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorController::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UDoorController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// on proceed l'angle en fonction
	if (getOverlappingWeight() >= massToOpen) {
		onOpen.Broadcast();
	}
	else {
		onClose.Broadcast();
	}
}

float UDoorController::getOverlappingWeight() {
	float weight = 0.f;
	if (pressurePlate) {
		TArray<AActor*> overlappingActors;
		pressurePlate->GetOverlappingActors(overlappingActors);
		for (const AActor* overlappingActor : overlappingActors)
		{
			weight += overlappingActor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("%f"), weight);
	return weight;
}
