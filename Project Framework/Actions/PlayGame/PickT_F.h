#include "PlayGame.h"

#include "..\Action.h"
#include "..\..\GUI\UI_Info.h"
#pragma once

class PickT_F : public PlayGame
{
	FigureType type;
	color F;
	bool isFill;

public :
	PickT_F(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	 void Execute() ;

};

