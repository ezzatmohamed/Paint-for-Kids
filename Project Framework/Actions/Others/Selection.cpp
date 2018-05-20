#include"Selection.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
Selection::Selection(ApplicationManager *pApp):Action(pApp)
{

}

void Selection::ReadActionParameters()
{
		 
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	
	pIn->GetPointClicked(P1.x,P1.y);
	
	if(P1.x >0 && P1.x < UI.MenuItemWidth && P1.y >0 && P1.y < UI.ToolBarHeight )
		pOut->CreateDrawToolBar();


}

	 
void Selection::Execute()
{
		 Output* pOut = pManager->GetOutput();
	     Input* pIn = pManager->GetInput();

		 if(pManager->getFigCount() == 0)
		 {
			 pOut->PrintMessage("There is nothing to select . Click anywhere to continue.");
			 double x,y;
	    	 pIn->GetPointClicked(x,y);
		     pOut->ClearStatusBar();
		     return;
		 }

		 pOut->PrintMessage("Selecting Figures: Click on a Figure to select / deselect it.");
		 pOut->CreateSelectToolBar();

		 while( pOut->getMode() == MODE_SELECT )
		 {

		         ReadActionParameters();
	        	 pManager->Select(P1);
		  		 pManager->UpdateInterface();

		 }

}
