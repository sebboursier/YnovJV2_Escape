// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PositionLogger.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class YNOVJV2_ESCAPE_API UPositionLogger : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPositionLogger();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
