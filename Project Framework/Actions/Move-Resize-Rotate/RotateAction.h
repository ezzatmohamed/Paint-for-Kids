#include"..\Action.h"
#pragma once



class RotateAction : public Action
{
	float degree;
public :


	RotateAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();


	virtual void Execute();

};