#include"..\Action.h"
#include "PlayGame.h"
#include "..\..\GUI\UI_Info.h"
#pragma once

class PickType : public PlayGame
{
private :
	
	FigureType type;
public :
	PickType(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	 void Execute() ;

};

