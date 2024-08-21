#include "ShaderManager.h"

#include "ShaderObject.h"

ShaderManager* ShaderManager::instance = nullptr;
const std::string ShaderManager::defaultPath = "Shaders/";

ShaderManager::~ShaderManager()
{
	for (ShaderMap::iterator it = storageMap.begin(); it != storageMap.end(); it++)
		delete it->second;
	instance = nullptr;
}

ShaderObject* ShaderManager::PrivGet(const std::string& key)
{
	assert(("Key does not exist!", storageMap.find(key) != storageMap.end()));
	return storageMap.at(key);
}

void ShaderManager::PrivLoad(const std::string& key, const std::string& path)
{
	assert(("Key already in use!", storageMap.find(key) == storageMap.end()));
	storageMap[key] = new ShaderObject((defaultPath + path).c_str());
}

ShaderManager* ShaderManager::Instance()
{
	if (!instance) instance = new ShaderManager;
	return instance;
}

void ShaderManager::Terminate()
{
	assert(instance);
	delete instance;
}

ShaderObject* ShaderManager::Get(const std::string& key)
{
	return Instance()->PrivGet(key);
}

void ShaderManager::Load(const std::string& key, const std::string& path)
{
	Instance()->PrivLoad(key, path);
}
