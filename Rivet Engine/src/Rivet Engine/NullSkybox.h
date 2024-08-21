#ifndef NullSkybox_H
#define NullSkybox_H

#include "Skybox.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	NullSkybox
///
/// \brief	A skybox that does not get rendered.
///
/// \author	Mike Piunti
/// \date	06/02/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class NullSkybox : public Skybox {
public:
	NullSkybox() : Skybox("Textures/NullTexture.tga", 0.0f) {}
	NullSkybox(const NullSkybox&) = delete;
	NullSkybox& operator=(const NullSkybox&) = delete;
	~NullSkybox() = default;

	void Render() override {}
};

#endif
