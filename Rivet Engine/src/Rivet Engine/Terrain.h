#ifndef Terrain_H
#define Terrain_H

#include <list>

#include "Matrix.h"
#include "BSphere.h"

class AABB;
class Collidable;
class GraphicsObject_TextureFlat;
class GraphicsObject_WireframeConstantColor;
class Model;
class TerrainRect;
class Texture;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	Terrain
///
/// \brief	A surface that uses collision to orient objects travelling on it.
///
/// \author	Mike Piunti
/// \date	05/01/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class Terrain
{
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Terrain::Terrain(const char* heightmapFile, Texture* tex, float len, float maxheight, float ytrans, int RepeatU, int RepeatV);
	///
	/// \brief	Constructor. Creates a new terrain using the given files and data.
	///
	/// \param 	heightmapFile	The image file to use as a height map.
	/// \param 	tex			 	The texture for the terrain model.
	/// \param 	len			 	The length of the terrain, in AZUL units.
	/// \param 	maxheight		The height of the terrain model.
	/// \param 	ytrans		 	The Y offset used to place the terrain.
	/// \param 	RepeatU		 	The number of times to use the texture's UV coordinates along the U axis.
	/// \param 	RepeatV		 	The number of times to use the texture's UV coordinates along the V axis.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Terrain(const char* heightmapFile, Texture* tex, float len,	float maxheight,
		float ytrans, int RepeatU, int RepeatV);

	Terrain() = delete;
	Terrain(const Terrain&) = delete;
	Terrain(Terrain&&) = delete;
	virtual ~Terrain();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void Terrain::Render();
	///
	/// \brief	Renders this object to the display.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Render();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void Terrain::ShowAllColliders();
	///
	/// \brief	Shows the collision volume for every cell in the terrain.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void ShowAllColliders();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	const AABB& Terrain::GetBoxAt(const int i, const int j);
	///
	/// \brief	Returns the AABB at the given (i, j) coordinates.
	///
	/// \param 	i	The cell's row.
	/// \param 	j	The cell's column.
	///
	/// \returns	The cell at (i, j).
	////////////////////////////////////////////////////////////////////////////////////////////////////
	const AABB& GetBoxAt(const int i, const int j);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	const Vect Terrain::GetPointBelow(const Vect& point);
	///
	/// \brief	Returns the point on the terrain below the given point.
	///
	/// \param 	point	The original point.
	///
	/// \returns	The point on the terrain below the original point, or the original if not above the terrain.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	const Vect GetPointBelow(const Vect& point);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	const Vect Terrain::GetNormBelow(const Vect& point);
	///
	/// \brief	Returns the normal vector of the terrain at the point below the given point.
	///
	/// \param 	point	The point to consider.
	///
	/// \returns	The terrain's normal vector below the point, or the zero vector if not above the terrain.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	const Vect GetNormBelow(const Vect& point);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	const int Terrain::GetTriBelow(const Vect& point);
	///
	/// \brief	Returns the triangle below the given point.
	///
	/// \param 	point	The point to consider.
	///
	/// \returns	The index of the model triangle below the point.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	const int GetTriBelow(const Vect& point);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	const int Terrain::GetCellBelow(const Vect& point);
	///
	/// \brief	Returns the cell below the given point.
	///
	/// \param 	point	The point to consider.
	///
	/// \returns	The index of the terrain cell below the point.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	const int GetCellBelow(const Vect& point);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	const CellList Terrain::GetCellsBelow(const BSphere& sphere);
	///
	/// \brief	Returns the cell below the given bounding sphere.
	///
	/// \param 	sphere	The sphere to consider.
	///
	/// \returns	A list of indices of the terrain cells below the sphere.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	TerrainRect GetCellsBelow(const BSphere& sphere);

private:
	/// \brief	The terrain as a graphics object.
	GraphicsObject_TextureFlat* terrain;

	/// \brief	A wireframe version of the terrain.
	GraphicsObject_WireframeConstantColor* wireframe;

	/// \brief	The terrain model.
	Model* terrainMod;

	/// \brief	A pointer to the array of collision boxes.
	AABB* boxes;

	/// \brief	A pointer to the array of the model vertices' normal vectors.
	Vect* norms;

	/// \brief	The length of one side of the terrain.
	float sideLen;

	/// \brief	The side length of each cell.
	float cellLen;

	/// \brief	The number of model vertices along each horizontal dimension of the terrain.
	int sideVerts;

	/// \brief	The number of cells along each horizontal dimension of the terrain.
	int sideCells;

	/// \brief	The total number of cells in the terrain.
	int cellCount;

	/// \brief	(Immutable) The maximum value for a color component (ie. red).
	static const float MAX_RVAL;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void Terrain::SetAABBs();
	///
	/// \brief	A helper method which sets the collision volume for every cell in the terrain.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetAABBs();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	const int Terrain::VertIndex(const int i, const int j);
	///
	/// \brief	Returns the index of a vertex used to make the model, based on its grid position.
	///
	/// \param 	i	The vertex's forward index.
	/// \param 	j	The vertex's side index.
	///
	/// \returns	The vertex's linear index.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	const int VertIndex(const int i, const int j);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	const int Terrain::TriIndex(const int i, const int j);
	///
	/// \brief	Returns the index of a cell's left triangle, based on the grid position of the cell.
	///
	/// \param 	i	The cell's forward index.
	/// \param 	j	The cell's side index.
	///
	/// \returns	The left triangle's linear index.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	const int TriIndex(const int i, const int j);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	const int Terrain::VertIndex(const int i, const int j);
	///
	/// \brief	Returns a cell's index based on its grid position.
	///
	/// \param 	i	The cell's forward index.
	/// \param 	j	The cell's side index.
	///
	/// \returns	The cell's linear index.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	const int CellIndex(const int i, const int j);
};

#endif
