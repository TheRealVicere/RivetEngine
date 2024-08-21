#ifndef UpdateAttorney_H
#define UpdateAttorney_H

#include "UpdateComponent.h"

class UpdateAttorney {
private:
	friend class UpdateManager;

	static void Update(UpdateComponent* u) { u->Update(); }
	static UpdateManager::StorageListRef GetStorageListRef(UpdateComponent* u) {
		return u->GetStorageListRef();
	}
};

#endif
