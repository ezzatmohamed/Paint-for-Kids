#include "ApplicationManager.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	Exit = false;
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	ClipboardCount = 0;
	SelectFig = 0;

	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;

	for(int i=0; i<MaxFigCount; i++)
		ClipboardList[i] = NULL;	

}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}

Point ApplicationManager :: AvgCenterSelc( CFigure * L[], int Count)
{
	Point Avg;
	Avg.x = Avg.y = 0;
	int counter = 0;
	for(int i =0;i < Count;i++)
		{
			if(L[i]->IsSelected())
			{
				Avg = Avg + L[i]->getcenter();
				counter++;
			}
		}
		Avg * (1.0/counter);
		return Avg;
}

void ApplicationManager :: Rotate(double angle)
{
		for(int i =0;i < FigCount;i++)
		{
			if(FigList[i]->IsSelected())
			{
				if(!FigList[i]->rotate(angle))
				{
					for(int k = i; k >= 0; k--)
					{
						if(FigList[k]->IsSelected())
						{
							FigList[k]->rotate(-angle);
						}
					}
					ErrorMsg();
					return;
				}
			}
		}	
	
}

void ApplicationManager :: Move(Point NewCenter)
{
		Point delta;
		Point OldCenter = AvgCenterSelc(FigList , FigCount);
		for(int i =0;i < FigCount;i++)
		{
			if(FigList[i]->IsSelected())
			{
				delta = OldCenter - FigList[i]->getcenter();
				if(!FigList[i]->Move(NewCenter - delta))
				{
					for(int k = i; k >= 0; k--)
					{
						if(FigList[k]->IsSelected())
						{
							delta = NewCenter- FigList[k]->getcenter();
							FigList[k]->Move(OldCenter - delta);
						}
					}
					ErrorMsg();
					return;
				
				}
			}
		}
}

void ApplicationManager :: resize(float ratio)
{	
		for(int i =0;i < FigCount;i++)
		{
			if(FigList[i]->IsSelected())
			{
				if(!FigList[i]->Resize(ratio))
				{
					for(int k = i; k >= 0; k--)
					{
						if(FigList[k]->IsSelected())
						{
							FigList[k]->Resize(1/ratio);
						}
					}
					ErrorMsg();
					return;
				}
			}
		}	
}

bool ApplicationManager:: Select(Point P)
{
	int count =0;
	CFigure *ptr = GetFigure(P.x,P.y);
		 if(ptr !=NULL)
		 {
			 if(ptr->IsSelected())
			 {
				 ptr->SetSelected(false);
				 SelectFig--;
			 }
			 else
			 {
			   ptr->SetSelected(true);
			   SelectFig++;
			 }

			 return true;

		 }
		 else 
		 {
			 return false;
		 }


}

void ApplicationManager:: ChngBckClr(color Bclr)
{
	pOut->chngBckClr(Bclr);
}

void ApplicationManager:: ChngCFillClr(color Bclr,bool fill)
{
	if(fill)
	{
		pOut->chngFillClr(Bclr);
		pOut->setFilled(true);
	}
	else
		pOut->setFilled(false);
}

void ApplicationManager:: ChngCDrawClr(color Bclr)
{
	pOut->chngDrawClr(Bclr);
}

void ApplicationManager :: ChngCWidth(int New)
{
	UI.PenWidth = New;
}


void ApplicationManager:: ClearClipBoard()
{
	for( int i =0 ;i<ClipboardCount; i++)
	{
		delete ClipboardList[i];
		ClipboardList[i] = NULL;
	}
	ClipboardCount =0;
}

void ApplicationManager:: Copy()
{
	ClearClipBoard();
	for(int i =0;i < FigCount;i++)
			if(FigList[i]->IsSelected())
				ClipboardList[ClipboardCount++] = FigList[i]->cpy();
}
		
void ApplicationManager::Paste(Point P)
{
	CFigure *F;
	Point delta;
	Point OldCenter = AvgCenterSelc(ClipboardList , ClipboardCount);

	for(int i =0 ; i < ClipboardCount;i++)
	{
		F = ClipboardList[i]->cpy();
		delta = OldCenter - F->getcenter();

		F->SetSelected(true);
		AddFigure(F);
		if(!F->Move(P - delta))
		{
			for(int k = i; k >= 0; k--)
			{
				delete FigList[--FigCount];
				FigList[FigCount]= NULL;
			}
			ErrorMsg();
			return;
		}
	}
	SelectFig += ClipboardCount;
	F = NULL;
}

void ApplicationManager::SendFigsBack()
{
	CFigure **selected = new CFigure*[SelectFig];
	int k = FigCount-1,s=0,i;
	for(i = FigCount-1 ; i >= 0;i--)
	{
		if(!FigList[i]->IsSelected())
			FigList[k--] = FigList[i];
		else
			selected[s++] = FigList[i];
	}
	for( i =0; i < SelectFig;i++)
		FigList[k--] = selected[i];

	delete selected;
}

void ApplicationManager::SendFigsFront()
{
	CFigure **selected = new CFigure*[SelectFig];
	int k = 0,s=0,i;
	for(i = 0 ; i <FigCount;i++)
	{
		if(!FigList[i]->IsSelected())
			FigList[k++] = FigList[i];
		else
			selected[s++] = FigList[i];
	}
	for( i =0; i < SelectFig;i++)
		FigList[k++] = selected[i];

	delete selected;
}

void ApplicationManager::Zoom(float Factor)
{
	if(!pOut->setZoom(Factor))
	{
		Point P;
		pOut->PrintMessage("Error !! You reached the maximum limit of zooming out.Click anywhere to continue.");
		pIn->GetPointClicked(P.x,P.y);
		pOut->ClearStatusBar();
	}
}

void ApplicationManager :: Delete()
{
	int k =0;
	CFigure *temp;
	for(int i =0; i < FigCount; i++)
	{
		if(!FigList[i]->IsSelected())
		{
			temp = FigList[i];
			FigList[i] = NULL;
			FigList[k++] = temp;
		}
		else
		{
			delete FigList[i];
			FigList[i] = NULL;
		}
	}
	FigCount = k;
	SelectFig = 0;
}

void ApplicationManager::ChngSFillClr(color Fclr,bool fill)
{
	for(int i =0;i < FigCount;i++)
		{
			if(FigList[i]->IsSelected())
			{
				if(fill)
					FigList[i]->ChngFillClr(Fclr);
				else
					FigList[i]->SetFilled(fill);
			}
		}
}

void ApplicationManager::ChngSDrawClr(color Fclr)
{

	for(int i =0;i < FigCount;i++)
		{
			if(FigList[i]->IsSelected())
			{
				FigList[i]->ChngDrawClr(Fclr);
			}
		}
}

void ApplicationManager::ChngSWidth(int New)
{

	for(int i =0;i < FigCount;i++)
		{
			if(FigList[i]->IsSelected())
			{
				FigList[i]->ChngWidth(New);
			}
		}
}

void ApplicationManager::Save(string name)
{
	ofstream output;
	
	output.open(name + ".txt");

	output << ColorToString(UI.DrawColor)<< "    ";

	if(pOut->getIsFilled())
		output << ColorToString(UI.FillColor)<<"    ";
	else 
		output << "NOT_FILLED" << "    ";

	output <<ColorToString(UI.BkGrndColor)<< "      ";

	output <<endl << FigCount <<endl;
	for(int i =0; i <FigCount; i++)
	{
		FigList[i]->PrintInfo(output);
	}
}

void ApplicationManager :: Load(string name)
{

	ifstream input;
	input.open(name + ".txt");
	if(!input.is_open())
	{
		pOut->PrintMessage("No File exists with this name . Please Click anywhere to continue.");
		double x,y;
		pIn->GetPointClicked(x,y);
		pOut->ClearStatusBar();
		return;
	}

	string clrString;
	input >> clrString ;
	pOut->chngDrawClr(ApplicationManager::stringToColor(clrString));

	input >> clrString;
	if(clrString == "NOT_FILLED")
		pOut->setFilled(false);
	else
		pOut->chngFillClr(ApplicationManager::stringToColor(clrString));

	input >> clrString;

	pOut->chngBckClr(ApplicationManager::stringToColor(clrString));

	
	int count ;
	input >> count;
	CFigure * Fig;


	ClearClipBoard();
	for(int i =0;i <FigCount;i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;

for(int i =0; i < count; i++)
{

	string type;
	input >> type; 
	if(type =="RECTANGLE")
		CRectangle::LoadFig(input,Fig);
	else if(type =="Triangle")
		CTriangle::LoadFig(input,Fig);
	else if(type =="Circle")
		CCircle::LoadFig(input,Fig);
	else
		CLine::LoadFig(input,Fig);

	AddFigure(Fig);
}
if(FigCount !=0)
	CFigure::setIdCount(FigList[FigCount-1]->getID());

}

void ApplicationManager::restartGame(CFigure **list,int count)
{
		FigCount = count;
		for(int i = 0; i <FigCount;i++)
		{
			delete FigList[i];
			FigList[i] = list[i]->cpy();
		}
}
	
void ApplicationManager::scrum() const
{
	for(int i =0 ; i < FigCount; i++)
	{
		FigList[i]->scram();
	}

}

void ApplicationManager::IsExit(bool save,bool exit)
{
	if(!exit)
		return;
	
	 Exit = true;
	 if(save)
	 {
		Action *pAct=NULL;
		pAct = new SaveAction(this);
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	 }

}

////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{

	case ROTATE :
		pAct = new RotateAction(this);
		break;
	case TO_ADD :
		pOut->CreateFigureToolBar();
		pOut->PrintMessage("Action: Add figure , Click any where. ");
		break;

		case MOVE :
			pAct = new MoveAction(this);
			break;

		case TO_CHNG_COLOR :
			pOut->CreateSubColorBar();
			break;

		case BACKGROUND :
			pAct = new Background(this);
			break;
	
		case SDRAWING:
			pAct = new DrawColorAction(this);
			break;
		case SFILLING:
			pAct = new FillColorAction(this);
			break;
	
			//   **  Figures Tool Bar Actions **  //
	

		         case GO_BACK :
			        pOut->PrintMessage("Action: Going back to Draw Mode , Click anywhere");
			        pOut->CreateDrawToolBar();
			        break;

		         case DRAW_RECT:
		        	pAct = new AddRecAction(this);
		        	break;
				case DRAW_TRI:
		        	pAct = new AddTriAction(this);
		        	break;

	           	case DRAW_LINE:
					pAct = new AddLineAction(this);
					break;               			//create AddLineAction here

			
					case DRAW_CIRC:
						pAct = new AddCircAction(this);
					break;      
			///////////////////////////////////////

					case SELEC:
						pAct = new Selection(this);
					break; 

					case RESIZE:
						pAct = new Resize(this);
					break; 

					case TO_OTHERS :
						pOut->CreateOthersBar();
						break;
					
						break;
					case CHNG_SWIDTH :
						pAct = new WidthAction(this);
						break;
					
					case CUT:
						pAct = new CutAction(this);
						break;
					case COPY :
						pAct = new CopyAction(this);
						break;

					case PASTE:
						pAct = new PasteAction(this);
						break;
					case DEL :
						pAct = new DeleteAction(this);
						break;
					case SAVE :
						pAct = new SaveAction(this);
						break;

					case LOAD :
						pAct = new LoadAction(this);
						break;
					case SENDB:
						pAct = new SendBackAction(this);
						break;
					case SENDF:
						pAct = new SendFrontAction(this);
						break;
					case ZOOM:
						pAct = new ZoomAction(this);
						break;
					case TO_PLAY:
						pOut->CreatePlayToolBar();
						break;
					case TO_PICK:
						pOut->CreatePickBar();
						break;
					case BY_TYPE:
						pAct = new PickType(this);
						break;
					case BY_FILL:
						pAct = new PickFill(this);
						break;
					case BY_BOTH:
						pAct = new PickT_F(this);
						break;
					case BY_AREA:
						pOut->PrintMessage("Picking By Area : Pick a Figure  .");
						pAct = new PickArea(this);
						break;
					case TO_FIND:
						pAct = new Scrumble(this);
						break;
			//   **  RESIZE  Tool Bar Actions **  //


			//////////////////////////////////////////
		case TO_DRAW :
			pOut->CreateDrawToolBar();
			break;

		case EXIT:
			pAct = new ExitAction(this);	
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{

		pAct->Execute();
		
			delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	
	}

}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures

void ApplicationManager::AddFigure(CFigure* pFig)
{
	if( FigList[FigCount] != NULL)
		delete FigList[FigCount];

	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}

void ApplicationManager::AddToClipboard(CFigure* pFig)
{
	ClipboardList[ClipboardCount++] = pFig;
}

void ApplicationManager :: CpyFigList(CFigure **&list) const
{

		list = new CFigure*[FigCount];
		for(int i =0;i<FigCount;i++)
		{
			list[i] = FigList[i]->cpy();
			FigList[i]->SetSelected(false);
		}
}

void ApplicationManager:: RandomFigures(CFigure **List)const
{
	for(int i = 0 ; i < FigCount; i++)
	{
		FigList[i]->RandFigure();
		FigList[i]->setID(List[i]->getID());
	}
}

void ApplicationManager :: DrawScrumFigs(CFigure **List)const
{

	for(int i =0; i< FigCount; i++)
		List[i]->Draw(pOut);

	GfxInfo LineGfxInfo;
	Point p1,p2;
	p1.x = p2.x = UI.width / 2;
	p1.y = UI.ToolBarHeight;
	p2.y = UI.height - UI.StatusBarHeight;

	LineGfxInfo.isFilled = false;
	LineGfxInfo.DrawClr = BLACK;
	LineGfxInfo.BorderWdth = 7;;
 
	pOut->DrawLINE(p1,p2,LineGfxInfo);

}

////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//							       Get Functions			        				//
//==================================================================================//
int ApplicationManager::GetSelectCount() const
{
	return SelectFig;
}

int ApplicationManager::GetClipBoardCount() const
{
	return ClipboardCount;
}

int ApplicationManager::GetMaxFigCount()const
{ return MaxFigCount ; }

int ApplicationManager::getFigCount()const
{
	return FigCount;
}

CFigure *ApplicationManager::GetFigure(double x, double y) const
{

	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	
	for(int i = FigCount-1 ;i >=0 ;i--)
	{
		if(FigList[i]->existFigure(x,y))
		{
			return FigList[i];
		}
	}
	///Add your code here to search for a figure given a point x,y	
	
	return NULL;
}

int ApplicationManager :: FiguresCount(FigureType T)
{
	int count = 0;
	int k =FigCount-1;
	int figcount = FigCount;
	CFigure *temp;

	for(int i =0; i < figcount;i++)
	{
		if(FigList[i]->getType() == T)
		{
			count++;
			temp = FigList[k];
			FigList[k--] = FigList[i];
			FigList[i] = temp;
			i--;
			figcount--;
		}
	}
	return count;
}

int ApplicationManager :: FigCountFill(color F,bool isFill)
{
	int count = 0;
	int k =FigCount-1;
	int figcount = FigCount;
	CFigure *temp;
	for(int i =0; i < figcount;i++)
	{

		if(  isFill && FigList[i]->IsFilled()   )
		{
			if( F == FigList[i]->getFillColor())
			{
				count++;
				temp = FigList[k];
		    	FigList[k--] = FigList[i];
			    FigList[i] = temp;
			    i--;
			    figcount--;
			}
		}
		else if( !isFill && !FigList[i]->IsFilled())
		{
			count++;
			temp = FigList[k];
			FigList[k--] = FigList[i];
		    FigList[i] = temp;
			i--;
			figcount--;
		}
	}
	return count;
}

int ApplicationManager :: FiguresCountT_F(FigureType T, color F,bool filled)
{
	int count = 0;

	int k =FigCount-1;
	int figcount = FigCount;
	CFigure *temp;

	for(int i =0; i < figcount;i++)
	{
		if(FigList[i]->getType() == T )
		{
			if( (filled && FigList[i]->IsFilled() && FigList[i]->getFillColor() == F ) || (!filled && !FigList[i]->IsFilled() ))
			count++;
			temp = FigList[k];
			FigList[k--] = FigList[i];
			FigList[i] = temp;
			i--;
			figcount--;
		}
	}
	return count;
}

bool ApplicationManager::getExit()const
{
	return Exit;
}

///////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::DelFig(int ID)
{

	for(int i =0 ; i < FigCount;i++)
	{
		if(ID == FigList[i]->getID())
		{
			delete FigList[i];
			int j;
			for(j = i; j < FigCount - 1 ; j++)
				FigList[j] = FigList[j+1];
			FigList[j] = NULL;
			FigCount--;
			return;
		}
	}
}

CFigure *ApplicationManager:: RandSelect(CFigure **&List) 	
{
	for(int i=0;i<FigCount;i++)
		List[i]->SetSelected(false);
	int z;
	do 
	{
		z = FigCount - rand()%(FigCount+1);
	}while(z < 0 || z > FigCount-1);
	List[z]->SetSelected(true);
	CFigure *temp;

	for (int j = 0; j<FigCount-1;j++)
	{
		if(FigList[j]->getID() == List[z]->getID())
		{
			temp = FigList[FigCount-1];
			FigList[FigCount-1] = FigList[j];
			FigList[j] = temp;
			break;
		}
	}
	return List[z];
}

void ApplicationManager:: MaxMinArea(CFigure *& Max ,CFigure *& Min)
{
	if(FigCount == 0)
	{
		Max = Min = NULL;
		return;
	}

	Max = Min = FigList[0];
	int k =0,h=0;
	if(FigCount == 1)
		return;
	for(int i = 1; i < FigCount; i++)
	{
		if( FigList[i]->getArea() > Max->getArea())
		{
			Max = FigList[i];
			h=i;
		}
		else if( FigList[i]->getArea() < Min->getArea())
		{
			Min = FigList[i];
			k=i;
		}
	}
	CFigure *temp = FigList[FigCount-1];
	FigList[FigCount-1] = Min;
	FigList[k] = temp;
	if(FigCount > 2)
	{
		temp = FigList[FigCount-2];
		FigList[FigCount-2] = Max;
		FigList[h] = temp;
	}
}



//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	
	pOut->ClearDrawArea();

	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	if( pOut->getZoomFactor() != 1)
	{
		
		if( pOut->getMode() == MODE_MAIN)
			pOut->CreateDrawToolBar();
		else if( pOut->getMode() == MODE_SUB_COLOR)
			pOut->CreateSubColorBar();
		else if( pOut->getMode() == MODE_COLOR)
			pOut->CreateColorsBar();
		else if ( pOut->getMode() == MODE_SELECT)
			pOut->CreateSelectToolBar();
		else
			pOut->CreateZoomBar();
	}
	if( pOut->getMode() == MODE_SELECT)
		PrintSelectMsg();

	//pOut->ClearStatusBar();
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor

void ApplicationManager::ErrorMsg() const
{

	pOut ->PrintMessage("Error .. The Figure is outside the Drawing Area. Click anywhere to continue. ");
	double x,y;
	pIn ->GetPointClicked(x,y);
	pOut->ClearStatusBar();
}

void ApplicationManager:: PrintSelectMsg()const
{
	string msg;
	 if( SelectFig > 1)
				 msg = " Number of Select Figure  : " + to_string(SelectFig);
	else if( SelectFig ==1)
	 {
		   for(int i =0 ; i < FigCount ; i++)
			if( FigList[i]->IsSelected())
			{
					FigList[i]->selectedInfo(msg);
					break;
			}
	 }
	 pOut->PrintMessage(msg);
}

void ApplicationManager::ErrorMsgSelect()const
{
	pOut->PrintMessage("Error ! ... None of the Figures is selected . Click anywhere to continue. ");
	double x,y;
	pIn->GetPointClicked(x,y);
	pOut->ClearStatusBar();
}

color ApplicationManager ::stringToColor(string s)
{
	if(s == "BLACK")
		return BLACK;
	else if(s == "RED")
		return RED;
	else if(s == "CYAN")
		return CYAN;
	else if(s == "YELLOW")
		return YELLOW;
	else if(s == "BLUE")
		return BLUE;
	else if(s == "ORANGE")
		return ORANGE;
	else if(s == "PINK")
		return PINK;
	else 
		return GREEN;
}

string ApplicationManager ::ColorToString(color s)
{
	if(s == BLACK)
		return "BLACK";
	else if(s == RED)
		return "RED";
	else if(s == CYAN)
		return "CYAN";
	else if(s == YELLOW)
		return "YELLOW";
	else if(s == BLUE)
		return "BLUE";
	else if(s == ORANGE)
		return "ORANGE";
	else if(s == PINK)
		return "PINK";
	else if( s ==GREEN)
		return "GREEN";
	else
		return "NOT_FILLED";
}

ApplicationManager::~ApplicationManager()
{
	int i = 0;

	ClearClipBoard();
	for(int i =0;i <FigCount;i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	for( i =0 ;i<ClipboardCount; i++)
	{
		delete ClipboardList[i];
		ClipboardList[i] = NULL;
	}

	delete pIn;
	delete pOut;
}

