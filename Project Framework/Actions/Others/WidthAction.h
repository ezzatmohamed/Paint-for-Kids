#include"..\Action.h"

#pragma once

class WidthAction : public Action
{
private:
	int New;
	bool chng;
public:
	WidthAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	 void Execute() ;


};
