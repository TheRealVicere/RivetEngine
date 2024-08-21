#include "Rock.h"

#include "../Rivet Engine/GameObject.h"

#include "RockCollision.h"
#include "RockDraw.h"

Rock::Rock()
{
	dr = new RockDraw(this);
	go->AddDraw("Draw", dr);

	col = new RockCollision;
	go->AddCollision("Collider", col);
	go->SetCollider("Collider", dr->GetModel(),
		CollisionComponent::Volume::BSphere);
	go->SetCollisionGroup<RockCollision>();

	go->Spawn();
}

Rock::~Rock()
{
	delete col;
	delete dr;
}

void Rock::SetPos(const Vect& p)
{
	Matrix w(TRANS, p);
	dr->SetPos(p);
	go->UpdateCollisionData("Collider", w);
}

void Rock::Orient(Terrain* t)
{
	Matrix w(dr->Orient(t));
	go->UpdateCollisionData("Collider", w);
}

void Rock::EnterScene()
{
	go->EnableCollision();
	go->SetCurrentDraw("Draw");
}

void Rock::ExitScene()
{
	go->DisableCollision();
	go->SetCurrentDraw("Null");
}
