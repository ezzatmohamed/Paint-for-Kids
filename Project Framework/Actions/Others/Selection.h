#pragma once
#include"..\Action.h"
#include "..\..\Figures\CFigure.h"



class Selection : public Action
{
	Point P1;
public :


	Selection(ApplicationManager *pApp);

	virtual void ReadActionParameters();


	virtual void Execute();

};