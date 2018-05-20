#include "AddRecAction.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"

AddRecAction::AddRecAction(ApplicationManager * pApp):Action(pApp){}


void AddRecAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1   
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	
	
	if( pOut->getIsFilled() )
	{
		RectGfxInfo.FillClr = pOut->getCrntFillColor();
		RectGfxInfo.isFilled = true;
	}
	else
		RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface

	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}

//Execute the action
void AddRecAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	if(!CRectangle::CheckRect(P1,P2))
		{
			pManager->ErrorMsg();
			return ;
		}
	//Create a rectangle with the parameters read from the user
	
		CRectangle *R = new CRectangle(P1, P2, RectGfxInfo);

		//Add the rectangle to the list of figures
		pManager->AddFigure(R);
}

/*

void ApplicationManager::bring2Front()
{
	int j = 0;
	GetSelected();
	for (int i = 0; i < FigCount; i++)
	{
		if (!FigList[i]->IsSelected())
		{
			FigList[j] = FigList[i];
			j++;
		}
	}
	cout << "j Has Reached " << j << " While Bringing Not Selected Figures to Front.\n";
	for (int i = 0; i < selectedCount; i++)
	{
		FigList[j] = selected[i];
		j++;
	}
	cout << "j Has Reached " << j << " While Bringing Selected Figures to Front.\n";
	return;
} 

*/