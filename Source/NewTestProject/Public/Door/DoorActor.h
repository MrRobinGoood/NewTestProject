// New Test Project Game. All Rights Reserved.


#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "DoorActor.generated.h"

UCLASS()
class NEWTESTPROJECT_API ADoorActor : public AActor
{
	GENERATED_BODY()

public:
	
	ADoorActor();
		
	UPROPERTY(EditAnywhere)
	UCurveFloat* DoorTimelineFloatCurve;
	
protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* DoorFrame;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Door;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UTimelineComponent* DoorTimelineComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* DoorProxVolume;

	FOnTimelineFloat UpdateFunctionFloat;

	UFUNCTION()
	void UpdateTimelineComp(float Output); 

	
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:	
	virtual void Tick(float DeltaTime) override;
};



