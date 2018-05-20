#include"..\Action.h"
#include "..\..\GUI\UI_Info.h"
#include "..\../Figures/CFigure.h"
#pragma once

class PlayGame : public Action
{
protected :
	int Valid;
	int InValid;
	int total;
	Point P;
	CFigure **Figs;
	CFigure* deleted;
	int count;
	bool Del;
public :
	PlayGame(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters() = 0;
	
	//Add rectangle to the ApplicationManager
	 void Execute();

	 bool IsRestart(Point);
	 bool GoBack(Point);
	 void PlayError();


	 ~PlayGame();
};

