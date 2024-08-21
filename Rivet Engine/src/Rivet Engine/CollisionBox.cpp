#include "CollisionBox.h"

#include "MathTools.h"

CollisionBox::CollisionBox() :
	world(IDENTITY), min(0, 0, 0), max(0, 0, 0), center(0, 0, 0),
	scaleFactor(0) {}

CollisionBox::CollisionBox(const CollisionBox& other) :
	world(other.world), min(other.min), max(other.max), center(other.center),
	halfDiag(halfDiag), scaleFactor(other.scaleFactor) {}

CollisionBox& CollisionBox::operator=(const CollisionBox& other)
{
	if (&other != this) {
		world = other.world;
		min.set(other.min);
		max.set(other.max);
		center.set(other.center);
		halfDiag.set(other.halfDiag);
		scaleFactor = other.scaleFactor;
	}
	return *this;
}

const Vect& CollisionBox::Min() const
{
	return min;
}

const Vect& CollisionBox::Max() const
{
	return max;
}

const Vect& CollisionBox::HalfDiag() const
{
	return halfDiag;
}

const Vect& CollisionBox::Center() const
{
	return center;
}

const Matrix& CollisionBox::World() const
{
	return world;
}

const float CollisionBox::ScaleFactor() const
{
	return scaleFactor;
}

bool CollisionBox::Intersect(const CollisionBox& other) const
{
	return MathTools::Intersect(*this, other);
}
