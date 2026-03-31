// LeaveMeAlone Game by Netologiya. All RightsReserved.


#include "BTT_FindPatrolLocation.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"


UBTT_FindPatrolLocation::UBTT_FindPatrolLocation()
{
	NodeName = "Find Patrol Location";

	// Указываем, что задача использует ключ PatrolLocationKey
	PatrolLocationKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTT_FindPatrolLocation, PatrolLocationKey));
}

EBTNodeResult::Type UBTT_FindPatrolLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Получаем необходимые компоненты
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	AAIController* AIController = OwnerComp.GetAIOwner();

	if (!Blackboard || !AIController)
	{
		return EBTNodeResult::Failed;
	}

	// Получаем персонажа (pawn)
	APawn* ControlledPawn = AIController->GetPawn();
	if (!ControlledPawn)
	{
		return EBTNodeResult::Failed;
	}

	// Получаем навигационную систему
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(ControlledPawn->GetWorld());
	if (!NavSystem)
	{
		return EBTNodeResult::Failed;
	}

	// Пытаемся найти случайную точку в навигационной сетке
	FNavLocation RandomLocation;

	// Используем текущую позицию персонажа как центр поиска
	const FVector Origin = ControlledPawn->GetActorLocation();

	// Ищем случайную достижимую точку
	bool bFound = NavSystem->GetRandomReachablePointInRadius(Origin, SearchRadius, RandomLocation);

	if (bFound)
	{
		// Сохраняем найденную точку в Blackboard
		Blackboard->SetValueAsVector(PatrolLocationKey.SelectedKeyName, RandomLocation.Location);
		return EBTNodeResult::Succeeded;
	}

	// Если не нашли точку - используем текущую позицию
	Blackboard->SetValueAsVector(PatrolLocationKey.SelectedKeyName, Origin);
	return EBTNodeResult::Succeeded;
}