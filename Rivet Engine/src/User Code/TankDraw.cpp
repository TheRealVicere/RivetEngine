#include "TankDraw.h"

#include "Camera.h"
#include "GraphicsObject_TextureLight.h"
#include "Texture.h"

#include "../Rivet Engine/ModelManager.h"
#include "../Rivet Engine/Rivet.h"
#include "../Rivet Engine/Scene.h"
#include "../Rivet Engine/SceneManager.h"
#include "../Rivet Engine/ShaderManager.h"
#include "../Rivet Engine/SpriteFontManager.h"
#include "../Rivet Engine/SpriteString.h"

#include "Tank.h"

TankDraw::TankDraw(Tank* t, const Vect& mainCol, const Vect& accentCol)
{
	tank = t;

	mainColor = new Texture((unsigned char) mainCol.X(),
		(unsigned char) mainCol.Y(), (unsigned char) mainCol.Z());
	accentColor = new Texture((unsigned char) accentCol.X(),
		(unsigned char) accentCol.Y(), (unsigned char) accentCol.Z());
	Vect lightCol(1.5f, 1.5f, 1.5f);
	Vect lightPos(1, 1, 1);

	body = new GraphicsObject_TextureLight(ModelManager::Get("Tank Body"),
		ShaderManager::Get("Light"), mainColor, lightCol, lightPos);
	turret = new GraphicsObject_TextureLight(ModelManager::Get("Tank Turret"),
		ShaderManager::Get("Light"), accentColor, lightCol, lightPos);
	barrel = new GraphicsObject_TextureLight(ModelManager::Get("Tank Barrel"),
		ShaderManager::Get("Light"), accentColor, lightCol, lightPos);
}

TankDraw::~TankDraw()
{
	delete body;
	delete turret;
	delete barrel;
	delete mainColor;
	delete accentColor;
}

void TankDraw::Draw()
{
	body->Render(SceneManager::GetCurrent()->GetCurrent3DCamera());
	turret->Render(SceneManager::GetCurrent()->GetCurrent3DCamera());
	barrel->Render(SceneManager::GetCurrent()->GetCurrent3DCamera());
}

Model* TankDraw::GetBodyModel()
{
	return body->getModel();
}

Model* TankDraw::GetTurretModel()
{
	return turret->getModel();
}

Model* TankDraw::GetBarrelModel()
{
	return barrel->getModel();
}

void TankDraw::SetBodyMatrix(const Matrix& m)
{
	Matrix w(m);
	body->SetWorld(w);
}

void TankDraw::SetCannonMatrix(const Matrix& m)
{
	Matrix w(m);
	turret->SetWorld(w);
	barrel->SetWorld(w);
}
