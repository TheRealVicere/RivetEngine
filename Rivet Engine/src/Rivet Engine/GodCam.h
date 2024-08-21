#ifndef GodCam_H
#define GodCam_H

#include "Matrix.h"

#include "Actor.h"

class Camera;
class GodCamInput;
class GodCamUpdate;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	GodCam
///
/// \brief	A free camera used during debugging, independent from the game camera.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class GodCam : public Actor {
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	GodCam::GodCam(Camera* const mCam);
	///
	/// \brief	Constructs a new god camera.
	///
	/// \param [in,out]	mCam	The main camera.
	/// 				
	/// \par Example:
	/// This constructor passes the camera used for gameplay purposes since turning off the god camera
	/// disables the new camera entirely. This allows the camera manager to reuse the main gameplay camera
	/// when the god camera is not in use. Therefore, unless the user wishes to have more than one
	/// perspective camera in a scene, the best use of this function is as follows:
	/// \code
	/// 	 GodCam gc(SceneManager::GetCurrent()->GetCurrent3DCamera());
	/// \endcode
	////////////////////////////////////////////////////////////////////////////////////////////////////
	GodCam(Camera* const mCam);

	GodCam() = delete;
	GodCam(const GodCam&) = delete;
	GodCam& operator=(const GodCam&) = delete;
	~GodCam();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void GodCam::Toggle();
	///
	/// \brief	Toggles the use of the god camera.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void Toggle();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void GodCam::EnterScene() override;
	///
	/// \brief	Enables the god camera.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void EnterScene() override;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void GodCam::EnterScene() override;
	///
	/// \brief	Disables the god camera.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void ExitScene() override;
private:
	/// \brief	The update callback.
	GodCamUpdate* up;

	/// \brief	The input callback.
	GodCamInput* in;

	/// \brief	Whether the god camera is in use.
	bool inUse;

	/// \brief	The god camera.
	Camera* godCam;

	/// \brief	The main camera to use when the god camera is disabled.
	Camera* mainCam;
};

#endif
