#ifndef NullDraw_H
#define NullDraw_H

#include "IDrawCallback.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	NullDraw
///
/// \brief	A draw callback that does nothing.
///
/// \author	Mike Piunti
/// \date	06/02/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class NullDraw : public IDrawCallback {
public:
	NullDraw() = default;
	NullDraw(const NullDraw&) = delete;
	NullDraw& operator=(const NullDraw&) = delete;
	~NullDraw() = default;

	void Draw() override {}
	void Draw2D() override {}
};

#endif
