#include "Bullet.h"

#include "AzulCore.h"

#include "../Rivet Engine/ActorSpawn.h"
#include "../Rivet Engine/GameObject.h"
#include "../Rivet Engine/Lifetime.h"

#include "BulletCollision.h"
#include "BulletDraw.h"
#include "BulletUpdate.h"

Bullet::Bullet() {
	dr = new BulletDraw(this);
	go->AddDraw("Draw", dr);

	col = new BulletCollision(this);
	go->AddCollision("Body", col);
	go->SetCollider("Body", dr->GetModel(), CollisionComponent::Volume::BSphere);
	go->SetCollisionGroup<BulletCollision>();

	isFriendly = false;

	lt = new Lifetime(go);

	up = new BulletUpdate(this);
	go->AddUpdate("Update", up);

	go->AddAlarm("Lifetime", lt, 5.0f);
}

Bullet::~Bullet()
{
	delete col;
	delete dr;
	delete lt;
	delete up;
}

void Bullet::SetActiveRef(BulletFactory::ActiveRef ref)
{
	activeRef = ref;
}

BulletFactory::ActiveRef Bullet::GetActiveRef()
{
	return activeRef;
}

void Bullet::SetWorld(const Matrix& w)
{
	dr->SetWorld(w);
	go->UpdateCollisionData("Body", w);
}

void Bullet::SetRotTrans(const Matrix& rt)
{
	up->SetRotTrans(rt);
}

bool Bullet::IsFriendly()
{
	return isFriendly;
}

void Bullet::SetFriendly(const bool f)
{
	isFriendly = f;
}

void Bullet::Create()
{
	go->Spawn();
}

void Bullet::Destroy()
{
	go->Despawn();
}

void Bullet::EnterScene()
{
	go->SetCurrentUpdate("Update");
	go->SetCurrentDraw("Draw");
	go->EnableCollision();
	go->SetAlarm("Lifetime");
}

void Bullet::ExitScene()
{
	go->SetCurrentUpdate("Null");
	go->SetCurrentDraw("Null");
	go->DisableCollision();
	go->CancelAlarm("Lifetime");
	BulletFactory::Recycle(this);
}
