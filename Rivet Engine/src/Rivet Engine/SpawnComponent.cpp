#include "SpawnComponent.h"

#include "ISpawnCallback.h"
#include "SceneAttorney.h"

void SpawnComponent::OnRegistration()
{
	ref = SceneAttorney::SpawnRegistry::Register(this);
	EnterScene();
}

void SpawnComponent::OnDeregistration()
{
	SceneAttorney::SpawnRegistry::Deregister(this);
	ExitScene();
}

void SpawnComponent::EnterScene()
{
	callback->EnterScene();
}

void SpawnComponent::ExitScene()
{
	callback->ExitScene();
}

SpawnComponent::SpawnComponent(ISpawnCallback* cb)
{
	assert(("Callback cannot be null!", cb));
	callback = cb;
}

Scene::SpawnListRef SpawnComponent::GetSpawnListRef()
{
	return ref;
}
