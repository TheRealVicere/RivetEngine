#ifndef TextureManager_H
#define TextureManager_H

#include <map>

class Texture;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	TextureManager
///
/// \brief	Manager for textures. Loads, stores, and accesses textures for use in games.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class TextureManager {
	friend class AssetAttorney;
private:
	TextureManager() = default;
	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	~TextureManager();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Texture* TextureManager::PrivGet(const std::string& key);
	///
	/// \brief	Returns a texture previously loaded with a given key.
	///
	/// \param 	key	The string key the texture was loaded with.
	///
	/// \returns	A pointer to the texture stored with the given key.
	/// 			Crashes in debug mode if the key does not exist.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Texture* PrivGet(const std::string& key);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void TextureManager::PrivLoad(const std::string& key, const std::string& path);
	///
	/// \brief	Stores a texture for later use. The given key is used to return the stored texture.
	/// 		Note that keys must be unique.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void PrivLoad(const std::string& key, const std::string& path);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static TextureManager* TextureManager::Instance();
	///
	/// \brief	Gets the instance of the texture manager. Used to create an instance if none exists.
	///
	/// \returns	The current instance of the texture manager.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static TextureManager* Instance();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void TextureManager::Terminate();
	///
	/// \brief	Terminates the texture manager.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Terminate();

	/// \brief	The current instance of the texture manager.
	static TextureManager* instance;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::string MapKey
	///
	/// \brief	Defines an alias representing the key used to return a texture.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::string MapKey;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::map<MapKey, Texture*> TextureMap
	///
	/// \brief	Defines an alias representing the map used to store textures by key.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::map<MapKey, Texture*> TextureMap;

	/// \brief	(Immutable) The default relative path to search for textures.
	static const std::string defaultPath;

	/// \brief	The map which stores textures for later use.
	TextureMap storageMap;

public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static Texture* TextureManager::Get(const std::string& key);
	///
	/// \brief	Same as PrivGet(key), but accessible to users through the resource loader source file.
	///
	/// \param 	key	The string key the texture was loaded with.
	///
	/// \returns	A pointer to the texture stored with the given key.
	/// 			Crashes in debug mode if the key does not exist.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static Texture* Get(const std::string& key);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void TextureManager::Load(const std::string& key, const std::string& path);
	///
	/// \brief	Same as PrivLoad(key, path), but accessible to users through the resource loader source file.
	///
	/// \param 	key 	The string key used to return the texture.
	/// \param 	path	Relative pathname of the texture file. Starts in the project's Assets\Textures folder.
	///
	/// Note that all textures MUST be in the .tga format.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Load(const std::string& key, const std::string& path);
};

#endif
