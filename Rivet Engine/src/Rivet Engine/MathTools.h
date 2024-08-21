#ifndef MathTools_H
#define MathTools_H

#include "AABB.h"
#include "BSphere.h"
#include "OBB.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	MathTools
///
/// \brief	A series of functions used for complex mathematical computations.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class MathTools {
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static bool MathTools::FloatEquals(const float& a, const float& b);
	///
	/// \brief	Checks if two floating-point numbers are close enough to be considered equal.
	/// 		This function was written as a solution to floating-point arithmetic inaccuracies.
	///
	/// \param 	a	The first float to compare.
	/// \param 	b	The second float to compare.
	///
	/// \returns	True if the floats are equal (enough), false if not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool FloatEquals(const float& a, const float& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static bool MathTools::PointEquals(const float& a, const float& b);
	///
	/// \brief	Checks if two 3D points are close enough to be considered equal.
	/// 		This function was written as a solution to floating-point arithmetic inaccuracies.
	///
	/// \param 	a	The first point to compare.
	/// \param 	b	The second point to compare.
	///
	/// \returns	True if the points are equal (enough), false if not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool PointEquals(const Vect& a, const Vect& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static const Vect MathTools::Minimize(const Vect& a, const Vect& b);
	///
	/// \brief	Returns the minimum point for an axis-aligned box holding the given points.
	///
	/// \param 	a	The first point to consider.
	/// \param 	b	The second point to consider.
	///
	/// \returns	The minimum point.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static const Vect Minimize(const Vect& a, const Vect& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static const Vect MathTools::Maximize(const Vect& a, const Vect& b);
	///
	/// \brief	Returns the maximum point for an axis-aligned box holding the given points.
	///
	/// \param 	a	The first point to consider.
	/// \param 	b	The second point to consider.
	///
	/// \returns	The maximum point.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static const Vect Maximize(const Vect& a, const Vect& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static const Vect MathTools::GetMin(const BSphere& s);
	///
	/// \brief	Finds the minimum point of a cube holding the given bounding sphere.
	///
	/// \param 	s	The bounding sphere to consider.
	///
	/// \returns	The minimum point of the surrounding cube.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static const Vect GetMin(const BSphere& s);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static const Vect MathTools::GetMax(const BSphere& s);
	///
	/// \brief	Finds the maximum point of a cube holding the given bounding sphere.
	///
	/// \param 	s	The bounding sphere to consider.
	///
	/// \returns	The maximum point of the surrounding cube.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static const Vect GetMax(const BSphere& s);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static bool MathTools::Intersect(const Vect& p, const CollisionVolume& v);
	///
	/// \brief	Checks if a point lies within a collision volume.
	///
	/// \param 	p	The point to test for intersection.
	/// \param 	v	The collision volume to test for intersection.
	///
	/// \returns	True if the point lies within the volume, false if not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool Intersect(const Vect& p, const CollisionVolume& v);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static bool MathTools::Intersect(const Vect& p, const OBB& b);
	///
	/// \brief	Checks if a point lies within an OBB.
	///
	/// \param 	p	The point to test for intersection.
	/// \param 	b	The OBB to test for intersection.
	///
	/// \returns	True if the point lies within the OBB, false if not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool Intersect(const Vect& p, const OBB& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static bool MathTools::Intersect(const Vect& p, const AABB& b);
	///
	/// \brief	Checks if a point lies within an AABB.
	///
	/// \param 	p	The point to test for intersection.
	/// \param 	b	The AABB to test for intersection.
	///
	/// \returns	True if the point lies within the AABB, false if not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool Intersect(const Vect& p, const AABB& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static bool MathTools::Intersect(const Vect& p, const BSphere& s);
	///
	/// \brief	Checks if a point lies within a bounding sphere.
	///
	/// \param 	p	The point to test for intersection.
	/// \param 	s	The bounding sphere to process.
	///
	/// \returns	True if the point lies within the sphere, false if not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool Intersect(const Vect& p, const BSphere& s);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static bool MathTools::Intersect(const CollisionVolume& a, const CollisionVolume& b);
	///
	/// \brief	Returns whether two collision volumes intersect. Used for collision processing.
	///
	/// \param 	a	The first volume to consider.
	/// \param 	b	The second volume to consider.
	///
	/// \returns	True if the volumes intersect, false if they do not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool Intersect(const CollisionVolume& a, const CollisionVolume& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static bool MathTools::Intersect(const BSphere& a, const BSphere& b);
	///
	/// \brief	Returns whether two bounding spheres intersect. Used for collision processing.
	///
	/// \param 	a	The first bounding sphere to consider.
	/// \param 	b	The second bounding sphere to consider.
	///
	/// \returns	True if the spheres intersect, false if they do not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool Intersect(const BSphere& a, const BSphere& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static bool MathTools::Intersect(const BSphere& s, const AABB& b);
	///
	/// \brief	Returns whether a bounding sphere intersects an AABB. Used for collision processing.
	///
	/// \param 	s	The bounding sphere to consider.
	/// \param 	b	The AABB to consider.
	///
	/// \returns	True if the volumes intersect, false if they do not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool Intersect(const BSphere& s, const AABB& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static bool MathTools::Intersect(const BSphere& s, const OBB& b);
	///
	/// \brief	Returns whether a bounding sphere intersects an OBB. Used for collision processing.
	///
	/// \param 	s	The bounding sphere to consider.
	/// \param 	b	The OBB to consider.
	///
	/// \returns	True if the volumes intersect, false if they do not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool Intersect(const BSphere& s, const OBB& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static bool MathTools::Intersect(const CollisionBox& a, const CollisionBox& b);
	///
	/// \brief	Returns whether two collision boxes intersect. Used for collision processing.
	///
	/// \param 	a	The first box to consider.
	/// \param 	b	The second box to consider.
	///
	/// \returns	True if the boxes intersect, false if they do not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool Intersect(const CollisionBox& a, const CollisionBox& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static const Vect& MathTools::Clamp(const Vect& p, const AABB& b);
	///
	/// \brief	Clamp the given point to lie within an AABB.
	///
	/// \param 	p	The point to clamp.
	/// \param 	b	The AABB to clamp the point to.
	///
	/// \returns	The clamped point.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static const Vect Clamp(const Vect& p, const AABB& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static const float MathTools::Clamp(const float start, const float end, const float val);
	///
	/// \brief	Clamp the given value between two bounds.
	///
	/// \param 	start	The lower bound for clamping.
	/// \param 	end  	The upper bound for clamping.
	/// \param 	val  	The value to clamp.
	///
	/// \returns	The clamped value.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static const float Clamp(const float start, const float end, const float val);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static const float MathTools::MaxProj(const CollisionBox& b, const Vect& v);
	///
	/// \brief	Returns the maximum projection of the given collision box along the given axis.
	///
	/// \param 	b	The box to project.
	/// \param 	v	The axis of projection.
	///
	/// \returns	The max projection of the box along the axis.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static const float MaxProj(const CollisionBox& b, const Vect& v);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static const bool MathTools::Overlap(const float start1, const float end1, const float start2, const float end2);
	///
	/// \brief	Checks if two ranges overlap.
	///
	/// \param 	start1	The start of the first range.
	/// \param 	end1  	The end of the first range.
	/// \param 	start2	The start of the second range.
	/// \param 	end2  	The end of the second range.
	///
	/// \returns	True if the ranges overlap, false if not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool Overlap(const float start1, const float end1,
		const float start2, const float end2);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static bool MathTools::Overlap(const CollisionBox& a, const CollisionBox& b, const Vect& v);
	///
	/// \brief	Checks if two collision boxes overlap along the given axis.
	///
	/// \param 	a	The first box.
	/// \param 	b	The second box.
	/// \param 	v	The overlap axis.
	///
	/// \returns	True if the boxes overlap along the axis, false if not.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static bool Overlap(const CollisionBox& a, const CollisionBox& b,
		const Vect& v);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static float MathTools::RandomAngle();
	///
	/// \brief	Returns a random angle, in radians.
	///
	/// \returns	The random angle.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static float RandomAngle();

	/// \brief	(Immutable) The epsilon value used for float comparisons.
	static const float EPSILON;
};

#endif
