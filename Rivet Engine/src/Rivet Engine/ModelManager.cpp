#include "ModelManager.h"

ModelManager* ModelManager::instance = nullptr;
const std::string ModelManager::defaultPath = "Models/";

ModelManager::~ModelManager()
{
	for (ModelMap::iterator it = storageMap.begin(); it != storageMap.end(); it++)
		delete it->second;
	instance = nullptr;
}

Model* ModelManager::PrivGet(const std::string& key)
{
	assert(("Key does not exist!", storageMap.find(key) != storageMap.end()));
	return storageMap.at(key);
}

void ModelManager::PrivLoad(const std::string& key, const Model::PreMadeModels pmm)
{
	assert(("Key already in use!", storageMap.find(key) == storageMap.end()));
	storageMap[key] = new Model(pmm);
}

void ModelManager::PrivLoad(const std::string& key, const std::string& path)
{
	assert(("Key already in use!", storageMap.find(key) == storageMap.end()));
	storageMap[key] = new Model((defaultPath + path).c_str());
}

ModelManager* ModelManager::Instance()
{
	if (!instance) instance = new ModelManager;
	return instance;
}

void ModelManager::Terminate()
{
	assert(instance);
	delete instance;
}

Model* ModelManager::Get(const std::string& key)
{
	return Instance()->PrivGet(key);
}

void ModelManager::Load(const std::string& key, const Model::PreMadeModels pmm)
{
	Instance()->PrivLoad(key, pmm);
}

void ModelManager::Load(const std::string& key, const std::string& path)
{
	Instance()->PrivLoad(key, path);
}
