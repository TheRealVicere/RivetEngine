#include "SphereDrawCommand.h"

#include "DebugAttorney.h"

SphereDrawCommand::SphereDrawCommand(const BSphere& S, const Vect& col) :
	sphere(S), color(col) {}

void SphereDrawCommand::Execute()
{
	float r = sphere.Radius();
	Vect c = sphere.Center();
	Matrix world(SCALE, r, r, r);
	world *= Matrix(TRANS, c);
	DebugAttorney::RenderSphere(world, color);
}
