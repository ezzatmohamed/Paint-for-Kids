#include "FillColorAction.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
FillColorAction::FillColorAction(ApplicationManager *pApp):Action(pApp)
{
	chng = true;
	fill = true;
}

void FillColorAction :: ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();

	pOut->PrintMessage("Changing Selected Figures Filling Color: Choose one of the shown colors .");
	
	 
	ActionType act;

	while(1)
	{
		act = pIn->GetUserAction();
		switch(act)
		{
		case CHNG_BLACK:
			New = BLACK;
			return;
        case UNFILL:
			fill = false;
			return;
		case CHNG_BLUE:
			New = BLUE;
			return;
		case CHNG_CYAN:
			New = color(222,243,251);;
			return;
		case CHNG_GREEN:
			New = GREEN;
			return;
		case CHNG_ORANGE:
			New = ORANGE;
			return;break;
		case CHNG_PINK:
			New = PINK;
			return;
		case CHNG_RED:
			New = RED;
			return;
		case CHNG_YELLOW:
			New = YELLOW;
			return;
			
		case TO_CHNG_COLOR:
			chng = false;
			return;
		}
	}
}

void FillColorAction:: Execute()
{
	Output * pOut = pManager->GetOutput();
	pOut->CreateFillColorsBar();

	ReadActionParameters();

	if(chng)
	{
		pManager->ChngSFillClr(New,fill);
		pManager->ChngCFillClr(New,fill);
	}

	pOut->CreateSubColorBar();

	
}
