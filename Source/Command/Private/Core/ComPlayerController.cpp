// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/ComPlayerController.h"

#include "Actors/ComCamera.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

AComPlayerController::AComPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	DefaultClickTraceChannel = ECollisionChannel::ECC_Camera;
}

void AComPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(this, nullptr, EMouseLockMode::LockAlways, false);
	ComCamera = Cast<AComCamera>(GetViewTarget());
}

void AComPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("Zoom", this, &AComPlayerController::Zoom);
}

void AComPlayerController::Zoom(float AxisValue)
{
	const float ZoomLevel = ZoomFactor + AxisValue * -1.f;

	ZoomFactor = static_cast<float>(UKismetMathLibrary::FClamp(ZoomLevel, 0.f, 10.f));

	if (ComCamera)
	{
		ComCamera->GetSpringArmComponent()->TargetArmLength = ZoomFactor * 200.f + 1000.f;
	}
}
