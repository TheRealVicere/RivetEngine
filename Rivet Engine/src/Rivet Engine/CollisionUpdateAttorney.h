#ifndef CollisionUpdateAttorney_H
#define CollisionUpdateAttorney_H

#include "CollisionComponent.h"

class CollisionUpdateAttorney {
	friend class GameObject;

	static void SetCollider(CollisionComponent* c, Model* mod,
		CollisionComponent::Volume type) {
		c->SetCollider(mod, type);
	}

	static void UpdateCollisionData(CollisionComponent* c, const Matrix& m) {
		c->UpdateCollisionData(m);
	}

	template <typename C>
	static void SetCollisionGroup(CollisionComponent* c) {
		c->SetCollisionGroup<C>();
	}
};

#endif
