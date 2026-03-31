// LeaveMeAlone Game by Netologiya. All RightsReserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "LMAAIController.generated.h"

/**
 * 
 */
UCLASS()
class LEAVEMEALONE_API ALMAAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ALMAAIController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Patrol")
	TArray<AActor*> PatrolPoints;

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

private:

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	class UBehaviorTree* BehaviorTree;
};


