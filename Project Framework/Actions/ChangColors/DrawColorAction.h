#include"..\Action.h"

#pragma once

class DrawColorAction : public Action
{
private:
	color New;
	bool chng;
public:
	DrawColorAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	 void Execute() ;

};
