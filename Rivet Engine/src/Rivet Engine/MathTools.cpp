#include "MathTools.h"

#include "DebugOut.h"

#include "Matrix.h"

const float MathTools::EPSILON = 0.00001f;

bool MathTools::FloatEquals(const float& a, const float& b)
{
	return fabs(a - b) < EPSILON;
}

bool MathTools::PointEquals(const Vect& a, const Vect& b) {
	return (FloatEquals(a.X(), b.X())
		&& FloatEquals(a.Y(), b.Y())
		&& FloatEquals(a.Z(), b.Z()));
}

const Vect MathTools::Minimize(const Vect& a, const Vect& b)
{
	float x = fmin(a.X(), b.X());
	float y = fmin(a.Y(), b.Y());
	float z = fmin(a.Z(), b.Z());
	return Vect(x, y, z);
}

const Vect MathTools::Maximize(const Vect& a, const Vect& b)
{
	float x = fmax(a.X(), b.X());
	float y = fmax(a.Y(), b.Y());
	float z = fmax(a.Z(), b.Z());
	return Vect(x, y, z);
}

const Vect MathTools::GetMin(const BSphere& s)
{
	float r = s.Radius();
	return (s.Center() - Vect(r, r, r));
}

const Vect MathTools::GetMax(const BSphere& s)
{
	float r = s.Radius();
	return (s.Center() + Vect(r, r, r));
}

bool MathTools::Intersect(const Vect& p, const CollisionVolume& v)
{
	return v.Intersect(p);
}

bool MathTools::Intersect(const Vect& p, const OBB& b)
{
	AABB bLocal(b);
	Vect pLocal(p * b.World().getInv());
	return Intersect(pLocal, bLocal);
}

bool MathTools::Intersect(const Vect& p, const AABB& b)
{
	Vect clamped = Clamp(p, b);
	return PointEquals(p, clamped);
}

bool MathTools::Intersect(const Vect& p, const BSphere& s)
{
	Vect diff = p - s.Center();
	return diff.mag() < s.Radius();
}

bool MathTools::Intersect(const CollisionVolume& a, const CollisionVolume& b)
{
	return a.Intersect(b);
}

bool MathTools::Intersect(const BSphere& a, const BSphere& b)
{
	Vect offset = a.Center() - b.Center();
	float mag2 = offset.dot(offset);
	float dist = a.Radius() + b.Radius();
	dist *= dist;
	return mag2 < dist;
}

bool MathTools::Intersect(const BSphere& s, const AABB& b)
{
	Vect center = Clamp(s.Center(), b);
	return Intersect(center, s);
}

bool MathTools::Intersect(const BSphere& s, const OBB& b)
{
	AABB bLocal(b);
	Vect testPoint = s.Center() * b.World().getInv();
	testPoint = Clamp(testPoint, bLocal);
	testPoint *= b.World();
	return Intersect(testPoint, s);
}

bool MathTools::Intersect(const CollisionBox& a, const CollisionBox& b)
{
	Vect s1(a.World().get(ROW_0));
	if (s1.magSqr() > EPSILON && !Overlap(a, b, s1)) return false;
	Vect u1(a.World().get(ROW_1));
	if (u1.magSqr() > EPSILON && !Overlap(a, b, u1)) return false;
	Vect f1(a.World().get(ROW_2));
	if (f1.magSqr() > EPSILON && !Overlap(a, b, f1)) return false;
	Vect s2(b.World().get(ROW_0));
	if (s2.magSqr() > EPSILON && !Overlap(a, b, s2)) return false;
	Vect u2(b.World().get(ROW_1));
	if (u2.magSqr() > EPSILON && !Overlap(a, b, u2)) return false;
	Vect f2(b.World().get(ROW_2));
	if (f2.magSqr() > EPSILON && !Overlap(a, b, f2)) return false;

	Vect next = s1.cross(s2);
	if (next.magSqr() > EPSILON && !Overlap(a, b, next)) return false;
	next = s1.cross(u2);
	if (next.magSqr() > EPSILON && !Overlap(a, b, next)) return false;
	next = s1.cross(f2);
	if (next.magSqr() > EPSILON && !Overlap(a, b, next)) return false;
	next = u1.cross(s2);
	if (next.magSqr() > EPSILON && !Overlap(a, b, next)) return false;
	next = u1.cross(u2);
	if (next.magSqr() > EPSILON && !Overlap(a, b, next)) return false;
	next = u1.cross(f2);
	if (next.magSqr() > EPSILON && !Overlap(a, b, next)) return false;
	next = f1.cross(s2);
	if (next.magSqr() > EPSILON && !Overlap(a, b, next)) return false;
	next = f1.cross(u2);
	if (next.magSqr() > EPSILON && !Overlap(a, b, next)) return false;
	next = f1.cross(f2);
	return (next.magSqr() <= EPSILON || Overlap(a, b, next));
}

const Vect MathTools::Clamp(const Vect& p, const AABB& b)
{
	Vect start(b.Min());
	Vect end(b.Max());
	float x = Clamp(start.X(), end.X(), p.X());
	float y = Clamp(start.Y(), end.Y(), p.Y());
	float z = Clamp(start.Z(), end.Z(), p.Z());
	Vect clamped(x, y, z);
	return clamped;
}

const float MathTools::Clamp(const float start, const float end, const float val)
{
	if (val < start) return start;
	if (val > end) return end;
	return val;
}

const float MathTools::MaxProj(const CollisionBox& b, const Vect& v)
{
	Vect w = v * b.World().getInv();
	Vect hd = b.HalfDiag();
	float x = w.X() * hd.X();
	float y = w.Y() * hd.Y();
	float z = w.Z() * hd.Z();
	float pMax = (fabs(x) + fabs(y) + fabs(z)) / v.mag();
	return pMax * b.ScaleFactor();
}

bool MathTools::Overlap(const float start1, const float end1,
	const float start2, const float end2)
{
	return (end1 >= start2 && end2 >= start1);
}

bool MathTools::Overlap(const CollisionBox& a, const CollisionBox& b, const Vect& v)
{
	Vect c = a.Center() - b.Center();
	float d = fabs(c.dot(v)) / v.mag();

	float p1 = MaxProj(a, v);
	float p2 = MaxProj(b, v);
	return (d <= p1 + p2);
}

float MathTools::RandomAngle()
{
	float angle = (float) (rand() % 360);
	angle *= MATH_PI_180;
	return angle;
}
