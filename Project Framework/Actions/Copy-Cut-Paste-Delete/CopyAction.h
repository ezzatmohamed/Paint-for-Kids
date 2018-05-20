#include"..\Action.h"
#pragma once

class CopyAction :
	public Action
{


public:
	CopyAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
};