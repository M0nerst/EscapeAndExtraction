// LeaveMeAlone Game by Netologiya. All RightsReserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_GetNextWaypoint.generated.h"

/**
 * Задача для получения следующей точки патруля из массива
 */
UCLASS()
class LEAVEMEALONE_API UBTT_GetNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_GetNextWaypoint();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	// Ключ для индекса текущей точки (хранится в Blackboard)
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector WaypointIndexKey;

	// Ключ для сохранения позиции следующей точки
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector WaypointLocationKey;

};
