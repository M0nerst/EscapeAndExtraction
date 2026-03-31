// LeaveMeAlone Game by Netologiya. All RightsReserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_FindPatrolLocation.generated.h"

/**
 * Задача для Behavior Tree: находит случайную точку для патруля в навигационной сетке
 */
UCLASS()
class LEAVEMEALONE_API UBTT_FindPatrolLocation : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_FindPatrolLocation();

	// Выполняется при запуске задачи
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	// Ключ Blackboard, куда сохранить найденную позицию
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector PatrolLocationKey;

	// Радиус поиска случайной точки
	UPROPERTY(EditAnywhere, Category = "Patrol", meta = (ClampMin = "100.0", UIMin = "100.0"))
	float SearchRadius = 1000.0f;
};
