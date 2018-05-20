#include "PlayGame.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
#include "..\..\Figures\CFigure.h"
#include <string>
PlayGame::PlayGame(ApplicationManager *pApp):Action(pApp)
{
	Valid = 0 ; 
	InValid = 0 ;
	
	pManager->CpyFigList(Figs);
	count = pManager->getFigCount();

	Output* pOut =pManager->GetOutput();
	pOut->CreateGameBar();
} 

void PlayGame::Execute()
{
	if(pManager->getFigCount() == 0)
	{ 
		PlayError();
		return;
	}

	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();

//	pManager->CpyFigList(Figs);
	string msg;
	pManager->UpdateInterface();
	while( Valid != total && pOut->getMode() == MODE_GAME )
	{
		Del = false;
		this->ReadActionParameters();
		if(Del)
			pManager->DelFig(deleted->getID());
		pManager->UpdateInterface();
	    msg = "Valid = " +std::to_string(Valid) + " , InValid = " + std::to_string(InValid);
		pOut->PrintMessage(msg);
	}
	pManager->restartGame(Figs,count);

	pOut->CreatePlayToolBar();
	
	 msg = "Valid = " +std::to_string(Valid) + " , InValid = " + std::to_string(InValid) + " , Game Over. Click anywhere to continue. ";

	pOut->PrintMessage(msg);

	pIn->GetPointClicked(P.x,P.y);
	pOut->ClearStatusBar();
}

bool PlayGame::IsRestart(Point P)
{
	if( P.y < UI.ToolBarHeight && P.y >0 && P.x > 0 && P.x < UI.MenuItemWidth)
		{
			return true;
		}
	return false;

}

bool PlayGame::GoBack(Point P)
{
		if( P.y < UI.ToolBarHeight && P.y >0 && P.x > UI.MenuItemWidth && P.x < UI.MenuItemWidth *2)
		{
			return true;
		}
	return false;
}

void PlayGame:: PlayError()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreatePickBar();
	pOut->PrintMessage("Error ! ... There is no Figures to play . Click anywhere to continue.");
	pIn->GetPointClicked(P.x,P.y);
	pOut->ClearStatusBar();
}

PlayGame:: ~PlayGame()
{
	 for (int i =0 ; i <pManager->getFigCount();i++)
		 {
			 delete Figs[i];
			 Figs[i]= NULL;
		 }
	 delete []Figs;
}
