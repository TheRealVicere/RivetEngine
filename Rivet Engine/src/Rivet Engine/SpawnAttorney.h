#ifndef SpawnAttorney_H
#define SpawnAttorney_H

#include "SpawnComponent.h"
#include "Scene.h"

class SpawnAttorney {
private:
	friend class Scene;
	static Scene::SpawnListRef GetSpawnListRef(SpawnComponent* go) {
		return go->GetSpawnListRef();
	}
};

#endif
