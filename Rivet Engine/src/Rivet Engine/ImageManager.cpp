#include "ImageManager.h"

#include "Image.h"

ImageManager* ImageManager::instance = nullptr;
const std::string ImageManager::defaultPath = "Sprites/";

ImageManager::~ImageManager()
{
	for (ImageMap::iterator it = storageMap.begin(); it != storageMap.end(); it++)
		delete it->second;
	instance = nullptr;
}

Image* ImageManager::PrivGet(const std::string& key)
{
	assert(("Key does not exist!", storageMap.find(key) != storageMap.end()));
	return storageMap.at(key);
}

void ImageManager::PrivLoad(const std::string& key, Texture* tex)
{
	assert(("Key already in use!", storageMap.find(key) == storageMap.end()));
	storageMap[key] = new Image(tex, new Rect(0.0f, 0.0f, (float) tex->getWidth(),
		(float) tex->getHeight()));
}

void ImageManager::PrivLoad(const std::string& key, Texture* tex, Rect* r)
{
	assert(("Key already in use!", storageMap.find(key) == storageMap.end()));
	storageMap[key] = new Image(tex, r);
}

ImageManager* ImageManager::Instance()
{
	if (!instance) instance = new ImageManager;
	return instance;
}

void ImageManager::Terminate()
{
	if (instance) delete instance;
}

Image* ImageManager::Get(const std::string& key)
{
	return Instance()->PrivGet(key);
}

void ImageManager::Load(const std::string& key, Texture* tex)
{
	Instance()->PrivLoad(key, tex);
}

void ImageManager::Load(const std::string& key, Texture* tex, Rect* r)
{
	Instance()->PrivLoad(key, tex, r);
}
