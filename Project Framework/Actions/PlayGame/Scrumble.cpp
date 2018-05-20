#include "Scrumble.h"
#include "..\..\Figures\Circle.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"

Scrumble::Scrumble(ApplicationManager *pApp):PlayGame(pApp)
{
	pManager->scrum();
	
	pManager->CpyFigList(ScramList);
	
	pManager->RandomFigures(ScramList);

	SelectedFig = NULL;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Scrumble & Find : Find the Selected Figures in the right half side .");

}

void Scrumble::ReadActionParameters()
{
		 
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Point P;

	if(!SelectedFig)
		SelectedFig = pManager->RandSelect(ScramList);
	


	pManager->UpdateInterface();
	pManager->DrawScrumFigs(ScramList);


    test = NULL;

	while(!test)
	{
		pIn->GetPointClicked(P.x,P.y);
		test = pManager->GetFigure(P.x,P.y);
		if(IsRestart(P))
		{
			Valid = 0;
			InValid = 0;
			pManager->restartGame(Figs,count);
			pManager->scrum();
			pManager->CpyFigList(ScramList);
			pManager->RandomFigures(ScramList);
			SelectedFig = NULL;
	//		string msg = "Valid = " +std::to_string(Valid) + " , InValid = " + std::to_string(InValid);
			return;
		}
		else if(GoBack(P))
		{
			pOut->CreatePlayToolBar();
			return;
		}
	}

	if(test->getID() == SelectedFig->getID() )
	{
		Valid++;
		Del = true;
	    SelectedFig = NULL;
	}
	
	else
	{
		InValid++;
	}

}

void Scrumble::Execute()
{
	if(pManager->getFigCount() == 0)
	{ 
		PlayError();
		return;
	}
	 Output * pOut = pManager->GetOutput();
	 Input  * pIn = pManager->GetInput();
	 pManager->UpdateInterface();
	 pManager->DrawScrumFigs(ScramList);
	 string msg;
	 int ID;
	 while( pManager->getFigCount() != 0  && pOut->getMode() == MODE_GAME)
	{
		Del = false;
		 ReadActionParameters();
		 if(Del)
		 {
			 ID = test->getID();
			 DeleteFig(ID);
	         pManager->DelFig(ID);
		 }

		 pManager->UpdateInterface();
		 pManager->DrawScrumFigs(ScramList);
		 msg = "Valid = " +std::to_string(Valid) + " , InValid = " + std::to_string(InValid);
		 pOut->PrintMessage(msg);
	}
	


		
	 msg = "Valid = " +std::to_string(Valid) + " , InValid = " + std::to_string(InValid) + " , Game Over. Click anywhere to continue. ";

   pOut->PrintMessage(msg);
	
	pIn->GetPointClicked(P.x,P.y);

	pManager->restartGame(Figs,count);
	pManager->UpdateInterface();

	pOut->CreatePlayToolBar();


	pOut->ClearStatusBar();
}


void Scrumble :: DeleteFig(int ID)
{
	int FigCount = pManager->getFigCount();
	for(int i = 0 ; i < FigCount; i++)
	{
		if(ScramList[i]->getID() == ID)
		{
			delete ScramList[i];
			int j;
			for(j = i; j < FigCount - 1 ; j++)
				ScramList[j] = ScramList[j+1];
			ScramList[j] = NULL;
			return;
		}
	}
}
