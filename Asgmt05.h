// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Asgmt05.generated.h"

UCLASS()
class NEWCPP_API AAsgmt05 : public AActor
{
	GENERATED_BODY()
	
private:
	FVector2D start = FVector2D(0, 0);
	int32 evCnt = 0;
	float totDist = 0;

public:	
	// Sets default values for this actor's properties
	AAsgmt05();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float distance(FVector2D first, FVector2D second);
	int32 step();
	void move();
	int32 createEvent();

};
