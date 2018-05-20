#include"..\Action.h"
#pragma once

class LoadAction :
	public Action
{
	string name;
	bool save;
	bool load;
public:
	LoadAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
	bool LoadBar(Point);


};