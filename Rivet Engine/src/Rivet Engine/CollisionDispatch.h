#ifndef CollisionDispatch_H
#define CollisionDispatch_H

#include "CollisionDispatchBase.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	CollisionDispatch
///
/// \brief	A dispatch used to process collision callbacks for specific object types.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename C1, typename C2>
class CollisionDispatch : public CollisionDispatchBase {
public:
	CollisionDispatch() = default;
	CollisionDispatch(const CollisionDispatch&) = delete;
	CollisionDispatch& operator=(const CollisionDispatch&) = delete;
	~CollisionDispatch() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void CollisionDispatch::ProcessCallbacks(ICollisionCallback* c1, ICollisionCallback* c2) = 0;
	///
	/// \brief	Downcasts each object to the proper type, then calls each object's collision function
	/// 		using the other as the respective argument.
	///
	/// \param	c1	The first colliding object.
	/// \param	c2	The second colliding object.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void ProcessCallbacks(ICollisionCallback* c1, ICollisionCallback* c2) {
		C1* col1 = static_cast<C1*>(c1);
		C2* col2 = static_cast<C2*>(c2);

		col1->Collision(col2);
		col2->Collision(col1);
	}
};

#endif
