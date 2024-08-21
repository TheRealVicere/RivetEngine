#ifndef GodCamUpdate_H
#define GodCamUpdate_H

#include "Matrix.h"

#include "IUpdateCallback.h"

class Camera;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	GodCamUpdate
///
/// \brief	An update callback for the god camera.
///
/// \author	Mike Piunti
/// \date	05/10/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class GodCamUpdate : public IUpdateCallback {
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	GodCamUpdate::GodCamUpdate(Camera* c);
	///
	/// \brief	Creates a callback for the god camera.
	///
	/// \param	c	The actual camera object to update.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	GodCamUpdate(Camera* c);

	GodCamUpdate() = delete;
	GodCamUpdate(const GodCamUpdate&) = delete;
	GodCamUpdate& operator=(const GodCamUpdate&) = delete;
	~GodCamUpdate() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn void GodCamUpdate::Update();
	///
	/// \brief	Updates the god camera this frame.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void Update() override;

private:
	/// \brief	The god camera to update.
	Camera* godCam;

	/// \brief	The camera's rotation matrix.
	Matrix rot;

	/// \brief	The camera's position.
	Vect pos;

	/// \brief	(Immutable) The camera's up vector.
	const Vect up = Vect(0, 1, 0);

	/// \brief	(Immutable) The camera's direction vector.
	const Vect dir = Vect(0, 0, 1);

	/// \brief	(Immutable) The camera's speed.
	const float speed = 1;

	/// \brief	(Immutable) The camera's rotation angle per frame.
	const float rotAng = 0.01f;
};

#endif
