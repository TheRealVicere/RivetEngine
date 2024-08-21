#ifndef AssetAttorney_H
#define AssetAttorney_H

#include "ModelManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "ImageManager.h"
#include "SpriteFontManager.h"
#include "TerrainManager.h"
#include "SkyboxManager.h"

class AssetAttorney {
	friend class Rivet;
private:
	static void TerminateAssetManagers() {
		ModelManager::Terminate();
		ShaderManager::Terminate();
		TextureManager::Terminate();
		ImageManager::Terminate();
		SpriteFontManager::Terminate();
		TerrainManager::Terminate();
		SkyboxManager::Terminate();
	}
};

#endif
