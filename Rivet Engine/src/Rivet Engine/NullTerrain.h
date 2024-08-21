#ifndef NullTerrain_H
#define NullTerrain_H

#include "Terrain.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	NullTerrain
///
/// \brief	A terrain that does nothing.
///
/// \author	Mike Piunti
/// \date	06/02/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class NullTerrain : public Terrain {
public:
	NullTerrain();
	NullTerrain(const NullTerrain&) = delete;
	NullTerrain& operator=(const NullTerrain&) = delete;
	~NullTerrain() = default;

	void Render() override {}
};

#endif
