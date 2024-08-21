#ifndef Skybox_H
#define Skybox_H

class GraphicsObject_TextureFlat;
class Model;
class Texture;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	Skybox
///
/// \brief	A default skybox for level design.
///
/// \author	Mike Piunti
/// \date	03/11/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class Skybox {
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Skybox::Skybox(const std::string textureFile, float len = 30.0f);
	///
	/// \brief	Constructor. Creates a skybox of size len in each dimension.
	///
	/// \param	textureFile		The filepath for the skybox texture. Starts at "Assets/Textures/".
	/// \param 	len	(Optional)	The length of the skybox's dimensions.
	/// 			
	/// Choosing the correct length may take some trial and error. We think 30 is a good size, hence why it's
	/// our default length.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Skybox(const std::string textureFile, float len = 30.0f);
	Skybox(const Skybox&) = delete;				 // Copy constructor
	Skybox& operator=(const Skybox&) = delete; // Copy assignment operator
	virtual ~Skybox();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void Skybox::Render();
	///
	/// \brief	Renders the skybox to the display.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Render();

private:
	/// \brief	The model the skybox will use.
	Model* model;

	/// \brief	The texture the skybox will use.
	Texture* tex;

	/// \brief	The graphics object used to render the model.
	GraphicsObject_TextureFlat* obj;
};

#endif
