#include "PickFill.h"
#include "..\..\ApplicationManager.h"
#include "..\..\GUI\input.h"
#include "..\..\GUI\Output.h"
#include "..\..\Figures\CFigure.h"
#include <string>
PickFill::PickFill(ApplicationManager *pApp):PlayGame(pApp)
{
	Valid = 0 ;
	InValid = 0 ;
	start = true;
} 

void PickFill :: ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input  * pIn = pManager->GetInput();

	
		pIn->GetPointClicked(P.x,P.y);

		deleted = pManager->GetFigure(P.x,P.y);		
		if( deleted )
		{
			if( start )
			{
				if(deleted->IsFilled())
				{
					FillC= deleted->getFillColor();
					isFill = true;
				}
				else
					isFill = false;
				
				total = pManager->FigCountFill(FillC,isFill);
				Valid++;
				start = false;
				Del = true;
				return;
			}
			color testClr;
			bool testFill;

			if(deleted->IsFilled())
			{
				testClr = deleted->getFillColor();
				testFill=true;
			}
			else
				testFill= false;
			if(isFill)
			{
				if(!testFill)
				{
					InValid++;
				}
				else
				{
					if(testClr == FillC)
					{
						Valid++;	
						Del = true;
					}
					else
					{
						InValid++;
					}
				}
			}
		    else
		    {
				if(!testFill)
				{
					Valid++;
					Del = true;
				}
				else
				{
					InValid++;
				}
			}
		}
		else if(IsRestart(P))
		{
			Valid = 0;
			InValid = 0;
			pManager->restartGame(Figs,count);
			start = true;
			
			return;
		}
		else if(GoBack(P))
		{
			pOut->CreatePlayToolBar();
			return;
		}
}

void PickFill:: Execute()
{
	PlayGame:: Execute();
}
