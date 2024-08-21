#include "GameObject.h"

#include "NullDraw.h"
#include "NullUpdate.h"

GameObject::GameObject(ISpawnCallback* sc)
{
	assert(("Callback cannot be null!", sc));
	spawn = new SpawnComponent(sc);

	nullDraw = new NullDraw;
	AddDraw("Null", nullDraw);
	currDraw = draws["Null"];

	nullUpdate = new NullUpdate;
	AddUpdate("Null", nullUpdate);
	currUpdate = updates["Null"];
}

GameObject::~GameObject()
{
	ClearAlarms();
	ClearCollision();
	ClearDraws();
	ClearInputs();
	ClearUpdates();

	delete draws["Null"];
	delete updates["Null"];

	delete spawn;
	delete nullDraw;
	delete nullUpdate;
}

void GameObject::AddAlarm(Key k, IAlarmCallback* cb, const float time)
{
	assert(("Key already in use!", alarms.find(k) == alarms.end()));
	alarms[k] = new AlarmComponent(cb, time);
}

void GameObject::RemoveAlarm(Key k)
{
	auto ref = alarms.find(k);
	assert(("Key not in use!", ref != alarms.end()));
	ref->second->Disable();
	delete ref->second;
	alarms.erase(ref);
}

void GameObject::SetAlarm(Key k)
{
	alarms.find(k)->second->Enable();
}

void GameObject::CancelAlarm(Key k)
{
	alarms.find(k)->second->Disable();
}

void GameObject::ResetAlarm(Key k, const float time)
{
	AlarmComponent* alarm = alarms.find(k)->second;
	alarm->SetTriggerTime(time);
	alarm->Enable();
}

void GameObject::ClearAlarms()
{
	for (auto it = alarms.begin(); it != alarms.end(); it = alarms.begin())
		RemoveAlarm(it->first);
	alarms.clear();
}

void GameObject::AddCollision(Key k, CollisionComponent* c)
{
	assert(("Key already in use!", colliders.find(k) == colliders.end()));
	colliders[k] = c;
}

void GameObject::RemoveCollision(Key k)
{
	auto ref = colliders.find(k);
	assert(("Key not in use!", ref != colliders.end()));
	colliders.erase(ref);
}

void GameObject::EnableCollision()
{
	for (auto it = colliders.begin(); it != colliders.end(); it++)
		it->second->Enable();
}

void GameObject::DisableCollision()
{
	for (auto it = colliders.begin(); it != colliders.end(); it++)
		it->second->Disable();
}

void GameObject::SetCollider(Key k, Model* mod, CollisionComponent::Volume type)
{
	CollisionUpdateAttorney::SetCollider(colliders.at(k), mod, type);
}

void GameObject::UpdateCollisionData(Key k, const Matrix& w)
{
	CollisionUpdateAttorney::UpdateCollisionData(colliders.at(k), w);
}

void GameObject::ClearCollision()
{
	for (auto it = colliders.begin(); it != colliders.end(); it = colliders.begin())
		RemoveCollision(it->first);
	colliders.clear();
}

void GameObject::AddDraw(Key k, IDrawCallback* cb)
{
	assert(("Key already in use!", draws.find(k) == draws.end()));
	draws[k] = new DrawComponent(cb);
}

void GameObject::RemoveDraw(Key k)
{
	auto ref = draws.find(k);
	assert(("Key not in use!", ref != draws.end()));
	assert(("Can't remove null draw!", k != "Null"));

	if (currDraw == ref->second) {
		currDraw->Disable();
		currDraw = nullptr;
	}
	delete ref->second;
	draws.erase(ref);
}

void GameObject::SetCurrentDraw(Key k)
{
	DrawComponent* nextDraw = draws.at(k);
	if (currDraw == nextDraw) return;
	currDraw->Disable();
	currDraw = nextDraw;
	currDraw->Enable();
}

void GameObject::ClearDraws()
{
	for (auto it = draws.begin(); it != draws.end(); it++)
		delete it->second;
	draws.clear();
	AddDraw("Null", nullDraw);
}

void GameObject::AddInput(AZUL_KEY k, KeyboardManager::EventType et,
	IInputCallback* cb)
{
	KeyboardManager::InputEvent e(k, et);
	assert(("Input already in use!", inputs.find(e) == inputs.end()));
	inputs[e] = new InputComponent(cb, e.first, e.second);
}

void GameObject::RemoveInput(AZUL_KEY k, KeyboardManager::EventType et)
{
	KeyboardManager::InputEvent e(k, et);
	auto ref = inputs.find(e);
	assert(("Key not in use!", ref != inputs.end()));
	ref->second->Disable();
	delete ref->second;
	inputs.erase(ref);
}

void GameObject::EnableInput(AZUL_KEY k, KeyboardManager::EventType et)
{
	KeyboardManager::InputEvent e(k, et);
	auto ref = inputs.find(e);
	assert(("Key not in use!", ref != inputs.end()));
	ref->second->Enable();
}

void GameObject::DisableInput(AZUL_KEY k, KeyboardManager::EventType et)
{
	KeyboardManager::InputEvent e(k, et);
	auto ref = inputs.find(e);
	assert(("Key not in use!", ref != inputs.end()));
	ref->second->Disable();
}

void GameObject::ClearInputs()
{
	for (auto it = inputs.begin(); it != inputs.end(); it = inputs.begin())
		RemoveInput(it->first.first, it->first.second);
	inputs.clear();
}

void GameObject::AddUpdate(Key k, IUpdateCallback* cb)
{
	assert(("Key already in use!", updates.find(k) == updates.end()));
	updates[k] = new UpdateComponent(cb);
}

void GameObject::RemoveUpdate(Key k)
{
	auto ref = updates.find(k);
	assert(("Key not in use!", ref != updates.end()));
	assert(("Can't remove null update!", k != "Null"));

	if (currUpdate == ref->second)
		SetCurrentUpdate("Null");
	delete ref->second;
	updates.erase(ref);
}

void GameObject::SetCurrentUpdate(Key k)
{
	UpdateComponent* nextUpdate = updates.at(k);
	if (currUpdate == nextUpdate) return;
	currUpdate->Disable();
	currUpdate = nextUpdate;
	currUpdate->Enable();
}

void GameObject::ClearUpdates()
{
	for (auto it = updates.begin(); it != updates.end(); it++)
		delete it->second;
	updates.clear();
	AddUpdate("Null", nullUpdate);
}

void GameObject::Spawn()
{
	spawn->Enable();
}

void GameObject::Despawn()
{
	spawn->Disable();
}
