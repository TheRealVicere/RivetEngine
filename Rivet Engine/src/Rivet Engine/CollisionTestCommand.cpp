#include "CollisionTestCommand.h"

#include "CollisionComponent.h"
#include "CollisionAttorney.h"
#include "CollisionDispatchBase.h"
#include "CollisionGroup.h"
#include "Colors.h"
#include "Debugger.h"
#include "MathTools.h"

CollisionTestCommand::CollisionTestCommand(CollisionGroup* g1,
	CollisionDispatchBase* d):
	group1(g1), dispatch(d) {}

CollisionTestCommand::~CollisionTestCommand()
{
	delete dispatch;
}

void CollisionTestCommand::Execute()
{
	const CollisionGroup::CollisionComponentList& collection =
		group1->GetCollisionComponentList();

	for (auto it1 = collection.begin(); it1 != collection.end(); it1++) {
		auto it2 = it1;
		it2++;
		for (it2; it2 != collection.end(); it2++) {
			BSphere s1((*it1)->GetDefaultSphere());
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
