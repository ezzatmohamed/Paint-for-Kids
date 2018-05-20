#include "WidthAction.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
WidthAction::WidthAction(ApplicationManager *pApp):Action(pApp)
{
	chng = true;
}

void WidthAction :: ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();

	pOut->PrintMessage("Changing Selected Figures Width: Choose one of the shown sizes .");
	

	ActionType act;

	while(1)
	{
		act = pIn->GetUserAction();
		switch(act)
		{
		case size1:
			New = 1;
			pOut->CreateOthersBar();
			return;
		case size2:
			New = 2;
			pOut->CreateOthersBar();
			return;
		case size4:
			New = 4;
			pOut->CreateOthersBar();
			return;
		case size8:
			New = 9;
			pOut->CreateOthersBar();
			return;
		case TO_OTHERS :
			chng = false;
			pOut->CreateOthersBar();
			return;

		}
	}
}

void WidthAction:: Execute()
{
	Output * pOut = pManager->GetOutput();

    pOut->CreateWidthBar();
	ReadActionParameters();
	if(chng)
	{
		pManager->ChngSWidth(New);
		pManager->ChngCWidth(New);
	}
}

