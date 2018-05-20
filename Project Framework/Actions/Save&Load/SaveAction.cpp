#include "SaveAction.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
SaveAction::SaveAction(ApplicationManager *pApp):Action(pApp)
{
}

void SaveAction :: ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();
	pOut->PrintMessage("Enter a name for your saved file. ");
	
	name = pIn->GetSrting(pOut);
	
	pOut->ClearStatusBar();

}

void SaveAction:: Execute()
{
	ReadActionParameters();
	pManager->Save(name);
	
}

