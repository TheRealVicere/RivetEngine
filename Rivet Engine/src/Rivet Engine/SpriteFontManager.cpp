#include "SpriteFontManager.h"

#include "SpriteFont.h"

SpriteFontManager* SpriteFontManager::instance = nullptr;

SpriteFontManager::~SpriteFontManager()
{
	for (FontMap::iterator it = storageMap.begin(); it != storageMap.end(); it++)
		delete it->second;
	instance = nullptr;
}

SpriteFontManager* SpriteFontManager::Instance()
{
	if (!instance) instance = new SpriteFontManager;
	return instance;
}

void SpriteFontManager::Terminate()
{
	if (instance) delete instance;
}

void SpriteFontManager::PrivLoad(const std::string& key, const std::string& path)
{
	assert(("Key already in use!", storageMap.find(key) == storageMap.end()));
	storageMap[key] = new SpriteFont("Fonts/" + path);
}

SpriteFont* SpriteFontManager::PrivGet(const std::string key)
{
	assert(("Key does not exist!", storageMap.find(key) != storageMap.end()));
	return storageMap.at(key);
}

void SpriteFontManager::Load(const std::string& key, const std::string& path)
{
	Instance()->PrivLoad(key, path);
}

SpriteFont* SpriteFontManager::Get(const std::string key)
{
	return Instance()->PrivGet(key);
}
