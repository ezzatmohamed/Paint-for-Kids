#include "CutAction.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
#include "..\..\Figures\CFigure.h"
CutAction::CutAction(ApplicationManager *pApp):Action(pApp)
{
}

void CutAction :: ReadActionParameters()
{
	//empty.
}

void CutAction:: Execute()
{

	if( pManager->GetSelectCount() == 0)
	{
		pManager->ErrorMsgSelect();
		return;
	}

	Output *pOut = pManager->GetOutput();
	Input * pIn = pManager->GetInput();

	pManager->Copy();
	pManager->Delete();

	pOut->PrintMessage("Cutting Selected Figures . click anywhere to continue.");
	double x,y;
	pIn->GetPointClicked(x,y);
	pOut->ClearStatusBar();

}
