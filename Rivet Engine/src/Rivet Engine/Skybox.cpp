#include "Skybox.h"

#include "GpuVertTypes.h"
#include "GraphicsObject_TextureFlat.h"
#include "Model.h"

#include "Scene.h"
#include "SceneManager.h"
#include "ShaderManager.h"

Skybox::Skybox(const std::string texturePath, float len)
{
	len *= 100;
	int nverts = 24;
	VertexStride_VUN* pVerts = new VertexStride_VUN[nverts];
	int ntri = 12;
	TriangleIndex* pTriList = new TriangleIndex[ntri];

	// Setting up faces
	// Forward
	int vind = 0;
	int tind = 0;
	pVerts[vind].set(0.5f * len, 0.5f * len, 0.5f * len, 0.25f, 0.333f, 0, 0, -1);
	pVerts[vind + 1].set(-0.5f * len, 0.5f * len, 0.5f * len, 0.5f, 0.333f, 0, 0, -1);
	pVerts[vind + 2].set(-0.5f * len, -0.5f * len, 0.5f * len, 0.5f, 0.667f, 0, 0, -1);
	pVerts[vind + 3].set(0.5f * len, -0.5f * len, 0.5f * len, 0.25f, 0.667f, 0, 0, -1);
	pTriList[tind].set(vind, vind + 2, vind + 1);
	pTriList[tind + 1].set(vind, vind + 3, vind + 2);

	// Back
	vind += 4;
	tind += 2;
	pVerts[vind].set(0.5f * len, 0.5f * len, -0.5f * len, 1, 0.333f, 0, 0, 1);
	pVerts[vind + 1].set(-0.5f * len, 0.5f * len, -0.5f * len, 0.75f, 0.333f, 0, 0, 1);
	pVerts[vind + 2].set(-0.5f * len, -0.5f * len, -0.5f * len, 0.75f, 0.667f, 0, 0, 1);
	pVerts[vind + 3].set(0.5f * len, -0.5f * len, -0.5f * len, 1, 0.667f, 0, 0, 1);
	pTriList[tind].set(vind + 1, vind + 2, vind);
	pTriList[tind + 1].set(vind + 2, vind + 3, vind);

	// Left
	vind += 4;
	tind += 2;
	pVerts[vind].set(0.5f * len, 0.5f * len, -0.5f * len, 0, 0.333f, -1, 0, 0);
	pVerts[vind + 1].set(0.5f * len, 0.5f * len, 0.5f * len, 0.25f, 0.333f, -1, 0, 0);
	pVerts[vind + 2].set(0.5f * len, -0.5f * len, 0.5f * len, 0.25f, 0.667f, -1, 0, 0);
	pVerts[vind + 3].set(0.5f * len, -0.5f * len, -0.5f * len, 0, 0.667f, -1, 0, 0);
	pTriList[tind].set(vind, vind + 2, vind + 1);
	pTriList[tind + 1].set(vind, vind + 3, vind + 2);

	// Right
	vind += 4;
	tind += 2;
	pVerts[vind].set(-0.5f * len, 0.5f * len, 0.5f * len, 0.5f, 0.333f, 1, 0, 0);
	pVerts[vind + 1].set(-0.5f * len, 0.5f * len, -0.5f * len, 0.75f, 0.333f, 1, 0, 0);
	pVerts[vind + 2].set(-0.5f * len, -0.5f * len, -0.5f * len, 0.75f, 0.667f, 1, 0, 0);
	pVerts[vind + 3].set(-0.5f * len, -0.5f * len, 0.5f * len, 0.5f, 0.667f, 1, 0, 0);
	pTriList[tind].set(vind, vind + 2, vind + 1);
	pTriList[tind + 1].set(vind, vind + 3, vind + 2);

	// Top
	vind += 4;
	tind += 2;
	pVerts[vind].set(0.5f * len, 0.5f * len, -0.5f * len, 0.25f, 0.001f, 0, -1, 0);
	pVerts[vind + 1].set(-0.5f * len, 0.5f * len, -0.5f * len, 0.5f, 0.001f, 0, -1, 0);
	pVerts[vind + 2].set(-0.5f * len, 0.5f * len, 0.5f * len, 0.5f, 0.333f, 0, -1, 0);
	pVerts[vind + 3].set(0.5f * len, 0.5f * len, 0.5f * len, 0.25f, 0.333f, 0, -1, 0);
	pTriList[tind].set(vind, vind + 2, vind + 1);
	pTriList[tind + 1].set(vind, vind + 3, vind + 2);

	// Bottom
	vind += 4;
	tind += 2;
	pVerts[vind].set(0.5f * len, -0.5f * len, 0.5f * len, 0.25f, 0.667f, 0, 1, 0);
	pVerts[vind + 1].set(-0.5f * len, -0.5f * len, 0.5f * len, 0.5f, 0.667f, 0, 1, 0);
	pVerts[vind + 2].set(-0.5f * len, -0.5f * len, -0.5f * len, 0.5f, 0.999f, 0, 1, 0);
	pVerts[vind + 3].set(0.5f * len, -0.5f * len, -0.5f * len, 0.25f, 0.999f, 0, 1, 0);
	pTriList[tind].set(vind, vind + 2, vind + 1);
	pTriList[tind + 1].set(vind, vind + 3, vind + 2);

	model = new Model(pVerts, nverts, pTriList, ntri);
	tex = new Texture(texturePath.c_str());
	obj = new GraphicsObject_TextureFlat(model, ShaderManager::Get("Flat"), tex);

	Matrix world(IDENTITY);
	obj->SetWorld(world);

	delete[] pVerts;
	delete[] pTriList;
}

Skybox::~Skybox()
{
	delete obj;
	delete tex;
	delete model;
}

void Skybox::Render()
{
	obj->Render(SceneManager::GetCurrent()->GetCurrent3DCamera());
}
