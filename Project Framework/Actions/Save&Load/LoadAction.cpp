#include "LoadAction.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
LoadAction::LoadAction(ApplicationManager *pApp):Action(pApp)
{
}

void LoadAction :: ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();

	
	string image ="images\\Load.jpg";

	pOut->Drawimage(image,(UI.width - 435)/2, (UI.height - 135)/2,435,135);

	Point P;
	do
	{
		pIn->GetPointClicked(P.x,P.y);
		
	}while(!LoadBar(P));

	pManager->UpdateInterface();
	if(save)
	{
		Action *pAct  = new SaveAction(pManager);
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
	if(!load)
	{
		pOut->PrintMessage("Loading operation has been cancelled,Click anywhere to continue. ");
		pIn->GetPointClicked(P.x,P.y);
		pOut->ClearStatusBar();
		return;
	}

	pOut->PrintMessage("Enter the name of the file you want to Load. ");
	
	name = pIn->GetSrting(pOut);
	
	pOut->ClearStatusBar();
}

void LoadAction:: Execute()
{

	ReadActionParameters();
	if(load)
		pManager->Load(name);
}



bool LoadAction:: LoadBar(Point P) 
{
	    if( P.x  >( (UI.width/2) -97)  && P.x  < ( (UI.width/2) - 12 ) && P.y  < ( (UI.height/2) + 53) && P.y  > ( (UI.height/2) +29 ))
		{
			save = true;
			load = true;
			return true;
		}
		else if( P.x  > ( (UI.width/2))  && P.x  < ( (UI.width/2) + 111) && P.y  < ( (UI.height/2) + 53) && P.y  > ( (UI.height/2) +29 ))
		{
			save = false;
			load = true;
			return true ;
		}
		else if( P.x  > ( (UI.width/2) + 120)  && P.x  < ( (UI.width/2) + 206) && P.y  < ( (UI.height/2) + 53) && P.y  > ( (UI.height/2) +29 ))
		{
			save = false;
			load = false;
			return true;
		}
		return false;
}