#include "AddCircAction.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager *pApp):Action(pApp)
{}

void AddCircAction:: ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Circle center point.");
	
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at another point to set the radius.");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	

	if( pOut->getIsFilled() )
	{
		CircGfxInfo.FillClr = pOut->getCrntFillColor();
		CircGfxInfo.isFilled = true;
	}
	else
		CircGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface

	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}

void AddCircAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	float radius = float(sqrt(pow(P1.y-P2.y,2)+pow(P1.x-P2.x,2)));
	if(!CCircle::CheckCircle(P1,radius))
	{
		pManager->ErrorMsg();
		return ;
	}

	
	//Create a rectangle with the parameters read from the user

	CCircle *R=new CCircle(P1,radius , CircGfxInfo);

		//Add the rectangle to the list of figures
		pManager->AddFigure(R);

	
}

