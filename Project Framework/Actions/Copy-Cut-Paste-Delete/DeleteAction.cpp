#include "DeleteAction.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
#include "..\..\Figures\CFigure.h"
DeleteAction::DeleteAction(ApplicationManager *pApp):Action(pApp)
{
}

void DeleteAction :: ReadActionParameters()
{
	//empty.
}

void DeleteAction:: Execute()
{
	if( pManager->GetSelectCount() == 0)
	{
		pManager->ErrorMsgSelect();
		return;
	}
   pManager->Delete();
}
