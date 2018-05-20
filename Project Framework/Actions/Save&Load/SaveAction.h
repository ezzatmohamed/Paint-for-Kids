#include"..\Action.h"
#pragma once

class SaveAction :
	public Action
{
	string name;
public:
	SaveAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute();
};