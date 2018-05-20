#include"..\Action.h"
#pragma once

class CutAction :
	public Action
{



public:
	CutAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;

};