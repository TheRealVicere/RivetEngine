#ifndef CollisionDispatchBase_H
#define CollisionDispatchBase_H

class ICollisionCallback;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	CollisionDispatchBase
///
/// \brief	A dispatch used to process collision callbacks.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class CollisionDispatchBase {
public:
	CollisionDispatchBase() = default;
	CollisionDispatchBase(const CollisionDispatchBase&) = delete;
	CollisionDispatchBase& operator=(const CollisionDispatchBase&) = delete;
	virtual ~CollisionDispatchBase() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void CollisionDispatchBase::ProcessCallbacks(ICollisionCallback* c1, ICollisionCallback* c2) = 0;
	///
	/// \brief	Calls each object's collision function using the other as the respective argument.
	///
	/// \param	c1	The first colliding object.
	/// \param	c2	The second colliding object.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void ProcessCallbacks(ICollisionCallback* c1, ICollisionCallback* c2) = 0;
};

#endif
