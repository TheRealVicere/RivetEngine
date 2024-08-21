#ifndef SkyboxManager_H
#define SkyboxManager_H

#include <map>

class Skybox;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	SkyboxManager
///
/// \brief	Manager for skyboxes. Loads, stores, and accesses skyboxes for use in games.
///
/// \author	Mike Piunti
/// \date	05/23/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class SkyboxManager {
	friend class AssetAttorney;
private:
	SkyboxManager();
	SkyboxManager(const SkyboxManager&) = delete;
	SkyboxManager& operator=(const SkyboxManager&) = delete;
	~SkyboxManager();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Skybox* SkyboxManager::PrivGet(const std::string& key);
	///
	/// \brief	Returns a skybox previously loaded with a given key.
	///
	/// \param 	key	The string key the skybox was loaded with.
	///
	/// \returns	A pointer to the skybox stored with the given key.
	/// 			Crashes in debug mode if the key does not exist.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Skybox* PrivGet(const std::string& key);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void SkyboxManager::PrivLoad(const std::string& key, const std::string& path, float len = 30.0f);
	///
	/// \brief	Stores a skybox for later use. The given key is used to return the stored skybox.
	/// 		Note that keys must be unique.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void PrivLoad(const std::string& key, const std::string& path, float len = 30.0f);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static SkyboxManager* SkyboxManager::Instance();
	///
	/// \brief	Gets the instance of the skybox manager. Used to create an instance if none exists.
	///
	/// \returns	The current instance of the skybox manager.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static SkyboxManager* Instance();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void SkyboxManager::Terminate();
	///
	/// \brief	Terminates the skybox manager.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Terminate();

	/// \brief	The current instance of the skybox manager.
	static SkyboxManager* instance;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::string MapKey
	///
	/// \brief	Defines an alias representing the key used to return a skybox.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::string MapKey;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::map<MapKey, Skybox*> SkyboxMap
	///
	/// \brief	Defines an alias representing the map used to store skyboxes by key.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::map<MapKey, Skybox*> SkyboxMap;

	/// \brief	(Immutable) The default relative path to search for skyboxes.
	static const std::string defaultPath;

	/// \brief	The map which stores skyboxes for later use.
	SkyboxMap storageMap;

public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static Skybox* SkyboxManager::Get(const std::string& key);
	///
	/// \brief	Same as PrivGet(key), but accessible to users through the resource loader source file.
	///
	/// \param 	key	The string key the skybox was loaded with.
	///
	/// \returns	A pointer to the skybox stored with the given key.
	/// 			Crashes in debug mode if the key does not exist.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static Skybox* Get(const std::string& key);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void SkyboxManager::Load(const std::string& key, const std::string& path, float len = 30.0f);
	///
	/// \brief	Same as PrivLoad(key, path), but accessible to users through the resource loader source file.
	///
	/// \param 	key 	The string key used to return the skybox.
	/// \param 	path	Relative pathname of the skybox's texture file. Starts in the project's Assets\Textures folder.
	/// \param	len		(Optional) The length of the skybox's dimensions.
	/// 				
	/// Choosing the correct length may take some trial and error. We think 30 is a good size, hence why it's
	/// our default length.
	///
	/// Note that all textures MUST be in the .tga format.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Load(const std::string& key, const std::string& path, float len = 30.0f);
};

#endif
