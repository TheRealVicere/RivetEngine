#ifndef TerrainTestScene_H
#define TerrainTestScene_H

#include "../Rivet Engine/Scene.h"

class GodCam;
class Tank;

class TerrainTestScene : public Scene {
public:
	TerrainTestScene() = default;
	TerrainTestScene(const TerrainTestScene&) = delete;
	TerrainTestScene& operator=(const TerrainTestScene&) = delete;
	~TerrainTestScene() = default;

	virtual void Initialize();
	virtual void Terminate();

private:
	Tank* tank;
	GodCam* gc;
};

#endif
