#ifndef Debugger_H
#define Debugger_H

#include <list>

#include "Matrix.h"
#include "Vect.h"

#include "AABB.h"
#include "BSphere.h"

class CollisionDrawCommand;
class GraphicsObject_WireframeConstantColor;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	Debugger
///
/// \brief	A tool for debugging games using the Rivet Engine.
///
/// \author	Mike Piunti
/// \date	02/28/2023
////////////////////////////////////////////////////////////////////////////////////////////////////

class Debugger {
	friend class DebugAttorney;
private:
	Debugger();
	Debugger(const Debugger&) = delete;
	Debugger& operator=(const Debugger&) = delete;
	~Debugger();

	/// \brief	The current instance of the debugger.
	static Debugger* instance;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static Debugger* Debugger::Instance();
	///
	/// \brief	Gets the instance of the debugger. Used to create an instance if none exists.
	///
	/// \returns	The current instance of the debugger.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static Debugger* Instance();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Debugger::Terminate();
	///
	/// \brief	Terminates the debugger.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Terminate();

	/// \brief	The default debug render color.
	static Vect DEFAULT_COLOR;

	/// \brief	The sphere model used for drawing bounding spheres.
	GraphicsObject_WireframeConstantColor* sphere;

	/// \brief	The box used for drawing AABBs and OBBs.
	GraphicsObject_WireframeConstantColor* box;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void Debugger::RenderSphere(Matrix& m, const Vect& col);
	///
	/// \brief	Renders a sphere in the specified color using the specified world matrix.
	///
	/// \param	m  	The world matrix for the sphere.
	/// \param 	col	The color used to render the sphere.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void RenderSphere(Matrix& m, const Vect& col);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void Debugger::RenderBox(Matrix& m, const Vect& col);
	///
	/// \brief	Renders a box in the specified color using the specified world matrix.
	///
	/// \param	m  	The world matrix for the box.
	/// \param 	col	The color used to render the box.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void RenderBox(Matrix& m, const Vect& col);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void Debugger::DrawAll();
	///
	/// \brief	Renders every volume in the draw list.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void DrawAll();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::list<CollisionDrawCommand*> SphereList
	///
	/// \brief	Defines an alias representing the list of volume draw commands.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::list<CollisionDrawCommand*> VolumeList;

	/// \brief	The list of spheres to be drawn.
	VolumeList list;

	/// \brief	Whether debug mode is enabled.
	static bool debug;

	/// \brief	(Immutable) The width of a box used to represent a line.
	static const float LINE_OFFSET;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Debugger::ToggleDebug();
	///
	/// \brief	Toggles debug mode.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void ToggleDebug();

public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Debugger::ShowVolume(const CollisionVolume& v, const Vect& col = DEFAULT_COLOR);
	///
	/// \brief	Requests the debugger to draw the given collision volume this frame in the given color.
	///
	/// \param 	v  	The collision volume to draw.
	/// \param 	col	(Optional) The color in which to draw the bounding sphere.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void ShowVolume(const CollisionVolume& v, const Vect& col = DEFAULT_COLOR);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Debugger::ShowBSphere(const BSphere& S, const Vect& col = DEFAULT_COLOR);
	///
	/// \brief	Requests the debugger to draw the given bounding sphere this frame in the given color.
	///
	/// \param 	S  	The bounding sphere to draw.
	/// \param 	col	(Optional) The color in which to draw the bounding sphere.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void ShowBSphere(const BSphere& S, const Vect& col = DEFAULT_COLOR);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Debugger::ShowBox(const CollisionBox& B, const Vect& col = DEFAULT_COLOR);
	///
	/// \brief	Requests the debugger to draw the given collision box this frame in the given color.
	///
	/// \param 	B  	The collision box to draw.
	/// \param 	col	(Optional) The color in which to draw the box.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void ShowBox(const CollisionBox& B, const Vect& col = DEFAULT_COLOR);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void Debugger::ShowLine(const Vect& a, const Vect& b, const Vect& col);
	///
	/// \brief	Requests the debugger to draw the line segment between two points.
	///
	/// \param 	a  	The start point.
	/// \param 	b  	The end point.
	/// \param 	col	(Optional) The color in which to draw the line segment.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void ShowLine(const Vect& a, const Vect& b, const Vect& col = DEFAULT_COLOR);
};

#endif
