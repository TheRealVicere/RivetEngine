#include "TankUpdate.h"

#include "Keyboard.h"

#include "../Rivet Engine/DebugLog.h"

#include "Tank.h"

TankUpdate::TankUpdate(Tank* t)
{
	tank = t;

	bodyScale.set(SCALE, 6, 6, 6);
	mBody = mCannon = Matrix(ROT_Y, 0);
	cannonScale.set(SCALE, 10, 10, 10);
	mCannon = cannonOffset * mCannon;

	Matrix world = bodyScale * mBody;
	tank->SetBodyMatrix(world);
	world = cannonScale * mCannon;
	tank->SetCannonMatrix(world);
}

void TankUpdate::Update()
{
	mLast = mBody;
	Move();

	Matrix world = bodyScale * mBody;
	tank->SetBodyMatrix(world);
	mCam = mCannon * mBody;
	world = cannonScale * mCam;
	tank->SetCannonMatrix(world);

	UpdateCamera();
	ShowDebug();
}

void TankUpdate::RollbackFrame()
{
	mBody = mLast;
	Matrix world = bodyScale * mBody;
	tank->SetBodyMatrix(world);

	world = cannonScale * mCannon * mBody;
	tank->SetCannonMatrix(world);
}

const Vect TankUpdate::GetPos()
{
	return mBody.get(ROW_3);
}

const Matrix& TankUpdate::GetCannonMatrix()
{
	return mCam;
}

void TankUpdate::Orient(const Matrix& rot)
{
	mBody = rot * Matrix(TRANS, GetPos());
}

void TankUpdate::Set(Matrix m)
{
	mBody = m;
	Matrix world = bodyScale * mBody;
	tank->SetBodyMatrix(world);

	world = cannonScale * (cannonOffset * mBody);
	tank->SetCannonMatrix(world);
}
