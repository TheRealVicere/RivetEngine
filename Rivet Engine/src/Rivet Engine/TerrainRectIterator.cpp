#include "TerrainRectIterator.h"

#include "TerrainRect.h"

TerrainRectIterator::TerrainRectIterator(TerrainRect* r) :
	rect(new TerrainRect(*r)) {}

TerrainRectIterator::TerrainRectIterator(const TerrainRectIterator& other)
{
	*rect = *(other.rect);
}

TerrainRectIterator& TerrainRectIterator::operator=(const TerrainRectIterator& other)
{
	if (&other != this) *rect = *(other.rect);
	return *this;
}

TerrainRectIterator::~TerrainRectIterator()
{
	delete rect;
}

TerrainRectIterator& TerrainRectIterator::operator++()
{
	++(*rect);
	return *this;
}

TerrainRect& TerrainRectIterator::operator*() const
{
	return *rect;
}

TerrainRect* TerrainRectIterator::operator->() const
{
	return rect;
}

bool operator==(const TerrainRectIterator& a, const TerrainRectIterator& b)
{
	return (*a == *b);
}

bool operator!=(const TerrainRectIterator& a, const TerrainRectIterator& b)
{
	return (*a != *b);
}
