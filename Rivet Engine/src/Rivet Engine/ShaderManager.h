#ifndef ShaderManager_H
#define ShaderManager_H

#include <map>

class ShaderObject;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	ShaderManager
///
/// \brief	Manager for shaders. Loads, stores, and accesses shaders for use in games.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class ShaderManager {
	friend class AssetAttorney;
private:
	ShaderManager() = default;
	ShaderManager(const ShaderManager&) = delete;
	ShaderManager& operator=(const ShaderManager&) = delete;
	~ShaderManager();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Shader* ShaderManager::PrivGet(const std::string& key);
	///
	/// \brief	Returns a shader previously loaded with a given key.
	///
	/// \param 	key	The string key the shader was loaded with.
	///
	/// \returns	A pointer to the shader stored with the given key.
	/// 			Crashes in debug mode if the key does not exist.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	ShaderObject* PrivGet(const std::string& key);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void ShaderManager::PrivLoad(const std::string& key, const std::string& path);
	///
	/// \brief	Stores a shader for later use. The given key is used to return the stored shader.
	/// 		Note that keys must be unique.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void PrivLoad(const std::string& key, const std::string& path);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static ShaderManager* ShaderManager::Instance();
	///
	/// \brief	Gets the instance of the shader manager. Used to create an instance if none exists.
	///
	/// \returns	The current instance of the shader manager.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static ShaderManager* Instance();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void ShaderManager::Terminate();
	///
	/// \brief	Terminates the shader manager.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Terminate();

	/// \brief	The current instance of the shader manager.
	static ShaderManager* instance;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::string MapKey
	///
	/// \brief	Defines an alias representing the key used to return a shader.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::string MapKey;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::map<MapKey, Shader*> ShaderMap
	///
	/// \brief	Defines an alias representing the map used to store shaders by key.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::map<MapKey, ShaderObject*> ShaderMap;

	/// \brief	(Immutable) The default relative path to search for shaders.
	static const std::string defaultPath;

	/// \brief	The map which stores shaders for later use.
	ShaderMap storageMap;


public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static Shader* ShaderManager::Get(const std::string& key);
	///
	/// \brief	Same as PrivGet(key), but accessible to users through the resource loader source file.
	///
	/// \param 	key	The string key the shader was loaded with.
	///
	/// \returns	A pointer to the shader stored with the given key.
	/// 			Crashes in debug mode if the key does not exist.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static ShaderObject* Get(const std::string& key);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void ShaderManager::Load(const std::string& key, const std::string& path);
	///
	/// \brief	Same as PrivLoad(key, path), but accessible to users through the resource loader source file.
	///
	/// \param 	key 	The string key used to return the shader.
	/// \param 	path	Relative pathname of the shader file. Starts in the project's Assets\Shaders folder.
	/// 				Note that the path should not contain the file extension.
	/// 
	/// The resource loader contains every shader for user convenience. Comment out those not needed, and
	/// use the rest with whatever keys the user deems appropriate.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Load(const std::string& key, const std::string& path);
};

#endif
