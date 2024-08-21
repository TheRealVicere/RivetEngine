#ifndef ModelManager_H
#define ModelManager_H

#include <map>

#include "Model.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	ModelManager
///
/// \brief	Manager for models. Loads, stores, and accesses models for use in games.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class ModelManager {
	friend class AssetAttorney;
private:
	ModelManager() = default;
	ModelManager(const ModelManager&) = delete;
	ModelManager& operator=(const ModelManager&) = delete;
	~ModelManager();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Model* ModelManager::PrivGet(const std::string& key);
	///
	/// \brief	Returns a model previously loaded with a given key.
	///
	/// \param 	key	The string key the model was loaded with.
	///
	/// \returns	A pointer to the model stored with the given key.
	/// 			Crashes in debug mode if the key does not exist.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Model* PrivGet(const std::string& key);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void ModelManager::PrivLoad(const std::string& key, const Model::PreMadeModels pmm);
	///
	/// \brief	Stores a premade model for later use. The given key is used to return the stored model.
	/// 		Note that keys must be unique.
	///
	/// \param 	key	The string key used to return the model.
	/// \param 	pmm	The premade model to store.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void PrivLoad(const std::string& key, const Model::PreMadeModels pmm);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void ModelManager::PrivLoad(const std::string& key, const std::string& path);
	///
	/// \brief	Stores a custom Azul model for later use. The given key is used to return the stored model.
	/// 		Note that keys must be unique.
	/// 		
	/// \param 	key 	The string key used to return the model.
	/// \param 	path	Relative pathname of the model file. Starts in the project's Assets\Models folder.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void PrivLoad(const std::string& key, const std::string& path);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static ModelManager* ModelManager::Instance();
	///
	/// \brief	Gets the instance of the model manager. Used to create an instance if none exists.
	///
	/// \returns	The current instance of the model manager.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static ModelManager* Instance();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void ModelManager::Terminate();
	///
	/// \brief	Terminates the model manager.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Terminate();


	/// \brief	The current instance of the model manager.
	static ModelManager* instance;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::string MapKey
	///
	/// \brief	Defines an alias representing the key used to return a model.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::string MapKey;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::map<MapKey, Model*> ModelMap
	///
	/// \brief	Defines an alias representing the map used to store models by key.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::map<MapKey, Model*> ModelMap;
	

	/// \brief	(Immutable) The default relative path to search for models.
	static const std::string defaultPath;


	/// \brief	The map which stores models for later use.
	ModelMap storageMap;

public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static Model* ModelManager::Get(const std::string& key);
	///
	/// \brief	Same as PrivGet(key), but accessible to users through the resource loader source file.
	///
	/// \param 	key	The string key the model was loaded with.
	///
	/// \returns	A pointer to the model stored with the given key.
	/// 			Crashes in debug mode if the key does not exist.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static Model* Get(const std::string& key);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void ModelManager::Load(const std::string& key, const Model::PreMadeModels pmm);
	///
	/// \brief	Same as PrivLoad(key, pmm), but accessible to users through the resource loader source file.
	///
	/// \param 	key	The string key used to return the model.
	/// \param 	pmm	The premade model to store.
	/// 			
	/// \par Example:
	/// 
	/// The following is an example of how to store a generic sphere model:
	/// \code
	///		ModelManager::Load("Sphere", Model::PreMadeModels::UnitSphere);
	/// \endcode
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Load(const std::string& key, const Model::PreMadeModels pmm);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void ModelManager::Load(const std::string& key, const std::string& path);
	///
	/// \brief	Same as PrivLoad(key, path), but accessible to users through the resource loader source file.
	///
	/// \param 	key 	The string key used to return the model.
	/// \param 	path	Relative pathname of the model file. Starts in the project's Assets\Models folder.
	/// 				
	///	\par Example:
	///
	/// The following is an example of how to store an arbitrary model:
	/// \code
	///		ModelManager::Load("My Model", "CoolModel.azul");
	/// \endcode
	/// Note that all models MUST be in the .azul format. A converter from .fbx to .azul will be
	/// included in the first release and onward for user convenience.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Load(const std::string& key, const std::string& path);
};

#endif
