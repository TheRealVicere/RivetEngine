#ifndef ICollisionCallback_H
#define ICollisionCallback_H

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	ICollisionCallback
///
/// \brief	A callback to perform the duties of a collision component.
/// 		User-defined derived classes should inherit from CollisionComponent instead of this.
///
/// \author	Mike Piunti
/// \date	05/03/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class ICollisionCallback {
public:
	ICollisionCallback() = default;
	ICollisionCallback(const ICollisionCallback&) = delete;
	ICollisionCallback& operator=(const ICollisionCallback&) = delete;
	virtual ~ICollisionCallback() = default;
};

#endif
