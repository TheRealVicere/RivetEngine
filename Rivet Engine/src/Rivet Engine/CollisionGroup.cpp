#include "CollisionGroup.h"

#include "CollisionAttorney.h"
#include "MathTools.h"

CollisionGroup::~CollisionGroup()
{
	list.clear();
}

const CollisionGroup::CollisionComponentList& CollisionGroup::GetCollisionComponentList()
{
	return list;
}

CollisionGroup::ColliderListRef CollisionGroup::Register(CollisionComponent* c)
{
	return list.emplace(list.end(), c);
}

void CollisionGroup::Deregister(CollisionComponent* c)
{
	list.erase(CollisionAttorney::GetColliderListRef(c));
}

void CollisionGroup::UpdateGroupPartition()
{
	if (list.empty()) return;

	auto it = list.begin();
	BSphere next = (*it)->GetDefaultSphere();
	Vect min = MathTools::GetMin(next);
	Vect max = MathTools::GetMax(next);

	it++;
	for (it; it != list.end(); it++) {
		next = (*it)->GetDefaultSphere();
		min = MathTools::Minimize(min, MathTools::GetMin(next));
		max = MathTools::Maximize(max, MathTools::GetMax(next));
	}

	partition.Set(min, max);
}

const AABB& CollisionGroup::GetPartition()
{
	return partition;
}
