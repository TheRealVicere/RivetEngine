#include "ActorSpawn.h"

#include "Actor.h"

ActorSpawn::ActorSpawn(Actor* a) :
	actor(a) {}

void ActorSpawn::EnterScene()
{
	actor->EnterScene();
}

void ActorSpawn::ExitScene()
{
	actor->ExitScene();
}
