#include"..\Action.h"
#pragma once

class SendBackAction :
	public Action
{


public:
	SendBackAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
};