// LeaveMeAlone Game by Netologiya. All RightsReserved.


#include "BTT_GetNextWaypoint.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Enemy/LMAAIController.h"
#include "GameFramework/Pawn.h"
#include "Engine/TargetPoint.h"



UBTT_GetNextWaypoint::UBTT_GetNextWaypoint()
{
	NodeName = "Get Next Waypoint";

	WaypointIndexKey.AddIntFilter(this, GET_MEMBER_NAME_CHECKED(UBTT_GetNextWaypoint, WaypointIndexKey));
	WaypointLocationKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTT_GetNextWaypoint, WaypointLocationKey));
}

EBTNodeResult::Type UBTT_GetNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	AAIController* AIController = OwnerComp.GetAIOwner();

	if (!Blackboard || !AIController)
	{
		return EBTNodeResult::Failed;
	}

	// Получаем персонажа (Pawn), которым управляет контроллер
	APawn* ControlledPawn = AIController->GetPawn();
	if (!ControlledPawn)
	{
		return EBTNodeResult::Failed;
	}

	// Ищем массив PatrolPoints в персонаже
	// Для этого нам нужно получить доступ к переменной PatrolPoints в персонаже
	// Самый простой способ - использовать FindField

	// Пытаемся найти свойство PatrolPoints в классе персонажа
	UClass* PawnClass = ControlledPawn->GetClass();
	FProperty* PatrolPointsProp = PawnClass->FindPropertyByName(FName("PatrolPoints"));

	if (!PatrolPointsProp)
	{
		UE_LOG(LogTemp, Error, TEXT("Не найдено свойство PatrolPoints в классе %s"), *PawnClass->GetName());
		return EBTNodeResult::Failed;
	}

	// Получаем массив точек из персонажа
	TArray<AActor*> PatrolPoints;

	FArrayProperty* ArrayProp = CastField<FArrayProperty>(PatrolPointsProp);
	if (ArrayProp)
	{
		void* ArrayPtr = ArrayProp->ContainerPtrToValuePtr<void>(ControlledPawn);
		FScriptArrayHelper ArrayHelper(ArrayProp, ArrayPtr);

		for (int32 i = 0; i < ArrayHelper.Num(); i++)
		{
			uint8* ElementPtr = ArrayHelper.GetRawPtr(i);
			if (ElementPtr)
			{
				FObjectProperty* ObjProp = CastField<FObjectProperty>(ArrayProp->Inner);
				if (ObjProp)
				{
					UObject* Obj = ObjProp->GetObjectPropertyValue(ElementPtr);
					if (Obj && Obj->IsA(AActor::StaticClass()))
					{
						PatrolPoints.Add(Cast<AActor>(Obj));
					}
				}
			}
		}
	}

	// Проверяем, есть ли точки
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Нет точек патруля в массиве PatrolPoints"));
		return EBTNodeResult::Failed;
	}

	// Получаем текущий индекс из Blackboard
	int32 CurrentIndex = Blackboard->GetValueAsInt(WaypointIndexKey.SelectedKeyName);

	// Вычисляем следующий индекс (по кругу)
	int32 NextIndex = (CurrentIndex + 1) % PatrolPoints.Num();

	// Получаем следующую точку
	AActor* NextPoint = PatrolPoints[NextIndex];
	if (!NextPoint)
	{
		return EBTNodeResult::Failed;
	}

	// Сохраняем новый индекс в Blackboard
	Blackboard->SetValueAsInt(WaypointIndexKey.SelectedKeyName, NextIndex);

	// Сохраняем позицию следующей точки в Blackboard
	Blackboard->SetValueAsVector(WaypointLocationKey.SelectedKeyName, NextPoint->GetActorLocation());

	UE_LOG(LogTemp, Log, TEXT("Идем к точке %d: %s"), NextIndex, *NextPoint->GetName());

	return EBTNodeResult::Succeeded;
}