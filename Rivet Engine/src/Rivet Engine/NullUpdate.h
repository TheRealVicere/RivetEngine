#ifndef NullUpdate_H
#define NullUpdate_H

#include "IUpdateCallback.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	NullUpdate
///
/// \brief	An update callback that does nothing.
///
/// \author	Mike Piunti
/// \date	06/02/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class NullUpdate : public IUpdateCallback {
public:
	NullUpdate() = default;
	NullUpdate(const NullUpdate&) = delete;
	NullUpdate& operator=(const NullUpdate&) = delete;
	~NullUpdate() = default;

	void Update() override {}
};

#endif
