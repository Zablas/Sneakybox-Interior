// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Furniture.generated.h"

UCLASS()
class SNEAKYBOX_INTERIOR_API AFurniture : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFurniture();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Rendering")
	USceneComponent* CustomRoot;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Rendering")
	UStaticMeshComponent* Mesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Rendering")
	UStaticMeshComponent* Outline;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
