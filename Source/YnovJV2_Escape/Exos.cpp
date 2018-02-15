// Fill out your copyright notice in the Description page of Project Settings.

#include "Exos.h"

bool activeExo_1 = false;
int val = 1;
int val2 = 2;
int* valPtr = &val;
int& valRef = val;

// Sets default values for this component's properties
UExos::UExos()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UExos::BeginPlay()
{
	Super::BeginPlay();

	if (activeExo_1) {
		UE_LOG(LogTemp, Warning, TEXT("EXO C++ - START"));
		printVal();

		UE_LOG(LogTemp, Warning, TEXT("EXO C++ - Changer l'adresse du pointeur vers celle de val2"));
		valPtr = &val2;
		printVal();

		UE_LOG(LogTemp, Warning, TEXT("EXO C++ - Changer la valeur pointée ValPtr"));
		val2 = 22;
		printVal();

		UE_LOG(LogTemp, Warning, TEXT("EXO C++ - Changer la valeur pointée ValPtr OTHER"));
		*valPtr = 222;
		printVal();

		UE_LOG(LogTemp, Warning, TEXT("EXO C++ - Changer la valeur de valRef"));
		valRef = 11;
		printVal();

		UE_LOG(LogTemp, Warning, TEXT("EXO C++ - Changer la valeur de valRef OTHER"));
		val = 111;
		printVal();
	}

	
}


// Called every frame
void UExos::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UExos::printVal()
{
	UE_LOG(LogTemp, Warning, TEXT("VALUES => val: %d val2: %d valPtr: %d valRef: %d"), val, val2, *valPtr, valRef);
	UE_LOG(LogTemp, Warning, TEXT("ADRESS => val: %d val2: %d valPtr: %d valRef: %d"), &val, &val2, valPtr, &valRef);
}