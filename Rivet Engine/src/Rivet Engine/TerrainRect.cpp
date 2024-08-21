#include "TerrainRect.h"

#include "Terrain.h"

TerrainRect::TerrainRect(Terrain* t, const int iMin, const int iMax,
	const int jMin, const int jMax) :
	terrain(t), min(iMin, jMin), max(iMax + 1, jMax), current(min) {}

TerrainRect::TerrainRect(const TerrainRect& other) :
	terrain(other.terrain), min(other.min),	max(other.max),
	current(other.current) {}

TerrainRect& TerrainRect::operator=(const TerrainRect& other)
{
	if (&other != this) {
		terrain = other.terrain;
		min = other.min;
		max = other.max;
		current = other.current;
	}
	return *this;
}

TerrainRect& TerrainRect::operator++()
{
	if (current.second + 1 > max.second) {
		current.first++;
		current.second = min.second;
	} else current.second++;

	return *this;
}

TerrainRectIterator TerrainRect::begin()
{
	TerrainRect temp(*this);
	temp.current = temp.min;
	return TerrainRectIterator(&temp);
}

TerrainRectIterator TerrainRect::end()
{
	TerrainRect temp(*this);
	temp.current = temp.max;
	return TerrainRectIterator(&temp);
}

const AABB& TerrainRect::getBox() const
{
	return terrain->GetBoxAt(current.first, current.second);
}

bool operator==(const TerrainRect& a, const TerrainRect& b)
{
	if (a.terrain != b.terrain) return false;
	if (a.min != b.min) return false;
	if (a.max != b.max) return false;
	if (a.current != b.current) return false;
	return true;
}

bool operator!=(const TerrainRect& a, const TerrainRect& b)
{
	return !(a == b);
}
