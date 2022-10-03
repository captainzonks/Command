// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ComCamera.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AComCamera::AComCamera()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetRelativeRotation(FRotator(-70.f, 0.f, 0.f));
	SpringArm->TargetArmLength = 5000.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void AComCamera::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetPlayerController(this, 0)->SetViewTargetWithBlend(this);
}

void AComCamera::MoveLeft()
{
	const FVector2d MousePosition{UWidgetLayoutLibrary::GetMousePositionOnViewport(this)};
	const UE::Math::TVector2<double> ScaledMousePosition{
		MousePosition * UWidgetLayoutLibrary::GetViewportScale(this)
	};
	const FVector2d ViewportSize{UWidgetLayoutLibrary::GetViewportSize(this)};
	const double NormalizedToRange{
		UKismetMathLibrary::NormalizeToRange(ScaledMousePosition.X, 0.f,
		                                     ViewportSize.X * 0.05)
	};
	const double Clamped{UKismetMathLibrary::FClamp(NormalizedToRange, 0.f, 1.f)};

	const FVector3d DeltaLocation = (1.f - Clamped) *
		FVector3d(75.f * UGameplayStatics::GetWorldDeltaSeconds(this) * 20.f, 0.f, 0.f);

	RootComponent->AddRelativeLocation(DeltaLocation);
}

void AComCamera::MoveRight()
{
	const FVector2d MousePosition{UWidgetLayoutLibrary::GetMousePositionOnViewport(this)};
	const UE::Math::TVector2<double> ScaledMousePosition{
		MousePosition * UWidgetLayoutLibrary::GetViewportScale(this)
	};
	const FVector2d ViewPortSize{UWidgetLayoutLibrary::GetViewportSize(this)};
	const double NormalizedToRange{
		UKismetMathLibrary::NormalizeToRange(ScaledMousePosition.X,
		                                     ViewPortSize.X * 0.95,
		                                     ViewPortSize.X)
	};
	const double Clamped{UKismetMathLibrary::FClamp(NormalizedToRange, 0.f, 1.f)};

	const FVector3d DeltaLocation = Clamped *
		FVector3d(-75.f * UGameplayStatics::GetWorldDeltaSeconds(this) * 20.f, 0.f, 0.f);

	RootComponent->AddRelativeLocation(DeltaLocation);
}

void AComCamera::MoveUp()
{
	const FVector2d MousePosition{UWidgetLayoutLibrary::GetMousePositionOnViewport(this)};
	const UE::Math::TVector2<double> ScaledMousePosition{
		MousePosition * UWidgetLayoutLibrary::GetViewportScale(this)
	};
	const FVector2d ViewportSize{UWidgetLayoutLibrary::GetViewportSize(this)};
	const double NormalizedToRange{
		UKismetMathLibrary::NormalizeToRange(ScaledMousePosition.Y, 0.f,
		                                     ViewportSize.Y * 0.05)
	};
	const double Clamped{UKismetMathLibrary::FClamp(NormalizedToRange, 0.f, 1.f)};

	const FVector3d DeltaLocation = (1.f - Clamped) *
		FVector3d(0.f, 75.f * UGameplayStatics::GetWorldDeltaSeconds(this) * 20.f, 0.f);

	RootComponent->AddRelativeLocation(DeltaLocation);
}

void AComCamera::MoveDown()
{
	const FVector2d MousePosition{UWidgetLayoutLibrary::GetMousePositionOnViewport(this)};
	const UE::Math::TVector2<double> ScaledMousePosition{
		MousePosition * UWidgetLayoutLibrary::GetViewportScale(this)
	};
	const FVector2d ViewPortSize{UWidgetLayoutLibrary::GetViewportSize(this)};
	const double NormalizedToRange{
		UKismetMathLibrary::NormalizeToRange(ScaledMousePosition.Y,
		                                     ViewPortSize.Y * 0.95,
		                                     ViewPortSize.Y)
	};
	const double Clamped{UKismetMathLibrary::FClamp(NormalizedToRange, 0.f, 1.f)};

	const FVector3d DeltaLocation = Clamped *
		FVector3d(0.f, -75.f * UGameplayStatics::GetWorldDeltaSeconds(this) * 20.f, 0.f);

	RootComponent->AddRelativeLocation(DeltaLocation);
}

// Called every frame
void AComCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

	MoveLeft();
	MoveRight();
	MoveUp();
	MoveDown();
}
