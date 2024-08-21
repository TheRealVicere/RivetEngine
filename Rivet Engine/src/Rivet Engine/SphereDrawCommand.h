#ifndef SphereDrawCommand_H
#define SphereDrawCommand_H

#include "BSphere.h"
#include "CollisionDrawCommand.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	SphereDrawCommand
///
/// \brief	A command to register bounding spheres for drawing.
///
/// \author	Mike Piunti
/// \date	04/02/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class SphereDrawCommand : public CollisionDrawCommand {
public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	SphereDrawCommand::SphereDrawCommand(const BSphere& S, const Vect& col);
	///
	/// \brief	Constructor.
	///
	/// \param	S	A bounding sphere to register for drawing.
	/// \param	col	The color in which the visual of the sphere will be rendered.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	SphereDrawCommand(const BSphere& S, const Vect& col);

	SphereDrawCommand() = delete;
	SphereDrawCommand(const SphereDrawCommand&) = delete;
	SphereDrawCommand& operator=(const SphereDrawCommand&) = delete;
	~SphereDrawCommand() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	virtual void SphereDrawCommand::Execute();
	///
	/// \brief	Registers the stored object for drawing.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void Execute();

private:
	/// \brief	The bounding sphere to render.
	BSphere sphere;

	/// \brief	The color to use for rendering.
	Vect color;
};

#endif
