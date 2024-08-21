#ifndef SpriteFontManager_H
#define SpriteFontManager_H

#include <map>

class SpriteFont;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	SpriteFontManager
///
/// \brief	Manager for sprite fonts.
///
/// \author	Mike Piunti
/// \date	03/08/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class SpriteFontManager {
	friend class AssetAttorney;
private:
	SpriteFontManager() = default;
	SpriteFontManager(const SpriteFontManager&) = delete;
	SpriteFontManager& operator=(const SpriteFontManager&) = delete;
	~SpriteFontManager();

	/// \brief	The current instance of the sprite font manager.
	static SpriteFontManager* instance;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static SpriteFontManager* SpriteFontManager::Instance();
	///
	/// \brief	Gets the instance of the sprite font manager. Used to create an instance if none exists.
	///
	/// \returns	The current instance of the sprite font manager.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static SpriteFontManager* Instance();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void SpriteFontManager::Terminate();
	///
	/// \brief	Terminates the sprite font manager.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Terminate();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::map<MapKey, SpriteFont*> FontMap
	///
	/// \brief	Defines an alias representing the map used to store sprite fonts by key.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::map<std::string, SpriteFont*> FontMap;
	FontMap storageMap;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void SpriteFontManager::PrivLoad(const std::string& key, const std::string& path);
	///
	/// \brief	Stores a font for later use. The given key is used to return the stored font.
	/// 		Note that keys must be unique.
	/// 		
	/// \param	key		The string key to load the font with.
	/// \param	path	Relative pathname of the font's texture file. Starts in the project's Assets\Fonts folder.
	/// 				
	/// Note that font paths exclude the file extension as both a .tga and a .xml will be read.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void PrivLoad(const std::string& key, const std::string& path);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	SpriteFont* SpriteFontManager::PrivGet(const std::string& key);
	///
	/// \brief	Returns a sprite font previously loaded with a given key.
	///
	/// \param 	key	The string key the font was loaded with.
	///
	/// \returns	A pointer to the sprite font stored with the given key.
	/// 			Crashes in debug mode if the key does not exist.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	SpriteFont* PrivGet(const std::string key);

public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void SpriteFontManager::Load(const std::string& key, const std::string& path);
	///
	/// \brief	Stores a font for later use. The given key is used to return the stored font.
	/// 		Note that keys must be unique.
	/// 		
	/// \param	key		The string key to load the font with.
	/// \param	path	Relative pathname of the font's texture file. Starts in the project's Assets\Fonts folder.
	/// 				
	/// Note that font paths exclude the file extension as both a .tga and a .xml will be read.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Load(const std::string& key, const std::string& path);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static SpriteFont* SpriteFontManager::Get(const std::string key);
	///
	/// \brief	Returns a sprite font previously loaded with a given key.
	///
	/// \param 	key	The string key the font was loaded with.
	///
	/// \returns	A pointer to the sprite font stored with the given key.
	/// 			Crashes in debug mode if the key does not exist.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static SpriteFont* Get(const std::string key);
};

#endif
