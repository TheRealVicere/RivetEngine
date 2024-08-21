#include "NullTerrain.h"
#include "TextureManager.h"

NullTerrain::NullTerrain() :
	Terrain("Textures/NullTexture.tga", TextureManager::Get("Null"),
		0.0f, 0.0f, 0.0f, 0, 0) {}
