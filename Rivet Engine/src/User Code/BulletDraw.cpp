#include "BulletDraw.h"

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

#include "Bullet.h"

BulletDraw::BulletDraw(Bullet* b)
{
	bullet = b;

	Vect lightCol(1.5f, 1.5f, 1.5f);
	Vect lightPos(1, 1, 1);
	color = new Texture(64, 64, 64);
	body = new GraphicsObject_TextureLight(ModelManager::Get("Sphere"),
		ShaderManager::Get("Light"), color, lightCol, lightPos);
}

BulletDraw::~BulletDraw()
{
	delete body;
	delete color;
}

void BulletDraw::Draw()
{
	body->Render(SceneManager::GetCurrent()->GetCurrent3DCamera());
}

Model* BulletDraw::GetModel()
{
	return body->getModel();
}

void BulletDraw::SetWorld(const Matrix& m)
{
	Matrix w(m);
	body->SetWorld(w);
}
