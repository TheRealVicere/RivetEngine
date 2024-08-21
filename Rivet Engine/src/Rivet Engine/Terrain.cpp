#include "Terrain.h"

#include <algorithm>

#include "GpuVertTypes.h"
#include "GraphicsObject_TextureFlat.h"
#include "GraphicsObject_WireframeConstantColor.h"
#include "TextureTGA.h"

#include "AABB.h"
#include "Colors.h"
#include "CollisionComponent.h"
#include "Debugger.h"
#include "MathTools.h"
#include "Scene.h"
#include "SceneManager.h"
#include "ShaderManager.h"
#include "TerrainRect.h"

const float Terrain::MAX_RVAL = 255.0f;

void Terrain::SetAABBs()
{
	boxes = new AABB[cellCount];
	Vect* vList = terrainMod->getVectList();

	for (int k = 0; k < sideCells * sideCells; k++) {
		int i = k / sideCells;
		int j = k % sideCells;

		Vect v1 = vList[VertIndex(i, j)];
		Vect v2 = vList[VertIndex(i + 1, j)];
		Vect v3 = vList[VertIndex(i, j + 1)];
		Vect v4 = vList[VertIndex(i + 1, j + 1)];
		
		Vect min = MathTools::Minimize(v1, v2);
		min = MathTools::Minimize(min, v3);
		min = MathTools::Minimize(min, v4);

		Vect max = MathTools::Maximize(v1, v2);
		max = MathTools::Maximize(max, v3);
		max = MathTools::Maximize(max, v4);

		boxes[k].Set(min, max);
	}
}

Terrain::Terrain(const char* heightmapFile, Texture* tex, float len, float maxheight,
	float ytrans, int RepeatU, int RepeatV)
{
	int width, height, comp;
	unsigned int type;
	GLbyte* imgData = gltReadTGABits(heightmapFile, &width, &height, &comp, &type);
	assert(width == height && width > 0);

	sideVerts = width;
	sideCells = sideVerts - 1;
	cellCount = sideCells * sideCells;
	sideLen = len;

	size_t pixel_width = 3;	// 3 bytes RGB per pixel
	unsigned char h_val; // = hgtmap->pixels[pixel_width * (5 * side + 3)]; // the 'R' byte of the pixel at (3,5)

	int nverts = sideVerts * sideVerts;
	VertexStride_VUN* pVerts = new VertexStride_VUN[nverts];
	norms = new Vect[nverts];

	int triSide = sideVerts - 1;
	int nTris = 2 * triSide * triSide;
	TriangleIndex* pTriList = new TriangleIndex[nTris];

	int index = 0;
	cellLen = len / (float) sideVerts;
	float xpos = 0.5f * len;
	float zpos = -0.5f * len;

	for (int i = 0; i < sideVerts; i++) {
		for (int j = 0; j < sideVerts; j++) {
			h_val = static_cast<unsigned char>(imgData[pixel_width * index]);
			pVerts[index].set(xpos, h_val / MAX_RVAL * maxheight + ytrans, zpos,
				j / (float) sideVerts * RepeatU, i / (float) sideVerts * RepeatV,
				0, 0, 0);
			xpos -= cellLen;
			index++;
		}
		zpos += cellLen;
		xpos = 0.5f * len;
	}

	index = 0;
	for (int i = 0; i < sideVerts; i++) {
		for (int j = 0; j < sideVerts; j++) {
			if (i > 0 && i < sideVerts - 1 && j > 0 && j < sideVerts - 1) {
				Vect currPos(pVerts[index].x, pVerts[index].y, pVerts[index].z);
				Vect pos0(pVerts[index - sideVerts].x, pVerts[index - sideVerts].y, pVerts[index - sideVerts].z);
				Vect pos1(pVerts[index - 1].x, pVerts[index - 1].y, pVerts[index - 1].z);
				Vect pos2(pVerts[index + sideVerts - 1].x, pVerts[index + sideVerts - 1].y, pVerts[index + sideVerts - 1].z);
				Vect pos3(pVerts[index + sideVerts].x, pVerts[index + sideVerts].y, pVerts[index + sideVerts].z);
				Vect pos4(pVerts[index + 1].x, pVerts[index + 1].y, pVerts[index + 1].z);
				Vect pos5(pVerts[index - sideVerts + 1].x, pVerts[index - sideVerts + 1].y, pVerts[index - sideVerts + 1].z);

				Vect a = pos0 - currPos;
				Vect b = pos1 - currPos;
				Vect c = pos2 - currPos;
				Vect d = pos3 - currPos;
				Vect e = pos4 - currPos;
				Vect f = pos5 - currPos;

				Vect face1 = b.cross(a);
				Vect face2 = c.cross(b);
				Vect face3 = d.cross(c);
				Vect face4 = e.cross(d);
				Vect face5 = f.cross(e);
				Vect face6 = a.cross(f);
				
				Vect norm = (face1 + face2 + face3 + face4 + face5 + face6).norm(); // No division since norm will handle that already
				norms[index].set(norm);
				pVerts[index].nx = norm.X();
				pVerts[index].ny = norm.Y();
				pVerts[index].nz = norm.Z();
			}
			index++;
		}
	}

	index = 0;
	for (int i = 0; i < sideVerts - 1; i++) {
		for (int j = 0; j < sideVerts - 1; j++) {
			pTriList[index].set((i + 1) * sideVerts + j, i * sideVerts + j, i * sideVerts + j + 1);
			pTriList[index + 1].set(i * sideVerts + j + 1, (i + 1) * sideVerts + j + 1, (i + 1) * sideVerts + j);
			index += 2;
		}
	}

	terrainMod = new Model(pVerts, nverts, pTriList, nTris);
	Vect col = Colors::Black;
	terrain = new GraphicsObject_TextureFlat(terrainMod,
		ShaderManager::Get("Flat"), tex);
	wireframe = new GraphicsObject_WireframeConstantColor(terrainMod,
		ShaderManager::Get("Constant"), col);
	SetAABBs();

	delete[] pVerts;
	delete[] pTriList;
	delete imgData;
}

Terrain::~Terrain()
{
	delete terrain;
	delete terrainMod;
	delete wireframe;
	delete[] boxes;
	delete[] norms;
}

void Terrain::Render()
{
	terrain->Render(SceneManager::GetCurrent()->GetCurrent3DCamera());
	// wireframe->Render(SceneManager::GetCurrent()->GetCurrent3DCamera());
}

void Terrain::ShowAllColliders()
{
	for (int i = 0; i < cellCount; i++)
		Debugger::ShowBox(boxes[i], Colors::ZyaBlue);
}

const AABB& Terrain::GetBoxAt(const int i, const int j)
{
	return boxes[CellIndex(i, j)];
}

const Vect Terrain::GetPointBelow(const Vect& point)
{
	int index = GetTriBelow(point);
	if (index == -1) return point;
	int parity = index % 2;

	Vect* verts = terrainMod->getVectList();
	index /= 2; // truncates odd remainder
	int i = index / sideCells, j = index % sideCells;

	Vect a = verts[VertIndex(i, j + 1)];
	Vect c = verts[VertIndex(i + 1, j)];
	Vect b;
	if (parity) b = verts[VertIndex(i + 1, j + 1)];
	else b = verts[VertIndex(i, j)];

	float qa = a.Y(), qb = b.Y(), qc = c.Y();
	float beta = (point - a).dot(b - a) / (b - a).magSqr();
	float gamma = (point - a).dot(c - b) / (c - b).magSqr();
	float qp = qa + beta * (qb - qa) + gamma * (qc - qb);
	Vect tPoint(point.X(), qp, point.Z());

	Debugger::ShowLine(tPoint, point, Colors::AequoraRed);
	return tPoint;
}

const Vect Terrain::GetNormBelow(const Vect& point)
{
	int index = GetTriBelow(point);
	if (index == -1) return Vect(0, 0, 0);
	int parity = index % 2;
	
	Vect* verts = terrainMod->getVectList();
	index /= 2; // truncates odd remainder
	int i = index / sideCells, j = index % sideCells;

	Vect a = verts[VertIndex(i, j + 1)], qa = norms[VertIndex(i, j + 1)];
	Vect c = verts[VertIndex(i + 1, j)], qc = norms[VertIndex(i + 1, j)];
	Vect b, qb;
	if (parity) {
		b = verts[VertIndex(i + 1, j + 1)];
		qb = norms[VertIndex(i + 1, j + 1)];
	} else {
		b = verts[VertIndex(i, j)];
		qb = norms[VertIndex(i, j)];
	}
	
	float beta = (point - a).dot(b - a) / (b - a).magSqr();
	float gamma = (point - a).dot(c - b) / (c - b).magSqr();
	Vect normal = qa + beta * (qb - qa) + gamma * (qc - qb);

	return normal.norm();
}

const int Terrain::GetCellBelow(const Vect& point)
{
	float lenX = -(point.X()), lenZ = point.Z();
	lenX += sideLen / 2.0f;
	lenZ += sideLen / 2.0f;
	if (lenX < 0 || lenX > sideLen || lenZ < 0 || lenZ > sideLen) return -1;

	float delta = sideLen / sideVerts;
	int i = (int)(lenZ / delta);
	int j = (int)(lenX / delta);
	return CellIndex(i, j);
}

TerrainRect Terrain::GetCellsBelow(const BSphere& sphere)
{
	int index1 = GetCellBelow(MathTools::GetMin(sphere));
	int index2 = GetCellBelow(MathTools::GetMax(sphere));

	if (index1 == -1 || index2 == -1) return TerrainRect(this, 0, 0, 0, 0);

	int iMin = index1 / sideCells, jMax = index1 % sideCells;
	int iMax = index2 / sideCells, jMin = index2 % sideCells;

	return TerrainRect(this, iMin, iMax, jMin, jMax);
}

const int Terrain::GetTriBelow(const Vect& point)
{
	int index = GetCellBelow(point);
	if (index == -1) return -1;
	
	int i = index / sideCells, j = index % sideCells;
	Vect* vList = terrainMod->getVectList();
	Vect anchor = vList[VertIndex(i, j + 1)];

	index = TriIndex(i, j);
	if ((point - anchor).X() > (point - anchor).Z()) return index;
	return index + 1;
}

const int Terrain::VertIndex(const int i, const int j)
{
	if (i < 0 || j < 0 || i >= sideVerts || j >= sideVerts) return -1;
	return (i * sideVerts + j);
}

const int Terrain::TriIndex(const int i, const int j)
{
	if (i < 0 || j < 0 || i >= sideCells || j >= sideCells) return -1;
	return (2 * (i * sideCells + j));
}

const int Terrain::CellIndex(const int i, const int j)
{
	if (i < 0 || j < 0 || i >= sideCells || j >= sideCells) return -1;
	return (i * sideCells + j);
}
