// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ComUnitBase.h"

#include "Components/DecalComponent.h"

// Sets default values
AComUnitBase::AComUnitBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DecalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal"));
	DecalComponent->SetupAttachment(GetMesh());

	GetMesh()->SetReceivesDecals(false);
}

// Called when the game starts or when spawned
void AComUnitBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AComUnitBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AComUnitBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

