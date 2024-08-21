#include "BSphere.h"

#include "CollisionBox.h"
#include "Debugger.h"
#include "MathTools.h"
#include "Matrix.h"
#include "Model.h"

BSphere::BSphere() :
	center(0, 0, 0), radius(-1) {}

BSphere::BSphere(const BSphere& other) :
	center(other.center), radius (other.radius) {}

BSphere& BSphere::operator=(const BSphere& other)
{
	if (&other != this) {
		center = other.center;
		radius = other.radius;
	}
	return *this;
}

void BSphere::ComputeData(Model* mod, const Matrix& mat)
{
	center = mod->getCenter() * mat;
	radius = mod->getRadius() * mat.get(ROW_0).mag();
}

void BSphere::DebugView(const Vect& col) const
{
	Debugger::ShowBSphere(*this, col);
}

bool BSphere::Intersect(const Vect& p) const
{
	return MathTools::Intersect(p, *this);
}

bool BSphere::Intersect(const CollisionVolume& other) const
{
	return other.Intersect(*this);
}

bool BSphere::Intersect(const BSphere& other) const
{
	return MathTools::Intersect(*this, other);
}

bool BSphere::Intersect(const CollisionBox& other) const
{
	return other.Intersect(*this);
}

const float BSphere::Radius() const
{
	return radius;
}

const Vect& BSphere::Center() const
{
	return center;
}
