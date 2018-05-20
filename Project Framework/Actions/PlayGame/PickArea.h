#include"..\Action.h"
#include "PlayGame.h"
#include "..\..\GUI\UI_Info.h"
#include "..\..\Figures\CFigure.h"
#pragma once

class PickArea : public PlayGame
{
private :
	CFigure *Max;
	CFigure *Min;
	TypeArea Area ;
	bool start;
public :
	PickArea(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	 void Execute() ;


};

