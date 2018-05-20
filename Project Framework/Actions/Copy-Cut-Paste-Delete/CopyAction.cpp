#include "CopyAction.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
#include "..\..\Figures\CFigure.h"
CopyAction::CopyAction(ApplicationManager *pApp):Action(pApp)
{
}

void CopyAction :: ReadActionParameters()
{
	//empty.
}

void CopyAction:: Execute()
{
	if( pManager->GetSelectCount() == 0)
	{
		pManager->ErrorMsgSelect();
		return;
	}

	Output *pOut = pManager->GetOutput();
	Input * pIn = pManager->GetInput();
	pOut->PrintMessage("Copying Selected Figures . click anywhere to continue.");
	double x,y;
	pIn->GetPointClicked(x,y);
	pOut->ClearStatusBar();
	pManager->Copy();
}
