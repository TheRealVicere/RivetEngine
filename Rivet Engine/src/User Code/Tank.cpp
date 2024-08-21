#include "Tank.h"

#include "../Rivet Engine/Debugger.h"
#include "../Rivet Engine/GameObject.h"

#include "Bullet.h"
#include "BulletFactory.h"
#include "TankBodyCollision.h"
#include "TankDraw.h"
#include "TankUpdate.h"

Tank::~Tank()
{
	delete colBody;
	delete colTurret;
	delete colBarrel;
	delete dr;
	if (up) delete up;
}

const Vect Tank::GetPos()
{
	return up->GetPos();
}

void Tank::Orient(const Matrix& rot)
{
	up->Orient(rot);
}

void Tank::SetBodyMatrix(const Matrix& m)
{
	dr->SetBodyMatrix(m);
	colBody->SetForward(m.get(ROW_2));
	go->UpdateCollisionData("Body", m);
	Debugger::ShowVolume(colBody->GetVolume());
}

void Tank::SetCannonMatrix(const Matrix& m)
{
	dr->SetCannonMatrix(m);
	go->UpdateCollisionData("Turret", m);
	go->UpdateCollisionData("Barrel", m);
	Debugger::ShowVolume(colTurret->GetVolume());
	Debugger::ShowVolume(colBarrel->GetVolume());
}

void Tank::RollbackFrame()
{
	up->RollbackFrame();
}

void Tank::OnHit()
{
	if (--hitPoints <= 0) go->Despawn();
}

void Tank::SetColliders()
{
	colBody = new TankBodyCollision(this);
	colTurret = new TankCollision(this);
	colBarrel = new TankCollision(this);
}

void Tank::CollisionSetup()
{
	SetColliders();

	go->AddCollision("Body", colBody);
	go->AddCollision("Turret", colTurret);
	go->AddCollision("Barrel", colBarrel);

	go->SetCollider("Body", dr->GetBodyModel(), CollisionComponent::Volume::OBB);
	go->SetCollider("Turret", dr->GetTurretModel(), CollisionComponent::Volume::OBB);
	go->SetCollider("Barrel", dr->GetBarrelModel(), CollisionComponent::Volume::OBB);
}

void Tank::Fire()
{
	static Matrix bulletPos(TRANS, 0, 0, 40);
	Matrix offset = bulletPos * up->GetCannonMatrix();
	BulletFactory::Create(offset);
}
