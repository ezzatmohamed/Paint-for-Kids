#include "PickT_F.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
#include "..\..\Figures\CFigure.h"
#include <string>
PickT_F::PickT_F(ApplicationManager *pApp):PlayGame(pApp)
{
	Valid = 0 ;
	InValid = 0 ;
	type = NOTYPE;
	
} 

void PickT_F :: ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();

	

		pIn->GetPointClicked(P.x,P.y);
		
		deleted = pManager->GetFigure(P.x,P.y);
		if( deleted )
		{
			if(type == undef)
			{
				type = deleted->getType();
				if(deleted->IsFilled())
				{
					F = deleted->getFillColor();
					isFill=true;
				}
				else
					isFill = false;
				total = pManager->FiguresCountT_F(type,F,isFill);
				Valid++;
				Del = true;
				return;
			}
			FigureType testType =NOTYPE;
			color testColor;
			bool testFill;

			testType = deleted->getType();
			if(deleted->IsFilled())
			{
				testColor = deleted->getFillColor();
				testFill = true;
			}
			else
				testFill = false;
			if(testType == type)
			{
				if( !testFill && !isFill)
				{
					Valid++;
					Del = true;
				}
				else if( testFill && isFill)
				{
					if(deleted->getFillColor() == F)
					{
						Valid++;
						Del = true;
					}
					else
						InValid++;
				}
				else
				{
					InValid++;
				}
			}
			else
			{
				InValid++;
			}
		}
		else if(IsRestart(P))
		{
			Valid = 0;
			InValid = 0;
			pManager->restartGame(Figs,count);
			type = NOTYPE;
			return;
		}
		else if(GoBack(P))
		{
			pOut->CreatePlayToolBar();
			return;
		}
}

void  PickT_F:: Execute()
{
	PlayGame:: Execute();
}

