#include"..\Action.h"

#pragma once


//Add Rectangle Action class
class AddRecAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	AddRecAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute();
	
};

