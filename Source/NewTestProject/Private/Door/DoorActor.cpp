// New Test Project Game. All Rights Reserved.


#include "Door/DoorActor.h"
#include "Components/BoxComponent.h"
#include <NewTestProject/NewTestProject.h>

ADoorActor::ADoorActor()
{
	PrimaryActorTick.bCanEverTick = true;
		
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrameMesh"));
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorTimelineComp = CreateDefaultSubobject<UTimelineComponent>(TEXT("DoorTimelineComp"));
	DoorProxVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("DoorProximityVolume"));
		
	DoorFrame->SetupAttachment(RootComponent);
	Door->AttachToComponent(DoorFrame, FAttachmentTransformRules::KeepRelativeTransform);
	DoorProxVolume->AttachToComponent(DoorFrame, FAttachmentTransformRules::KeepRelativeTransform);
}


void ADoorActor::BeginPlay()
{
	Super::BeginPlay();
		
	UpdateFunctionFloat.BindDynamic(this, &ADoorActor::UpdateTimelineComp);
		
	if (DoorTimelineFloatCurve)
	{
		DoorTimelineComp->AddInterpFloat(DoorTimelineFloatCurve, UpdateFunctionFloat);
	}
		
	DoorProxVolume->OnComponentBeginOverlap.AddDynamic(this, &ADoorActor::OnOverlapBegin);
	DoorProxVolume->OnComponentEndOverlap.AddDynamic(this, &ADoorActor::OnOverlapEnd);
}

void ADoorActor::UpdateTimelineComp(float Output)
{	
	FRotator DoorNewRotation = FRotator(0.0f, Output, 0.f);
	Door->SetRelativeRotation(DoorNewRotation);
}

void ADoorActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	DoorTimelineComp->Play();
}

void ADoorActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	DoorTimelineComp->Reverse();
}

void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
