// Fill out your copyright notice in the Description page of Project Settings.


#include "Furniture.h"

// Sets default values
AFurniture::AFurniture()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CustomRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CustomRoot"));
	SetRootComponent(CustomRoot);
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FurnitureMesh"));
	Mesh->SetupAttachment(RootComponent);

	Outline = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Outline"));
	Outline->SetVisibility(false);
	Outline->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AFurniture::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFurniture::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

