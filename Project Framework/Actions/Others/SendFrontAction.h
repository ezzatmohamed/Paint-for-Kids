#include"..\Action.h"
#pragma once

class SendFrontAction :
	public Action
{


public:
	SendFrontAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
};