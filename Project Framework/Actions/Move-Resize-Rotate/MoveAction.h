#include "..\Action.h"

#pragma once


class MoveAction :
	public Action
{
private:
	Point P; //Rectangle Corners

public:
	MoveAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;

};
