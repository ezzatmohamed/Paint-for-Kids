#include "Background.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
Background::Background(ApplicationManager *pApp):Action(pApp)
{}

void Background :: ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();

	pOut->PrintMessage("Changing BackGround Color: Choose one of the shown colors .");
	

	ActionType act;

	while(1)
	{
		act = pIn->GetUserAction();
		switch(act)
		{
		case CHNG_BLACK:
			New = BLACK;
			return;
		case CHNG_BLUE:
			New = BLUE;
			return;
		case CHNG_CYAN:
			New = color(222,243,251);
			return;
		case CHNG_GREEN:
			New = GREEN;
			return;
		case CHNG_ORANGE:
			New = ORANGE;
			return;
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
			pOut->CreateSubColorBar();
			New  = pOut->getBkgrColor();
			return;
		}
	}
}

void Background:: Execute()
{
	Output * pOut = pManager->GetOutput();
	pOut->CreateColorsBar();

	ReadActionParameters();

	pManager->ChngBckClr(New);

	pOut->CreateSubColorBar();
}

