#include "PickArea.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
#include "..\..\Figures\CFigure.h"
#include <string>
PickArea::PickArea(ApplicationManager *pApp):PlayGame(pApp)
{
	Valid = 0 ;
	InValid = 0 ;
	Max = Min = NULL;
	Area = undef;
} 

void PickArea :: ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();
	deleted = NULL;

	pManager->MaxMinArea(Max,Min);
	pManager->UpdateInterface();

	
	pIn->GetPointClicked(P.x,P.y);
	
	deleted = pManager->GetFigure(P.x,P.y);

			if(IsRestart(P))
		    {
				Valid = 0;
				InValid = 0;
				pManager->restartGame(Figs,count);
				return;
		    }
			else if(GoBack(P))
	    	{
				pOut->CreatePlayToolBar();
				return;
		    }
			else if(!deleted)
				return;


	if( Area == undef)
	{
		if(deleted == Max)
		{
			Area = MAX;
			Valid++;
			Del = true;
		}
		else if(deleted == Min)
		{
			Area = MIN;
			Valid++;
			Del = true;
		}
		else
		{
			InValid++;
			deleted = NULL;
		}
		total = pManager->getFigCount();
	}
	else if( Area == MAX )
	{
		if(deleted == Max)
		{
			Valid++;
			Del = true;
		}
		else
		{
			InValid++;
		}
	}

	else if( Area == MIN )
	{
		if(deleted == Min)
		{
			Valid++;
			Del = true;
		}
		else
		{
			InValid++;
		}
	}
}

void PickArea:: Execute()
{
	PlayGame::Execute();
}

