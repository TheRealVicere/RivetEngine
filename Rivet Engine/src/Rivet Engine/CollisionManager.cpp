#include "CollisionManager.h"

#include "CollisionGroup.h"

CollisionManager::ObjTypeID CollisionManager::nextID = 0;

CollisionManager::CollisionManager() :
	groups(GroupCollection(50, nullptr)) {}

CollisionManager::~CollisionManager()
{
	for (ObjTypeID i = 0; i < nextID; i++)
		delete groups.at(i);
	groups.clear();
	for (TestCommandList::iterator it = testCommands.begin();
		it != testCommands.end(); it++)
		delete *it;
	testCommands.clear();
}

void CollisionManager::ProcessCollisions()
{
	for (CollisionGroup* g : groups)
		if (g) g->UpdateGroupPartition();

	for (TestCommandList::iterator it = testCommands.begin();
		it != testCommands.end(); it++)
		(*it)->Execute();
}

CollisionManager::ObjTypeID CollisionManager::SetCollisionGroup(ObjTypeID id)
{
	if (groups[id] == nullptr)
		groups[id] = new CollisionGroup;
	return id;
}

CollisionGroup* CollisionManager::GetGroup(ObjTypeID id)
{
	return groups[id];
}
