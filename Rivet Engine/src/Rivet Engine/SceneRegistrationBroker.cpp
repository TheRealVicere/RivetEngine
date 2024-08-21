#include "SceneRegistrationBroker.h"

#include "Command.h"

SceneRegistrationBroker::~SceneRegistrationBroker()
{
	cmdList.clear();
}

void SceneRegistrationBroker::AddCommand(Command* c)
{
	cmdList.push_back(c);
}

void SceneRegistrationBroker::ExecuteAll()
{
	for (Command* c : cmdList)
		c->Execute();
	cmdList.clear();
}
