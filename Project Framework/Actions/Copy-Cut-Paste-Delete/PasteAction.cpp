#include "PasteAction.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
#include "..\..\Figures\CFigure.h"
PasteAction::PasteAction(ApplicationManager *pApp):Action(pApp)
{
}

void PasteAction :: ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();

	pOut->PrintMessage("Click at the point you want to paste figures to.");
	pIn->GetPointClicked(P.x,P.y);
	pOut->ClearStatusBar();
}

void PasteAction:: Execute()
{
	if( UI.ZoomFactor !=1)
		return;
	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();
	if(pManager->GetClipBoardCount() == 0)
	{
		pOut->PrintMessage("There is no Figures in the Clipboard . Click anywhere to continue.");
		double x,y;
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		return;
	}

	if( pManager->GetClipBoardCount() + pManager->getFigCount() > pManager->GetMaxFigCount())
	{
		pOut->PrintMessage("Error Pasting Figures ! .. Number of Figures is greater than The Maximum Number. Click anywhere to continue. ");
		double x,y;
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		return;
	}

	ReadActionParameters();
	pManager->Paste(P);
}

