// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionLogger.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UPositionLogger::UPositionLogger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

// Called when the game starts
void UPositionLogger::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("%s, at position %s"), *GetOwner()->GetName(), *GetOwner()->GetActorTransform().GetLocation().ToString());
	
}
