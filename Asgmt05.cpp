// Copyright Epic Games, Inc. All Rights Reserved.

#include "Asgmt05.h"
#include <iostream>
#include <CoreMinimal.h>

// Sets default values
AAsgmt05::AAsgmt05()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAsgmt05::BeginPlay()
{
	move();
}

// Called every frame
void AAsgmt05::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AAsgmt05::distance(FVector2D first, FVector2D second)
{
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(pow(dx, 2) + pow(dy, 2));
}

void AAsgmt05::move()
{
	UE_LOG(LogTemp, Log, TEXT("start : (%d, %d)"), (int32)start.X, (int32)start.Y);

	for (int32 i = 0; i < 10; i++)
	{
		FVector2D lastMove = start;
		start.X += step();
		start.Y += step();
		UE_LOG(LogTemp, Display, TEXT("%d. "), i + 1)
		UE_LOG(LogTemp, Warning, TEXT("(%d, %d)"), (int32)start.X, (int32)start.Y);
		UE_LOG(LogTemp, Warning, TEXT("%f Move"), distance(start, lastMove));
		totDist += distance(start, lastMove);

		if (createEvent() < 50)
		{
			UE_LOG(LogTemp, Error, TEXT("Event Triggered!"));
			evCnt++;
		}
		else
		{
			continue;
		}
	}

	UE_LOG(LogTemp, Display, TEXT("Total Distance : %f"), totDist);
	UE_LOG(LogTemp, Display, TEXT("Total Evemt : %d"), evCnt);
}

int32 AAsgmt05::step()
{
	return FMath::RandRange(0, 1);
}

int32 AAsgmt05::createEvent()
{
	return FMath::RandRange(0, 99);
}