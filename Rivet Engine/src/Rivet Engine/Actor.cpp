#include "Actor.h"

#include "ActorSpawn.h"
#include "GameObject.h"

Actor::Actor()
{
	sp = new ActorSpawn(this);
	go = new GameObject(sp);
}

Actor::~Actor()
{
	delete go;
	delete sp;
}
