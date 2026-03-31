// LeaveMeAlone Game by Netologiya. All RightsReserved.


#include "Enemy/LMAAIController.h"
#include "Enemy/LMAEnemyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"


ALMAAIController::ALMAAIController()
{
	
}

void ALMAAIController::BeginPlay()
{
	Super::BeginPlay();

	// Запускаем Behavior Tree
	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
}

void ALMAAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	const auto AICharacter = Cast<ALMAEnemyCharacter>(InPawn);
	if (AICharacter)
	{
		RunBehaviorTree(AICharacter->BehaviorTreeAsset);
	}
}
