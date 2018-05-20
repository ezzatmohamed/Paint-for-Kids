#include"Action.h"
#pragma once

class ExitAction :
	public Action
{
	bool save;
	bool exit;
public:
	ExitAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
	bool ExitBar(Point P);
};