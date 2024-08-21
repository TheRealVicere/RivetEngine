#include "Debugger.h"

#include "AzulCore.h"

#include "BoxDrawCommand.h"
#include "Colors.h"
#include "CollisionDrawCommand.h"
#include "ModelManager.h"
#include "Scene.h"
#include "SceneManager.h"
#include "ShaderManager.h"
#include "SphereDrawCommand.h"

Debugger* Debugger::instance = nullptr;
Vect Debugger::DEFAULT_COLOR = Colors::Blue;
bool Debugger::debug = false;
const float Debugger::LINE_OFFSET = 1.0f;

Debugger::Debugger()
{
	sphere = new GraphicsObject_WireframeConstantColor(ModelManager::Get("Sphere"),
		ShaderManager::Get("Constant"), DEFAULT_COLOR);
	box = new GraphicsObject_WireframeConstantColor(ModelManager::Get("Box"),
		ShaderManager::Get("Constant"), DEFAULT_COLOR);
}

Debugger::~Debugger()
{
	delete sphere;
	delete box;
	instance = nullptr;
}

Debugger* Debugger::Instance()
{
	if (!instance) instance = new Debugger;
	return instance;
}

void Debugger::Terminate()
{
	if (instance) delete instance;
}

void Debugger::RenderSphere(Matrix& m, const Vect& col)
{
	sphere->SetWorld(m);
	sphere->SetColor(col);
	sphere->Render(SceneManager::GetCurrent()->GetCurrent3DCamera());
}

void Debugger::RenderBox(Matrix& m, const Vect& col)
{
	box->SetWorld(m);
	box->SetColor(col);
	box->Render(SceneManager::GetCurrent()->GetCurrent3DCamera());
}

void Debugger::DrawAll()
{
	if (debug) {
		for (CollisionDrawCommand* cmd : list)
			cmd->Execute();
	}

	for (CollisionDrawCommand* cmd : list)
		delete cmd;
	list.clear();
}

void Debugger::ToggleDebug()
{
	debug = !debug;
}
void Debugger::ShowVolume(const CollisionVolume& v, const Vect& col)
{
	v.DebugView(col);
}

void Debugger::ShowBSphere(const BSphere& S, const Vect& col)
{
	Instance()->list.push_back(new SphereDrawCommand(S, col));
}

void Debugger::ShowBox(const CollisionBox& B, const Vect& col)
{
	Instance()->list.push_back(new BoxDrawCommand(B, col));
}

void Debugger::ShowLine(const Vect& a, const Vect& b, const Vect& col)
{
	Matrix w(SCALE, LINE_OFFSET, LINE_OFFSET, (b - a).mag());
	w *= Matrix(ROT_ORIENT, b - a, Vect(0, 1, 0));
	w *= Matrix(TRANS, 0.5f * (b + a));

	OBB line;
	line.ComputeData(Instance()->box->getModel(), w);
	Instance()->list.push_back(new BoxDrawCommand(line, col));
}
