#include "SendFrontAction.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
SendFrontAction::SendFrontAction(ApplicationManager *pApp):Action(pApp)
{
}

void SendFrontAction :: ReadActionParameters()
{
	//empty.
}

void SendFrontAction:: Execute()
{
	if( pManager->GetSelectCount() == 0)
	{
		pManager->ErrorMsgSelect();
		return;
	}

	pManager->SendFigsFront();
}
