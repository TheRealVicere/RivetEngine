#ifndef UpdateAttorney_H
#define UpdateAttorney_H

#include "CollisionComponent.h"

class CollisionAttorney {
private:
	friend class CollisionGroup;
	friend class CollisionTestCommand;
	friend class CollisionTestPairCommand;
	friend class CollisionTestTerrainCommand;

	static CollisionGroup::ColliderListRef GetColliderListRef(CollisionComponent* c) {
		return c->GetColliderListRef();
	}

	static void CollisionTerrain(CollisionComponent* c, Terrain* t) {
		c->Collision(t);
	}
};

#endif
