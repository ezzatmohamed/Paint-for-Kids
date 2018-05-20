#include"..\Action.h"
#pragma once

class PasteAction :
	public Action
{
	Point P;
public:
	PasteAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	

};