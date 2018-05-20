#include"..\Action.h"

#pragma once

class FillColorAction : public Action
{
private:
	color New;
	bool chng,fill;

public:
	FillColorAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	 void Execute() ;

};
