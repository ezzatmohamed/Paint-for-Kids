#include "ExitAction.h"
#include "..\Figures\Circle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ExitAction::ExitAction(ApplicationManager *pApp):Action(pApp)
{}

void ExitAction :: ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();


	string image ="images\\exit.jpg";

	pOut->Drawimage(image,(UI.width - 435)/2, (UI.height - 135)/2,435,135);

	Point P;

	do
	{
		pIn->GetPointClicked(P.x,P.y);
		
	}while(!ExitBar(P));

	


	pOut->ClearStatusBar();

}

void ExitAction:: Execute()
{

	ReadActionParameters();

	pManager->IsExit(save,exit);
}

bool ExitAction:: ExitBar(Point P) 
{
	    if( P.x  >( (UI.width/2) -97)  && P.x  < ( (UI.width/2) - 12 ) && P.y  < ( (UI.height/2) + 53) && P.y  > ( (UI.height/2) +29 ))
		{
			save = true;
			exit = true;
			return true;
		}
		else if( P.x  > ( (UI.width/2))  && P.x  < ( (UI.width/2) + 111) && P.y  < ( (UI.height/2) + 53) && P.y  > ( (UI.height/2) +29 ))
		{
			save = false;
			exit = true;
			return true ;
		}
		else if( P.x  > ( (UI.width/2) + 120)  && P.x  < ( (UI.width/2) + 206) && P.y  < ( (UI.height/2) + 53) && P.y  > ( (UI.height/2) +29 ))
		{
			save = false;
			exit = false;
			return true;
		}
		return false;
}












