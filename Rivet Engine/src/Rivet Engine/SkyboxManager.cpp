#include "SkyboxManager.h"

#include "NullSkybox.h"

SkyboxManager* SkyboxManager::instance = nullptr;
const std::string SkyboxManager::defaultPath = "Textures/";

SkyboxManager::SkyboxManager()
{
	storageMap["Null"] = new NullSkybox();
}

SkyboxManager::~SkyboxManager()
{
	for (SkyboxMap::iterator it = storageMap.begin(); it != storageMap.end(); it++)
		delete it->second;
	instance = nullptr;
}

Skybox* SkyboxManager::PrivGet(const std::string& key)
{
	assert(("Key does not exist!", storageMap.find(key) != storageMap.end()));
	return storageMap.at(key);
}

void SkyboxManager::PrivLoad(const std::string& key, const std::string& path, float len)
{
	assert(("Key already in use!", storageMap.find(key) == storageMap.end()));
	storageMap[key] = new Skybox((defaultPath + path).c_str(), len);
}

SkyboxManager* SkyboxManager::Instance()
{
	if (!instance) instance = new SkyboxManager;
	return instance;
}

void SkyboxManager::Terminate()
{
	assert(instance);
	delete instance;
}

Skybox* SkyboxManager::Get(const std::string& key)
{
	return Instance()->PrivGet(key);
}

void SkyboxManager::Load(const std::string& key, const std::string& path, float len)
{
	Instance()->PrivLoad(key, path, len);
}
