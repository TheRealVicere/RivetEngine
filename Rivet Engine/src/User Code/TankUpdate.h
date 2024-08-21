#ifndef TankUpdate_H
#define TankUpdate_H

#include "Matrix.h"

#include "../Rivet Engine/IUpdateCallback.h"

class Tank;

class TankUpdate : public IUpdateCallback {
public:
	TankUpdate(Tank* t);
	TankUpdate() = delete;
	TankUpdate(const TankUpdate&) = delete;
	TankUpdate& operator=(const TankUpdate&) = delete;
	virtual ~TankUpdate() = default;

	void Update() override;
	void RollbackFrame();

	const Vect GetPos();
	const Matrix& GetCannonMatrix();
	virtual void Set(Matrix m);
	void Orient(const Matrix& rot);

protected:
	Tank* tank;

	// Object Matrices
	Matrix bodyScale;
	Matrix cannonScale;
	Matrix mBody;
	Matrix mCannon;
	Matrix mCam;

	// Placement Variables
	const Matrix cannonOffset = Matrix(TRANS, 0, 16, 0);
	const float speed = 0.375f;
	const float rotAng = .01f;

private:
	Matrix mLast;

	virtual void Move() = 0;
	virtual void UpdateCamera() {}
	virtual void ShowDebug() {}
};

#endif
