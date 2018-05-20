#include "DrawColorAction.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
DrawColorAction::DrawColorAction(ApplicationManager *pApp):Action(pApp)
{
	chng = true;
}

void DrawColorAction :: ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();

	pOut->PrintMessage("Changing Selected Figures Drawing Color: Choose one of the shown colors .");
	
	 
	ActionType act;

	while(1)
	{
		act = pIn->GetUserAction();
		switch(act)
		{
		case CHNG_BLACK:
			New = BLACK;
			pOut->CreateSubColorBar();
			return;
		case CHNG_BLUE:
			New = BLUE;
			pOut->CreateSubColorBar();
			return;
		case CHNG_CYAN:
			New = color(222,243,251);;
			pOut->CreateSubColorBar();
			return;
		case CHNG_GREEN:
			New = GREEN;
			pOut->CreateSubColorBar();
			return;
		case CHNG_ORANGE:
			New = ORANGE;
			pOut->CreateSubColorBar();
			return;
		case CHNG_PINK:
			New = PINK;
			pOut->CreateSubColorBar();
			return;
		case CHNG_RED:
			New = RED;
			pOut->CreateSubColorBar();
			return;
		case CHNG_YELLOW:
			New = YELLOW;
			pOut->CreateSubColorBar();
			return;
			
		case TO_CHNG_COLOR:
		//	New = pOut->getCrntDrawColor();
			chng = false;
			pOut->CreateSubColorBar();
			return;
		}
	}
}

void DrawColorAction:: Execute()
{
	Output * pOut = pManager->GetOutput();
	pOut->CreateColorsBar();

	ReadActionParameters();

	if(chng)
	{
		pManager->ChngSDrawClr(New);
		pManager->ChngCDrawClr(New);
	}

	
}

