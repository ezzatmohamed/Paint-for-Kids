#include"..\Action.h"
#pragma once



class Resize : public Action
{
	float ratio;
public :


	Resize(ApplicationManager *pApp);

	virtual void ReadActionParameters();


	virtual void Execute();


	
};