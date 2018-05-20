#include "ZoomAction.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
ZoomAction::ZoomAction(ApplicationManager *pApp):Action(pApp)
{
	ZoomFactor = 1;
}

void ZoomAction :: ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();

	pOut->PrintMessage("Zooming In/Out .");
	
	ActionType act;
	while(1)
	{
		act = pIn->GetUserAction();
		switch(act)
		{
		case ZOOM_IN:
			ZoomFactor= 1.5;
			return;
		case ZOOM_OUT:
			ZoomFactor= float(2/3.0);
			return;
		case GO_BACK:
			pOut->CreateDrawToolBar();
			ZoomFactor=1;
			return;
		}
	}	
	pOut->ClearStatusBar();

}

void ZoomAction:: Execute()
{

	Output* pOut = pManager->GetOutput();
	pOut->CreateZoomBar();
	while(pOut->getMode() == MODE_ZOOM)
	{
		ReadActionParameters();
		pManager->Zoom(ZoomFactor);
		pManager->UpdateInterface();
	}

	

}

