#include "TerrainManager.h"

#include "NullTerrain.h"
#include "Texture.h"

TerrainManager* TerrainManager::instance = nullptr;
const std::string TerrainManager::defaultPath = "Textures/";

TerrainManager::TerrainManager()
{
	storageMap["Null"] = new NullTerrain();
}

TerrainManager::~TerrainManager()
{
	for (TerrainMap::iterator it = storageMap.begin(); it != storageMap.end(); it++)
		delete it->second;
	instance = nullptr;
}

Terrain* TerrainManager::PrivGet(const std::string& key)
{
	assert(("Key does not exist!", storageMap.find(key) != storageMap.end()));
	return storageMap.at(key);
}

void TerrainManager::PrivLoad(const std::string& key, const std::string& heightmap,
	Texture* tex, float len, float maxheight, float ytrans, int RepeatU, int RepeatV)
{
	assert(("Key already in use!", storageMap.find(key) == storageMap.end()));
	storageMap[key] = new Terrain((defaultPath + heightmap).c_str(), tex, len,
		maxheight, ytrans, RepeatU, RepeatV);
}

TerrainManager* TerrainManager::Instance()
{
	if (!instance) instance = new TerrainManager;
	return instance;
}

void TerrainManager::Terminate()
{
	assert(instance);
	delete instance;
}

Terrain* TerrainManager::Get(const std::string& key)
{
	return Instance()->PrivGet(key);
}

void TerrainManager::Load(const std::string& key, const std::string& heightmap,
	Texture* tex, float len, float maxheight, float ytrans, int RepeatU, int RepeatV)
{
	Instance()->PrivLoad(key, heightmap, tex, len, maxheight, ytrans, RepeatU, RepeatV);
}
