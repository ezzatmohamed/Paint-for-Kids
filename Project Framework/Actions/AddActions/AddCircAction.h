#include"..\Action.h"

#pragma once

class AddCircAction : public Action
{
private:
	Point P1,P2; //Rectangle Corners
	GfxInfo CircGfxInfo;
public:
	AddCircAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	 void Execute() ;

};

