#include "RotateAction.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"

RotateAction::RotateAction(ApplicationManager *pApp):Action(pApp)
{
}


void RotateAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Rotating Figures .");
	ActionType act;
	while(1)
	{
		act = pIn->GetUserAction();
		switch(act)
		{
		case ROTATE_90:
			degree= 90;
			return;
		case ROTATE_180:
			degree= 180;
			return;
		case ROTATE_270:
			degree= 270;
			return;
		case GO_BACK:
			degree=0;
			pOut->CreateOthersBar();
			return;
		}
	}
   
}
	
void RotateAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	if( pManager->GetSelectCount() == 0)
	{
		pManager->ErrorMsgSelect();
		return;
	}
	pOut->CreateRotateBar();
	while(pOut->getMode() == MODE_ROTATE)
	{

     ReadActionParameters();
	 pManager->Rotate(degree);
	 pManager->UpdateInterface();
	}

}
