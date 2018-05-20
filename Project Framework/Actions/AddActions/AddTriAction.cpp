#include"AddTriAction.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager *pApp):Action(pApp)
{
}

void AddTriAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");
	
	//Read 1st corner and store in point P1   
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

    pIn->GetPointClicked(P3.x, P3.y);


	
	if( pOut->getIsFilled() )
	{
		TriGfxInfo.FillClr = pOut->getCrntFillColor();
		TriGfxInfo.isFilled = true;
	}
	else
		TriGfxInfo.isFilled = false;	//default is not filled	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
	TriGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}

//Execute the action
void AddTriAction::Execute() 
{
	//This action needs to read some parameters first
		
	ReadActionParameters();

	if(!CTriangle::CheckTri(P1,P2,P3))
		{
			pManager->ErrorMsg();
			return;
		}
	//Create a rectangle with the parameters read from the user
	
	CTriangle *R=new CTriangle(P1, P2,P3,TriGfxInfo);

		//Add the rectangle to the list of figures
		pManager->AddFigure(R);
}