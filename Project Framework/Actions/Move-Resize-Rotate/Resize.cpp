#include "Resize.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"

Resize::Resize(ApplicationManager *pApp):Action(pApp)
{
	ratio = -1;
}


void Resize::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Resize Figures : Choose the Resize Ratio from the toolbar.");

	ActionType act ;
   while(1)
   {
	act = pIn->GetUserAction();
	switch(act)
	{
	case HALF:
		ratio = 1/2.0;
		pOut->CreateDrawToolBar();
		return;
	case QUARTER :
		ratio = 1/4.0;
		pOut->CreateDrawToolBar();
		return;
	case DOUBLe :
		ratio = 2.0;
		pOut->CreateDrawToolBar();
		return;
	case FOUR :
		ratio = 4;
		pOut->CreateDrawToolBar();
		return;
	case GO_BACK :
		pOut->CreateDrawToolBar();
		return;

	}

   }
}
	
void Resize::Execute()
{

	if( UI.ZoomFactor !=1)
		return;
	if( pManager->GetSelectCount() == 0)
	{
		pManager->ErrorMsgSelect();
		return;
	}
	 Output* pOut = pManager->GetOutput();

	 pOut->CreateResizeBar();
     
	 ReadActionParameters();

	 if(ratio == -1)
		 return ; 
	 pManager->resize(ratio) ;

 
}

