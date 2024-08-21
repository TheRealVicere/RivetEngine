#include "DrawManager.h"

#include "DrawAttorney.h"

DrawManager::~DrawManager()
{
	storageList.clear();
}

void DrawManager::ProcessElements()
{
	for (DrawComponent* dr : storageList)
		DrawAttorney::Draw(dr);

	for (DrawComponent* dr : storageList)
		DrawAttorney::Draw2D(dr);
}

DrawManager::StorageListRef DrawManager::Register(DrawComponent* dr)
{
	return storageList.insert(storageList.end(), dr);
}

void DrawManager::Deregister(DrawComponent* dr)
{
	storageList.erase(DrawAttorney::GetStorageListRef(dr));
}
