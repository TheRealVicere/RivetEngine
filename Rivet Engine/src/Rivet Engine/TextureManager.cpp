#include "TextureManager.h"

#include "Texture.h"

TextureManager* TextureManager::instance = nullptr;
const std::string TextureManager::defaultPath = "Textures/";

TextureManager::~TextureManager()
{
	for (TextureMap::iterator it = storageMap.begin(); it != storageMap.end(); it++)
		delete it->second;
	instance = nullptr;
}

Texture* TextureManager::PrivGet(const std::string& key)
{
	assert(("Key does not exist!", storageMap.find(key) != storageMap.end()));
	return storageMap.at(key);
}

void TextureManager::PrivLoad(const std::string& key, const std::string& path)
{
	assert(("Key already in use!", storageMap.find(key) == storageMap.end()));
	storageMap[key] = new Texture((defaultPath + path).c_str());
}

TextureManager* TextureManager::Instance()
{
	if (!instance) instance = new TextureManager;
	return instance;
}

void TextureManager::Terminate()
{
	assert(instance);
	delete instance;
}

Texture* TextureManager::Get(const std::string& key)
{
	return Instance()->PrivGet(key);
}

void TextureManager::Load(const std::string& key, const std::string& path)
{
	Instance()->PrivLoad(key, path);
}
