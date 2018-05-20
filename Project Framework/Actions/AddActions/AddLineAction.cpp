#include "AddLineAction.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
AddLineAction::AddLineAction(ApplicationManager *pApp):Action(pApp)
{
}

void AddLineAction:: ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at First Corner.");
	
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at Second Corner.");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	

	LineGfxInfo.isFilled = false;//default is not filled
	//get drawing, filling colors and pen width from the interface

	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}

void AddLineAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
		
	if(!CLine::CheckLine(P1,P2))
		{
			pManager->ErrorMsg();
			return ;
		}
	
	//Create a rectangle with the parameters read from the user
	
	CLine *R=new CLine(P1,P2 , LineGfxInfo);

		//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	return ;
}

