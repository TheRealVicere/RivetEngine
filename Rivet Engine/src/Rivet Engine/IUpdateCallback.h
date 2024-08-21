#ifndef IUpdateCallback_H
#define IUpdateCallback_H

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	IUpdateCallback
///
/// \brief	A callback to perform the duties of an update component.
///
/// \author	Mike Piunti
/// \date	04/12/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class IUpdateCallback {
public:
	IUpdateCallback() = default;
	IUpdateCallback(const IUpdateCallback&) = delete;
	IUpdateCallback& operator=(const IUpdateCallback&) = delete;
	virtual ~IUpdateCallback() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void IUpdateCallback::Update() = 0;
	///
	/// \brief	Updates an object for this frame.
	/// 		
	/// This is where all movement, resizing, raw input handling, and more should be handled.
	/// Exact implementation is entirely defined by the user for each derived game object.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Update() = 0;
};

#endif
