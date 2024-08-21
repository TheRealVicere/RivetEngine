#include "Sprite.h"

#include "GraphicsObject_Sprite.h"
#include "Matrix.h"

#include "ModelManager.h"
#include "ImageManager.h"
#include "ShaderManager.h"

Sprite::Sprite(std::string key)
{
	Image* img = ImageManager::Get(key);
	model = new GraphicsObject_Sprite(ModelManager::Get("Sprite"),
		ShaderManager::Get("Sprite"), img, img->pImageRect);
	centerX = 0.0f;
	centerY = 0.0f;
	scaleX = 1.0f;
	scaleY = 1.0f;
	angle = 0.0f;

	Matrix world = Matrix(SCALE, scaleX, scaleY, 1.0f) * Matrix(ROT_Z, angle) * 
		Matrix(TRANS, model->origPosX, model->origPosY, 1.0f);
	model->SetWorld(world);
}

Sprite::~Sprite()
{
	delete model;
}

float Sprite::GetAngle()
{
	return angle;
}

float Sprite::GetAngleDeg()
{
	return angle * MATH_180_PI;
}

void Sprite::SetAngle(const float a)
{
	angle = a;
	UpdateWorldMatrix();
}

void Sprite::SetAngleDeg(const float a)
{
	angle = a * MATH_PI_180;
	UpdateWorldMatrix();
}

void Sprite::SetCenter(const float dx, const float dy)
{
	centerX = dx;
	centerY = dy;

	UpdateWorldMatrix();
}

void Sprite::SetPosition(const float x, const float y)
{
	model->origPosX = x;
	model->origPosY = y;
	UpdateWorldMatrix();
}

void Sprite::SetScaleFactor(float scalex, float scaley)
{
	scaleX = scalex;
	scaleY = scaley;
	UpdateWorldMatrix();
}

void Sprite::SetScalePixel(float w, float h)
{
	scaleX = w / model->origWidth;
	scaleY = h / model->origHeight;
	UpdateWorldMatrix();
}

float Sprite::GetHeight()
{
	return model->origHeight * scaleY;
}

float Sprite::GetWidth()
{
	return model->origWidth * scaleX;
}

void Sprite::Render(Camera* c)
{
	model->Render(c);
}

void Sprite::UpdateWorldMatrix()
{
	Matrix world = Matrix(SCALE, scaleX, scaleY, 1.0f) * Matrix(ROT_Z, angle) *
		Matrix(TRANS, model->origPosX - centerX, model->origPosY - centerY, 1.0f);
	model->SetWorld(world);
}
