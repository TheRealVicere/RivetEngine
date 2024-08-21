#include "../Rivet Engine/Rivet.h"

#include "../Rivet Engine/ImageManager.h"
#include "../Rivet Engine/ModelManager.h"
#include "../Rivet Engine/SceneManager.h"
#include "../Rivet Engine/ShaderManager.h"
#include "../Rivet Engine/SkyboxManager.h"
#include "../Rivet Engine/SpriteFontManager.h"
#include "../Rivet Engine/TerrainManager.h"
#include "../Rivet Engine/TextureManager.h"

#include "../User Code/InitScene.h"

void Rivet::LoadResources() {
	// -- Models -- //
	ModelManager::Load("Tank Body", "Pixel_Tank_Body.azul");
	ModelManager::Load("Tank Turret", "Pixel_Tank_Turret.azul");
	ModelManager::Load("Tank Barrel", "Pixel_Tank_Barrel.azul");
	ModelManager::Load("Rock", "Rock.azul");
	ModelManager::Load("Sphere", Model::PreMadeModels::UnitSphere);
	ModelManager::Load("Box", Model::PreMadeModels::UnitBox_WF);
	ModelManager::Load("Sprite", Model::PreMadeModels::UnitSquareXY);

	// -- Shaders -- //
	ShaderManager::Load("Flat", "textureFlatRender");
	ShaderManager::Load("Light", "textureLightRender");
	// ShaderManager::Load("Varied Color", "colorVaryRender");
	ShaderManager::Load("Constant", "colorConstantRender");
	ShaderManager::Load("No Texture", "colorNoTextureRender");
	// ShaderManager::Load("Light No Texture", "colorNoTextureLightRender");
	ShaderManager::Load("Sprite", "spriteRender");
	// ShaderManager::Load("Sprite Line", "spriteLineRender");

	// -- Textures -- //
	TextureManager::Load("Null", "NullTexture.tga"); // REQUIRED
	TextureManager::Load("Grass", "Grass_Retro.tga");
	TextureManager::Load("Snow", "Snow_Retro.tga");
	TextureManager::Load("Rock", "RockTex.tga");
	TextureManager::Load("Hell", "Hell_Retro.tga");

	// -- Images -- //
	// None for now
	
	// -- Terrains -- //
	TerrainManager::Load("Hills", "HMCustom128.tga", TextureManager::Get("Grass"),
		3000, 200, -139, 150, 150);
	TerrainManager::Load("Snowy", "HMCustom128_inv.tga", TextureManager::Get("Snow"),
		3000, 200, -63.5f, 150, 150);
	TerrainManager::Load("Flat", "FlatTerrain.tga", TextureManager::Get("Grass"),
		3000, 1, 0, 150, 150);
	TerrainManager::Load("Hell", "FlatTerrain.tga", TextureManager::Get("Hell"),
		3000, 1, 0, 150, 150);

	// -- Skyboxes -- //
	SkyboxManager::Load("Day", "Skybox_Retro.tga");
	SkyboxManager::Load("Night", "Skybox_Night_Retro.tga");
	SkyboxManager::Load("Hell", "Skybox_Hell_Retro.tga");

	// -- Fonts -- //
	SpriteFontManager::Load("HUD", "HUD");
	SpriteFontManager::Load("Title", "Title");

	// -- Starting Scene -- //
	SceneManager::SetStartScene(new InitScene);
}
