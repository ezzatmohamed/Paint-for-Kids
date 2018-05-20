#include "..\Action.h"
#include "PlayGame.h"
#pragma once


class Scrumble :
	public PlayGame
{
private:
	CFigure ** ScramList;
	CFigure * SelectedFig;
	CFigure*test;

public:
	Scrumble(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute();

	void DeleteFig(int ID);


};
