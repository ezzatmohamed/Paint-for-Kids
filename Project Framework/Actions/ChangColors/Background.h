#include"..\Action.h"

#pragma once

class Background :	public Action
{

	color New;
	
public:
	Background(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
};


