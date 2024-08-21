#ifndef TerrainManager_H
#define TerrainManager_H

#include <map>

class Terrain;
class Texture;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	TerrainManager
///
/// \brief	Manager for terrains. Loads, stores, and accesses terrains for use in games.
///
/// \author	Mike Piunti
/// \date	05/10/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class TerrainManager {
	friend class AssetAttorney;
private:
	TerrainManager();
	TerrainManager(const TerrainManager&) = delete;
	TerrainManager& operator=(const TerrainManager&) = delete;
	~TerrainManager();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Terrain* TerrainManager::PrivGet(const std::string& key);
	///
	/// \brief	Returns a terrain previously loaded with a given key.
	///
	/// \param 	key	The string key the terrain was loaded with.
	///
	/// \returns	A pointer to the terrain stored with the given key.
	/// 			Crashes in debug mode if the key does not exist.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Terrain* PrivGet(const std::string& key);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void TerrainManager::PrivLoad(const std::string& key, const std::string& path);
	///
	/// \brief	Stores a terrain for later use. The given key is used to return the stored terrain.
	/// 		Note that keys must be unique.
	/// 		
	/// \param	key			The string key used to return the terrain.
	/// \param	heightmap	Relative pathname of the terrain heightmap file. Starts in the project's Assets\Textures folder.
	/// \param	tex			The texture used on the terrain.
	/// \param 	len			The length of the terrain, in AZUL units.
	/// \param 	maxheight	The height of the terrain model.
	/// \param 	ytrans		The Y offset used to place the terrain.
	/// \param 	RepeatU		The number of times to use the texture's UV coordinates along the U axis.
	/// \param 	RepeatV		The number of times to use the texture's UV coordinates along the V axis.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void PrivLoad(const std::string& key, const std::string& heightmap, Texture* tex, float len,
		float maxheight, float ytrans, int RepeatU, int RepeatV);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static TerrainManager* TerrainManager::Instance();
	///
	/// \brief	Gets the instance of the terrain manager. Used to create an instance if none exists.
	///
	/// \returns	The current instance of the terrain manager.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static TerrainManager* Instance();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void TerrainManager::Terminate();
	///
	/// \brief	Terminates the terrain manager.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Terminate();

	/// \brief	The current instance of the terrain manager.
	static TerrainManager* instance;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::string MapKey
	///
	/// \brief	Defines an alias representing the key used to return a terrain.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::string MapKey;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::map<MapKey, Terrain*> TerrainMap
	///
	/// \brief	Defines an alias representing the map used to store terrains by key.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::map<MapKey, Terrain*> TerrainMap;

	/// \brief	(Immutable) The default relative path to search for terrains.
	static const std::string defaultPath;

	/// \brief	The map which stores terrains for later use.
	TerrainMap storageMap;

public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static Terrain* TerrainManager::Get(const std::string& key);
	///
	/// \brief	Same as PrivGet(key), but accessible to users through the resource loader source file.
	///
	/// \param 	key	The string key the terrain was loaded with.
	///
	/// \returns	A pointer to the terrain stored with the given key.
	/// 			Crashes in debug mode if the key does not exist.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static Terrain* Get(const std::string& key);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void TerrainManager::Load(const std::string& key, const std::string& path);
	///
	/// \brief	Stores a terrain for later use. The given key is used to return the stored terrain.
	/// 		Note that keys must be unique.
	/// 		
	/// \param	key			The string key used to return the terrain.
	/// \param	heightmap	Relative pathname of the terrain heightmap file. Starts in the project's Assets\Textures folder.
	/// \param	tex			The texture used on the terrain.
	/// \param 	len			The length of the terrain, in AZUL units.
	/// \param 	maxheight	The height of the terrain model.
	/// \param 	ytrans		The Y offset used to place the terrain.
	/// \param 	RepeatU		The number of times to use the texture's UV coordinates along the U axis.
	/// \param 	RepeatV		The number of times to use the texture's UV coordinates along the V axis.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Load(const std::string& key, const std::string& heightmap, Texture* tex, float len,
		float maxheight, float ytrans, int RepeatU, int RepeatV);
};

#endif
