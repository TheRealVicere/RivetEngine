#include "OBB.h"

#include <algorithm>

#include "BSphere.h"
#include "Debugger.h"
#include "MathTools.h"
#include "Matrix.h"
#include "Model.h"

OBB::OBB() : CollisionBox() {}

OBB::OBB(const CollisionBox& other) :
	CollisionBox(other) {}

OBB& OBB::operator=(const CollisionBox& other)
{
	if (&other != this) {
		world = other.World();
		min.set(other.Min());
		max.set(other.Max());
		center.set(other.Center());
		halfDiag.set(other.HalfDiag());
		scaleFactor = other.ScaleFactor();
	}
	return *this;
}

void OBB::ComputeData(Model* mod, const Matrix& mat)
{
	if (MathTools::PointEquals(min, max)) {
		min = mod->getMinAABB();
		max = mod->getMaxAABB();
		halfDiag = (max - min) * 0.5f;
	}

	world = mat;
	center = (min + halfDiag) * world;
	scaleFactor = world.get(ROW_0).magSqr();
}

void OBB::DebugView(const Vect& col) const
{
	Debugger::ShowBox(*this, col);
}

bool OBB::Intersect(const Vect& p) const
{
	return MathTools::Intersect(p, *this);
}

bool OBB::Intersect(const CollisionVolume& other) const
{
	return other.Intersect(*this);
}

bool OBB::Intersect(const BSphere& other) const
{
	return MathTools::Intersect(other, *this);
}
