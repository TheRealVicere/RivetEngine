#include "CollisionTestPairCommand.h"

#include "CollisionComponent.h"
#include "CollisionAttorney.h"
#include "CollisionDispatchBase.h"
#include "CollisionGroup.h"
#include "Colors.h"
#include "Debugger.h"
#include "MathTools.h"

CollisionTestPairCommand::CollisionTestPairCommand(CollisionGroup* g1,
	CollisionGroup* g2, CollisionDispatchBase* d):
	CollisionTestCommand(g1, d), group2(g2) {}

void CollisionTestPairCommand::Execute()
{
	AABB partition1(group1->GetPartition());
	AABB partition2(group2->GetPartition());

	if (!MathTools::Intersect(partition1, partition2)) return;

	Debugger::ShowBox(partition1, Colors::LucidiaGreen);
	Debugger::ShowBox(partition2, Colors::LucidiaGreen);

	const CollisionGroup::CollisionComponentList& collection1 =
		group1->GetCollisionComponentList();
	const CollisionGroup::CollisionComponentList& collection2 =
		group2->GetCollisionComponentList();

	for (auto it1 = collection1.begin(); it1 != collection1.end(); it1++) {
		BSphere s1((*it1)->GetDefaultSphere());
		if (MathTools::Intersect(s1, partition2)) {
			for (auto it2 = collection2.begin(); it2 != collection2.end(); it2++) {
				BSphere s2((*it2)->GetDefaultSphere());
				if (MathTools::Intersect(s1, s2)) {
					Debugger::ShowBSphere(s1, Colors::Gold);
					Debugger::ShowBSphere(s2, Colors::Gold);

					const CollisionVolume& v1 = (*it1)->GetVolume();
					const CollisionVolume& v2 = (*it2)->GetVolume();

					if (MathTools::Intersect(v1, v2)) {
						dispatch->ProcessCallbacks(*it1, *it2);
						Debugger::ShowVolume(v1, Colors::Red);
						Debugger::ShowVolume(v2, Colors::Red);
					}
				}
			}
		}
	}
}
