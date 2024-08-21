#ifndef CollisionManager_H
#define CollisionManager_H

#include <list>
#include <vector>

#include "CollisionDispatch.h"
#include "CollisionTestPairCommand.h"
#include "CollisionTestTerrainCommand.h"

class CollisionGroup;
class Terrain;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	CollisionManager
///
/// \brief	Manager for collision processing.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class CollisionManager {
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	int ObjTypeID
	///
	/// \brief	Represents an object's type, used for downcasting with collision callbacks.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef int ObjTypeID;

	/// \brief	(Immutable) The default value for object IDs.
	static const ObjTypeID UNDEFINED = -1;

	CollisionManager();
	CollisionManager(const CollisionManager&) = delete;
	CollisionManager& operator=(const CollisionManager&) = delete;
	~CollisionManager();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void CollisionManager::ProcessCollisions();
	///
	/// \brief	Calculates collisions for each pair needing testing.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void ProcessCollisions();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	ObjTypeID CollisionManager::SetCollisionGroup(ObjTypeID id);
	///
	/// \brief	Sets the storage group for collision testing based on object type.
	///
	/// \param 	id	The object's type identifier.
	///
	/// \returns	The object's type identifier.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	ObjTypeID SetCollisionGroup(ObjTypeID id);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	CollisionGroup* CollisionManager::GetGroup(ObjTypeID id);
	///
	/// \brief	Returns the object's collision group.
	///
	/// \param 	id	The object's type identifier.
	///
	/// \returns	The object's collision group.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	CollisionGroup* GetGroup(ObjTypeID id);

private:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::vector<CollisionGroup*> GroupCollection
	///
	/// \brief	Defines an alias representing a collection of collision groups.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::vector<CollisionGroup*> GroupCollection;

	/// \brief	The collection of collision groups.
	GroupCollection groups;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::list<CollisionTestCommand*> TestCommandList
	///
	/// \brief	Defines an alias representing list of collision test commands.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::list<CollisionTestCommand*> TestCommandList;

	/// \brief	The list of collision test commands.
	TestCommandList testCommands;

	/// \brief	A placeholder for the next object type's identifier.
	static ObjTypeID nextID;

public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	template <typename C> ObjTypeID CollisionManager::GetTypeID()
	///
	/// \brief	Gets the object's type identifier.
	///
	/// \tparam	C	The object's actual type.
	///
	/// \returns	The object's type identifier.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	template <typename C>
	ObjTypeID GetTypeID() {
		static ObjTypeID id = nextID++;
		SetCollisionGroup(id);
		return id;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	template <typename C1, typename C2> void CollisionManager::SetCollisionPair()
	///
	/// \brief	Enables two types of objects to process collision with objects of each other's type.
	///
	/// \tparam	C1	The first object type.
	/// \tparam	C2	The second object type.
	/// 			
	/// \par Example:
	/// Say you have two objects of types Player and Enemy that you want to process collision for.
	/// Set up their collision like this:
	/// \code
	/// 	 SetCollisionPair<Player, Enemy>();
	/// \endcode
	/// Then, make sure to include corresponding functions for collision processing:
	/// \code
	/// 	 void Player::Collision(Enemy* e) { ... }
	/// 	 void Enemy::Collision(Player* p) { ... }
	/// \endcode
	/// Note that C1 and C2 are interchangeable and do not require separate function calls:
	/// \code
	/// 	 // These two do the same thing!
	/// 	 SetCollisionGroup<C1, C2>();
	/// 	 SetCollisionGroup<C2, C1>();
	/// \endcode
	/////////////////////////////////////////////////////////////////////////////////////////////////
	template <typename C1, typename C2>
	void SetCollisionPair() {
		CollisionGroup* g1 = groups[GetTypeID<C1>()];
		CollisionGroup* g2 = groups[GetTypeID<C2>()];
		CollisionDispatch<C1, C2>* dispatch = new CollisionDispatch<C1, C2>;
		testCommands.push_back(new CollisionTestPairCommand(g1, g2, dispatch));
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	template <typename C> void CollisionManager::SetCollisionSelf()
	///
	/// \brief	Enables objects of the given type to process collision with other objects of the same type.
	///
	/// \tparam	C	The object type requesting self-collision processing.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	template <typename C>
	void SetCollisionSelf() {
		CollisionGroup* g = groups[GetTypeID<C>()];
		CollisionDispatch<C, C>* dispatch = new CollisionDispatch<C, C>;
		testCommands.push_back(new CollisionTestCommand(g, dispatch));
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	template <typename C> void CollisionManager::SetCollisionTerrain()
	///
	/// \brief	Enables objects of the given type to process collision with terrain objects.
	///
	/// \tparam	C	The object type requesting terrain collision processing.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	template <typename C>
	void SetCollisionTerrain(Terrain* t) {
		CollisionGroup* g = groups[GetTypeID<C>()];
		testCommands.push_back(new CollisionTestTerrainCommand(g, t));
	}
};

#endif
