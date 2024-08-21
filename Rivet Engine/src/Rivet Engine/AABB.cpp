#include "AABB.h"

#include "BSphere.h"
#include "Debugger.h"
#include "MathTools.h"
#include "Matrix.h"
#include "Model.h"

AABB::AABB() : CollisionBox() {}

AABB::AABB(const CollisionBox& other) :
	CollisionBox(other) {}

AABB& AABB::operator=(const CollisionBox& other)
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

void AABB::ComputeData(Model* mod, const Matrix& mat)
{
	int vNum(mod->getVectNum());
	Vect* vArr(mod->getVectList());
	Vect current = vArr[0] * mat;

	min.set(current);
	max.set(current);

	for (int i = 1; i < vNum; i++) {
		current = vArr[i] * mat;
		min.set(MathTools::Minimize(min, current));
		max.set(MathTools::Maximize(max, current));
	}

	scaleFactor = mat.get(ROW_0).magSqr();
	halfDiag = (0.5f / scaleFactor) * (max - min);
	center = 0.5f * (max + min);
}

void AABB::DebugView(const Vect& col) const
{
	Debugger::ShowBox(*this, col);
}

bool AABB::Intersect(const Vect& p) const
{
	return MathTools::Intersect(p, *this);
}

bool AABB::Intersect(const CollisionVolume& other) const
{
	return other.Intersect(*this);
}

bool AABB::Intersect(const BSphere& other) const
{
	return MathTools::Intersect(other, *this);
}

void AABB::Set(const Vect& _min, const Vect& _max)
{
	min = _min;
	max = _max;
	scaleFactor = 1;
	halfDiag = 0.5f * (max - min);
	center = 0.5f * (max + min);
}
