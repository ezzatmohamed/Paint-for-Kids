#include"..\Action.h"
#pragma once

class ZoomAction :
	public Action
{
	float ZoomFactor;
public:
	ZoomAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	

};