#ifndef CollisionVolume_H
#define CollisionVolume_H

class BSphere;
class CollisionBox;
class Matrix;
class Model;
class Vect;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	CollisionVolume
///
/// \brief	A simple volume used for collision testing.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class CollisionVolume {
public:
	CollisionVolume() = default;
	CollisionVolume(const CollisionVolume&) = delete;
	CollisionVolume& operator=(const CollisionVolume&) = delete;
	virtual ~CollisionVolume() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void CollisionVolume::ComputeData(Model* mod, const Matrix& mat) = 0;
	///
	/// \brief	Computes the data needed for proper volume placement.
	///
	/// \param	mod	The object's collision model.
	/// \param	mat	The object's world matrix.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void ComputeData(Model* mod, const Matrix& mat) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual bool CollisionVolume::Intersect(const Vect& p) const = 0;
	///
	/// \brief	Checks if a point lies within this collision volume.
	///
	/// \param 	p	The point to test for intersection.
	///
	/// \returns	True if this volume contains the point, false if not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual bool Intersect(const Vect& p) const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual bool CollisionVolume::Intersect(const CollisionVolume& other) const = 0;
	///
	/// \brief	Tests whether this volume intersects with the other.
	///
	/// \param 	other	The other collision volume to test for intersection.
	///
	/// \returns	True if the volumes intersect, false otherwise.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual bool Intersect(const CollisionVolume& other) const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual bool CollisionVolume::Intersect(const BSphere& other) const = 0;
	///
	/// \brief	A callback to calculate whether a bounding sphere intersects with this volume.
	///
	/// \param 	other	The bounding sphere to test for intersection.
	///
	/// \returns	True if the volumes intersect, false otherwise.
	/////////////////////////////////////////////////////////////////////////////////////////////////
	virtual bool Intersect(const BSphere& other) const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual bool CollisionVolume::Intersect(const CollisionBox& other) const = 0;
	///
	/// \brief	A callback to calculate whether a collision box intersects with this volume.
	///
	/// \param 	other	The box to test for intersection.
	///
	/// \returns	True if the volumes intersect, false otherwise.
	/////////////////////////////////////////////////////////////////////////////////////////////////
	virtual bool Intersect(const CollisionBox& other) const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void CollisionVolume::DebugView(const Vect& col);
	///
	/// \brief	Renders the volume to the display for debugging purposes.
	///
	/// \param 	col	The color used to render the volume.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void DebugView(const Vect& col) const = 0;
};

#endif
