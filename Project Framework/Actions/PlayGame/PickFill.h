#include"..\Action.h"
#include "PlayGame.h"
#include "..\..\GUI\UI_Info.h"
#pragma once

class PickFill : public PlayGame
{
private :
	
	color FillC;
	bool isFill;
	bool start;
public :
	PickFill(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	 void Execute() ;


};

