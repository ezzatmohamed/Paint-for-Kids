#include "PickType.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
#include "..\..\Figures\CFigure.h"
#include <string>
PickType::PickType(ApplicationManager *pApp):PlayGame(pApp)
{
	Valid = 0 ;
	InValid = 0 ;
	type = NOTYPE;
} 

void PickType :: ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x,P.y);

	FigureType test =NOTYPE;
	
	deleted = pManager->GetFigure(P.x,P.y);
	if(deleted)
	{
		if(type == NOTYPE)
		{
		    type = deleted->getType();
			total = pManager->FiguresCount(type);
			Valid++;
			Del = true;
			return;
		}
		test = deleted->getType();
		if(test == type)
	    {
			Valid++;
			Del = true;
		}
		else
		{
			InValid++;
		}
	}		
	else if(IsRestart(P))
	{
		Valid = 0;
		InValid = 0;
		pManager->restartGame(Figs,count);
		type = NOTYPE;
		return;
	}
	else if(GoBack(P))
	{
		pOut->CreatePlayToolBar();
		return;
	}
}

void PickType:: Execute()
{
	PlayGame:: Execute();
}

