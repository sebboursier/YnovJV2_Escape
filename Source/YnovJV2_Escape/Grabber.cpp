// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsHandleComponent.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"

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

	handler = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (!handler) {
		UE_LOG(LogTemp, Warning, TEXT("PhysicsHandleComponent missing for %s"), *GetOwner()->GetName());
	}

	GetOwner()->InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
	GetOwner()->InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::UnGrab);
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (handler->GrabbedComponent) {
		FVector end = getEndViewPoint(distance);

		handler->SetTargetLocation(end);
	}

}

void UGrabber::Grab() {
	if (!handler->GrabbedComponent) {
		FVector end = getEndViewPoint(scope);
		FHitResult outHit;
		bool isGrabbable = GetWorld()->LineTraceSingleByObjectType(outHit, GetOwner()->GetActorLocation(), end, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), FCollisionQueryParams(FName(TEXT("")), false, GetOwner()));

		if (isGrabbable) {
			distance = outHit.Distance;
			end = getEndViewPoint(distance);
			handler->GrabComponentAtLocation(outHit.GetComponent(), NAME_None, end);
		}
	}
}

void UGrabber::UnGrab() {
	handler->ReleaseComponent();
}

FVector UGrabber::getEndViewPoint(float coeff) {
	FVector location;
	FRotator rotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(location, rotation);
	return location + rotation.Vector() * coeff;
}