#ifndef IDrawCallback_H
#define IDrawCallback_H

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	IDrawCallback
///
/// \brief	A callback to perform the duties of a draw component.
/// 		User-defined derived classes should hold the necessary graphics objects for drawing.
///
/// \author	Mike Piunti
/// \date	04/12/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class IDrawCallback {
public:
	IDrawCallback() = default;
	IDrawCallback(const IDrawCallback&) = delete;
	IDrawCallback& operator=(const IDrawCallback&) = delete;
	virtual ~IDrawCallback() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void IDrawCallback::Draw() = 0;
	///
	/// \brief	Draws an object's models this frame.
	/// 		
	/// Usually, this method simply calls the object's models' render functions:
	/// \code
	/// 	void MyObject::Draw() {
	/// 		model1->Render(SceneManager::GetCurrent()->GetCurrent3DCamera());
	/// 		model2->Render(SceneManager::GetCurrent()->GetCurrent3DCamera());
	/// 		// And so on...
	/// 	}
	/// \endcode
	/// The user should define this as an empty function if only Draw2D() is needed.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Draw() = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void IDrawCallback::Draw2D() = 0;
	///
	/// \brief	Renders this object's sprites on the screen.
	///
	/// Usually, this method simply calls the object's sprites' render functions:
	/// \code
	/// 	void MyObject::Draw2D() {
	/// 		sprite1->Render(SceneManager::GetCurrent()->GetCurrent2DCamera());
	/// 		sprite2->Render(SceneManager::GetCurrent()->GetCurrent2DCamera());
	/// 		// And so on...
	/// 	}
	/// \endcode
	/// The user should define this as an empty function if only Draw3D() is needed.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Draw2D() = 0;
};

#endif
