#include "UpdateManager.h"

#include "UpdateAttorney.h"

UpdateManager::~UpdateManager()
{
	storageList.clear();
}

void UpdateManager::ProcessElements()
{
	for (UpdateComponent* up : storageList)
		UpdateAttorney::Update(up);
}

UpdateManager::StorageListRef UpdateManager::Register(UpdateComponent* up)
{
	return storageList.insert(storageList.end(), up);
}

void UpdateManager::Deregister(UpdateComponent* up)
{
	storageList.erase(UpdateAttorney::GetStorageListRef(up));
}
