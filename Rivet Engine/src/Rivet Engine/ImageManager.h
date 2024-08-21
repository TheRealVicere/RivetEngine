#ifndef ImageManager_H
#define ImageManager_H

#include <map>

class Image;
struct Rect;
class Texture;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	ImageManager
///
/// \brief	Manager for images. Loads, stores, and accesses images for use in games.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class ImageManager {
	friend class AssetAttorney;
private:
	ImageManager() = default;
	ImageManager(const ImageManager&) = delete;
	ImageManager& operator=(const ImageManager&) = delete;
	~ImageManager();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Image* ImageManager::PrivGet(const std::string& key);
	///
	/// \brief	Returns an image previously loaded with a given key.
	///
	/// \param 	key	The string key the image was loaded with.
	///
	/// \returns	A pointer to the image stored with the given key.
	/// 			Crashes in debug mode if the key does not exist.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Image* PrivGet(const std::string& key);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void ImageManager::PrivLoad(const std::string& key, Texture* tex);
	///
	/// \brief	Stores an image for later use. The given key is used to return the stored image.
	/// 		Note that keys must be unique.
	/// 		
	/// \param	key	The string key to load the image with.
	/// \param	tex	The texture to use for the image.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void PrivLoad(const std::string& key, Texture* tex);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void ImageManager::PrivLoad(const std::string& key, Texture* tex, Rect* r);
	///
	/// \brief	Stores part of an image for later use. The given key is used to return the stored image.
	/// 		Note that keys must be unique.
	/// 		
	/// \param	key	The string key to load the image with.
	/// \param	tex	The texture to use for the image.
	/// \param	r	The rectangle containing the part of the texture to keep.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void PrivLoad(const std::string& key, Texture* tex, Rect* r);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static ImageManager* ImageManager::Instance();
	///
	/// \brief	Gets the instance of the image manager. Used to create an instance if none exists.
	///
	/// \returns	The current instance of the image manager.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static ImageManager* Instance();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void ImageManager::Terminate();
	///
	/// \brief	Terminates the image manager.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Terminate();

	/// \brief	The current instance of the image manager.
	static ImageManager* instance;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::string MapKey
	///
	/// \brief	Defines an alias representing the key used to return an image.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::string MapKey;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::map<MapKey, Image*> ImageMap
	///
	/// \brief	Defines an alias representing the map used to store images by key.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::map<MapKey, Image*> ImageMap;

	/// \brief	(Immutable) The default relative path to search for images.
	static const std::string defaultPath;

	/// \brief	The map which stores images for later use.
	ImageMap storageMap;

public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static Image* ImageManager::Get(const std::string& key);
	///
	/// \brief	Same as PrivGet(key), but accessible to users through the resource loader source file.
	///
	/// \param 	key	The string key the image was loaded with.
	///
	/// \returns	A pointer to the image stored with the given key.
	/// 			Crashes in debug mode if the key does not exist.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static Image* Get(const std::string& key);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void ImageManager::Load(const std::string& key, const std::string& path);
	///
	/// \brief	Stores an image for later use. The given key is used to return the stored image.
	/// 		Note that keys must be unique.
	///
	/// \param	key	The string key to load the image with.
	/// \param	tex	The texture to use for the image.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Load(const std::string& key, Texture* tex);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void ImageManager::Load(const std::string& key, const std::string& path, Rect* r);
	///
	/// \brief	Stores part of an image for later use. The given key is used to return the stored image.
	/// 		Note that keys must be unique.
	/// 		
	/// \param	key	The string key to load the image with.
	/// \param	tex	The texture to use for the image.
	/// \param	r	The rectangle containing the part of the texture to keep.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Load(const std::string& key, Texture* tex, Rect* r);
};

#endif
