#include "Scene.h"

#include "Skybox.h"
#include "SpawnAttorney.h"
#include "Terrain.h"

Scene::~Scene()
{
	list.clear();
}

Camera* Scene::GetCurrent3DCamera()
{
	return camMan.GetCurrent3D();
}

void Scene::SetCurrent3DCamera(Camera* c)
{
	camMan.SetCurrent3D(c);
}

Camera* Scene::GetCurrent2DCamera()
{
	return camMan.GetCurrent2D();
}

void Scene::SetCurrent2DCamera(Camera* c)
{
	camMan.SetCurrent2D(c);
}

UpdateManager::StorageListRef Scene::Register(UpdateComponent* up)
{
	return upMan.Register(up);
}

DrawManager::StorageListRef Scene::Register(DrawComponent* dr)
{
	return drawMan.Register(dr);
}

AlarmManager::TimelineRef Scene::Register(AlarmComponent* al)
{
	return alarmMan.Register(al);
}

KeyboardManager::InputListRef Scene::Register(InputComponent* in)
{
	return keyMan.Register(in);
}

Scene::SpawnListRef Scene::Register(SpawnComponent* sc)
{
	return list.insert(list.end(), sc);
}

void Scene::Deregister(UpdateComponent* up)
{
	upMan.Deregister(up);
}

void Scene::Deregister(DrawComponent* dr)
{
	drawMan.Deregister(dr);
}

void Scene::Deregister(AlarmComponent* al)
{
	alarmMan.Deregister(al);
}

void Scene::Deregister(InputComponent* in)
{
	keyMan.Deregister(in);
}

void Scene::Deregister(SpawnComponent* sc)
{
	list.erase(SpawnAttorney::GetSpawnListRef(sc));
}

void Scene::SubmitCommand(Command* c)
{
	regBroker.AddCommand(c);
}

void Scene::Update()
{
	regBroker.ExecuteAll();
	alarmMan.ProcessElements();
	colMan.ProcessCollisions();
	keyMan.ProcessKeyEvents();
	upMan.ProcessElements();
}

void Scene::Draw()
{
	terrain->Render();
	skybox->Render();
	drawMan.ProcessElements();
}
