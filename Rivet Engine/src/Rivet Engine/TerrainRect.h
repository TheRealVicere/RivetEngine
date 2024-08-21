#ifndef TerrainRect_H
#define TerrainRect_H

#include <utility>

#include "AABB.h"
#include "TerrainRectIterator.h"

class Terrain;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	TerrainRect
///
/// \brief	A rectangle of terrain cells defined by a minimum and maximum point.
///
/// \author	Mike Piunti
/// \date	05/17/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class TerrainRect {
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::pair<int, int> Coords
	///
	/// \brief	Defines an alias representing the (i, j) coordinates of each cell.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::pair<int, int> Coords;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	TerrainRect::TerrainRect(Terrain* t, const int iMin, const int iMax, const int jMin, const int jMax);
	///
	/// \brief	Constructor. Defines a rectangular area over the given terrain using the given minima and maxima.
	///
	/// \param	t   	The terrain whose cells to process.
	/// \param	iMin	The minimum i coordinate on the rectangle.
	/// \param	iMax	The maximum i coordinate on the rectangle.
	/// \param	jMin	The minimum j coordinate on the rectangle.
	/// \param	jMax	The maximum j coordinate on the rectangle.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	TerrainRect(Terrain* t, const int iMin, const int iMax, const int jMin,
		const int jMax);

	TerrainRect() = delete;
	TerrainRect(const TerrainRect& other);
	TerrainRect& operator=(const TerrainRect& other);
	~TerrainRect() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	TerrainRect& TerrainRect::operator++();
	///
	/// \brief	Increment operator. Moves to the next cell in the rectangle.
	///
	/// \returns	This object with an incremented counter.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	TerrainRect& operator++();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	friend bool TerrainRect::operator==(const TerrainRect& a, const TerrainRect& b);
	///
	/// \brief	Equality operator.
	///
	/// \param 	a	The first instance to compare.
	/// \param 	b	The second instance to compare.
	///
	/// \returns	True if the instances share the same data.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	friend bool operator==(const TerrainRect& a, const TerrainRect& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	friend bool TerrainRect::operator!=(const TerrainRect& a, const TerrainRect& b);
	///
	/// \brief	Inequality operator.
	///
	/// \param 	a	The first instance to compare.
	/// \param 	b	The second instance to compare.
	///
	/// \returns	True if the instances have at least one differing data member.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	friend bool operator!=(const TerrainRect& a, const TerrainRect& b);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	TerrainRectIterator TerrainRect::begin();
	///
	/// \brief	Returns an iterator representing the minimum point on the rectangle.
	///
	/// \returns	The iterator.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	TerrainRectIterator begin();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	TerrainRectIterator TerrainRect::end();
	///
	/// \brief	Returns an iterator representing the maximum point on the rectangle.
	///
	/// \returns	The iterator.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	TerrainRectIterator end();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	const AABB& TerrainRect::getBox() const;
	///
	/// \brief	Gets the bounding box of the current cell.
	///
	/// \returns	The bounding box.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	const AABB& getBox() const;

private:
	/// \brief	The terrain this rectangle covers.
	Terrain* terrain;

	/// \brief	The minimum (i, j) coordinates of this rectangle.
	Coords min;

	/// \brief	The maximum (i, j) coordinates of this rectangle.
	Coords max;

	/// \brief	The (i, j) coordinates of the current position in this rectangle.
	Coords current;
};

#endif
