#include "MoveAction.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"

MoveAction::MoveAction(ApplicationManager *pApp):Action(pApp)
{
}

void MoveAction::ReadActionParameters()
{
		 
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Moving Figures: Click on a point to move the selected figures.");
	
	pIn->GetPointClicked(P.x, P.y);

	pOut->ClearStatusBar();		 
	 
}

	 
void MoveAction::Execute()
{
	if(UI.ZoomFactor !=1)
		return;
	if( pManager->GetSelectCount() == 0)
	{
		pManager->ErrorMsgSelect();
		return;
	}
		 ReadActionParameters();
		pManager->Move(P);
}

