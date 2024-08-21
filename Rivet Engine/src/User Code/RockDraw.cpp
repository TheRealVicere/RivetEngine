#include "RockDraw.h"

#include "GraphicsObject_TextureLight.h"

#include "../Rivet Engine/ModelManager.h"
#include "../Rivet Engine/Scene.h"
#include "../Rivet Engine/SceneManager.h"
#include "../Rivet Engine/ShaderManager.h"
#include "../Rivet Engine/Terrain.h"
#include "../Rivet Engine/TextureManager.h"

#include "Rock.h"

RockDraw::RockDraw(Rock* r)
{
	rock = r;

	Vect lightCol(1.5f, 1.5f, 1.5f);
	Vect lightPos(1.0f, 1.0f, 1.0f);
	model = new GraphicsObject_TextureLight(ModelManager::Get("Rock"),
		ShaderManager::Get("Light"), TextureManager::Get("Rock"), lightCol, lightPos);

	scale.set(SCALE, 0.5f, 0.5f, 0.5f);
	world.set(IDENTITY);

	Matrix result(scale * world);
	model->SetWorld(result);
}

RockDraw::~RockDraw()
{
	delete model;
}

void RockDraw::SetPos(const Vect& p)
{
	world.set(TRANS, p);
	Matrix result(scale * world);
	model->SetWorld(result);
}

const Matrix RockDraw::Orient(Terrain* t)
{
	Vect norm = t->GetNormBelow(world.get(ROW_3));
	Vect right = norm.cross(world.get(ROW_2));
	Vect fwd = right.cross(norm);
	Matrix rot(ROT_ORIENT, fwd, norm);
	world = rot * world;

	Matrix result(scale * world);
	model->SetWorld(result);
	return result;
}

Model* RockDraw::GetModel()
{
	return model->getModel();
}

void RockDraw::Draw()
{
	model->Render(SceneManager::GetCurrent()->GetCurrent3DCamera());
}
