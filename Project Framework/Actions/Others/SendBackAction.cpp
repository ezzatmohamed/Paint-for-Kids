#include "SendBackAction.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
SendBackAction::SendBackAction(ApplicationManager *pApp):Action(pApp)
{
}

void SendBackAction :: ReadActionParameters()
{
	//empty.
}

void SendBackAction:: Execute()
{
	if( pManager->GetSelectCount() == 0)
	{
		pManager->ErrorMsgSelect();
		return;
	}
	pManager->SendFigsBack();
}
