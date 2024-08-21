#include "CollisionComponent.h"

#include "AABB.h"
#include "OBB.h"

CollisionComponent::CollisionComponent() :
	volume(nullptr) {}

CollisionComponent::~CollisionComponent()
{
	if (volume) delete volume;
}

CollisionGroup::ColliderListRef CollisionComponent::GetColliderListRef()
{
	return listRef;
}

void CollisionComponent::SetCollider(Model* model, CollisionComponent::Volume type)
{
	assert(model != nullptr);
	collider = model;

	switch (type) {
	case Volume::BSphere:
		volume = new BSphere;
		break;
	case Volume::AABB:
		volume = new AABB;
		break;
	case Volume::OBB:
		volume = new OBB;
		break;
	default:
		assert(("Invalid collision volume type!", false));
	}
}

const BSphere& CollisionComponent::GetDefaultSphere()
{
	return defaultSphere;
}

const CollisionVolume& CollisionComponent::GetVolume()
{
	return *volume;
}

void CollisionComponent::UpdateCollisionData(const Matrix& m)
{
	defaultSphere.ComputeData(collider, m);
	volume->ComputeData(collider, m);
}

void CollisionComponent::OnRegistration()
{
	listRef = SceneAttorney::CollisionRegistry::GetCollisionManager()->
		GetGroup(id)->Register(this);
}

void CollisionComponent::OnDeregistration()
{
	SceneAttorney::CollisionRegistry::GetCollisionManager()->
		GetGroup(id)->Deregister(this);
}
