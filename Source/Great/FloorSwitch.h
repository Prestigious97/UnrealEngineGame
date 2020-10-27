// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorSwitch.generated.h"

UCLASS()
class GREAT_API AFloorSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorSwitch();

	/** Overlap volume for functionality to be triggered */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FloorSwitch")
	class UBoxComponent* TriggerBox;

	/** The switch for the character to step on  */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FloorSwitch")
	class UStaticMeshComponent* FloorSwitch;

	/** Door to move when character steps on floor switch */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FloorSwitch")
	UStaticMeshComponent* Door;
	/** Initial Door Location */
	UPROPERTY(BlueprintReadWrite, Category = "FloorSwitch")
	FVector InitialDoorLocation;

	/** Initial Location for floor switch */
	UPROPERTY(BlueprintReadWrite, Category = "FloorSwitch")
	FVector InitialSwitchLocation;

	FTimerHandle SwitchHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloorSwitch")
	float SwitchTime;

	bool bCharacterOnSwitch;
	void CloseDoor();

protected:
	// Called when the game starts or when spawned	
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Switch")
	void RaiseDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Switch")
	void LowerDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Switch")
	void RaiseFloorSwitch();

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Switch")
	void LowerFloorSwitch();

	UFUNCTION(BlueprintCallable, Category = "Floor Switch")
	void UpdateDoorLocation(float Z);

	UFUNCTION(BlueprintCallable, Category = "Floor Switch")
	void UpdateFloorSwitchLocation(float Z);
};
