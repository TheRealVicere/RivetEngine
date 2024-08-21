#ifndef CollisionComponent_H
#define CollisionComponent_H

#include "BSphere.h"
#include "CollisionGroup.h"
#include "CollisionManager.h"
#include "CollisionVolume.h"
#include "Component.h"
#include "ICollisionCallback.h"
#include "SceneAttorney.h"

class Command;
class Matrix;
class Model;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	CollisionComponent
///
/// \brief	Adds collision processing to game objects.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class CollisionComponent : public Component, public ICollisionCallback {
public:
	friend class CollisionAttorney;
	friend class CollisionUpdateAttorney;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \enum	Volume
	///
	/// \brief	Values that represent cheap collision volumes.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	enum class Volume {
		BSphere, AABB, OBB
	};

	CollisionComponent();
	CollisionComponent(const CollisionComponent&) = delete;
	CollisionComponent& operator=(const CollisionComponent&) = delete;
	virtual ~CollisionComponent();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn const BSphere& CollisionComponent::GetDefaultSphere();
	///
	/// \brief	Returns the default collision sphere.
	///
	/// \returns	The default sphere.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	const BSphere& GetDefaultSphere();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	const CollisionVolume& CollisionComponent::GetVolume();
	///
	/// \brief	Gets the object's collision volume. Used for collision processing and debugging.
	///
	/// \returns	The collision volume.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	const CollisionVolume& GetVolume();

protected:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void CollisionComponent::SetCollider(Model* model);
	///
	/// \brief	Sets the model and volume to use for collision processing.
	///
	/// \param	model	The collider model.
	/// \param	type	The desired type of collision volume to use for processing.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetCollider(Model* model, Volume type);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void CollisionComponent::UpdateCollisionData(const Matrix& m);
	///
	/// \brief	Updates the collision data using the given world matrix.
	/// 		Used to correctly calculate collision based on objects' world matrices.
	///
	/// \param 	m	The world matrix of the object's GraphicsObject.
	/// 			
	/// \par Example:
	/// Users should normally pass the world matrix of the GraphicsObject in question, like as follows.
	/// \code
	/// 	Matrix world = [...]; // Define world matrix
	///		graphicsObject->SetWorld(world);
	///		UpdateCollisionData(world);
	///	\endcode
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void UpdateCollisionData(const Matrix& m);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	template <typename C> void CollisionComponent::SetCollisionGroup()
	///
	/// \brief	Sets the object's collision group based on its type.
	///
	/// \tparam	C	The object's type.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	template <typename C>
	void SetCollisionGroup() {
		id = SceneAttorney::CollisionRegistry::GetCollisionManager()->
			GetTypeID<C>();
		SceneAttorney::CollisionRegistry::GetCollisionManager()->
			SetCollisionGroup(id);
	}

private:
	/// \brief	The object's type identifier. Defaults to -1, meaning no identifier.
	CollisionManager::ObjTypeID id = CollisionManager::UNDEFINED;

	/// \brief	A reference to the object's location on the collision group's list.
	CollisionGroup::ColliderListRef listRef;

	/// \brief	A bounding volume completely enveloping the object, used for collision detection.
	CollisionVolume* volume;

	/// \brief	The default bounding sphere used for efficient collision detection.
	BSphere defaultSphere;

	/// \brief	The collider model.
	Model* collider;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void CollisionComponent::OnRegistration();
	///
	/// \brief	Requests collision registration.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void OnRegistration();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void CollisionComponent::OnDeregistration();
	///
	/// \brief	Requests collision deregistration.
	/////////////////////////////////////////////////////////////////////////////////////////////////
	void OnDeregistration();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	CollisionGroup::ColliderListRef CollisionComponent::GetColliderListRef();
	///
	/// \brief	Gets a reference to the object's location on the list of collidables for efficient deletion.
	///
	/// \returns	The collidable list reference.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	CollisionGroup::ColliderListRef GetColliderListRef();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void Collidable::Collision(Terrain* t)
	///
	/// \brief	A callback for terrain collision processing.
	/// 		Derived classes MUST implement this if they need to collide with the terrain.
	/// 		
	/// \param	t	The colliding terrain.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Collision(Terrain* t) { UNREFERENCED_PARAMETER(t); }
};

#endif
