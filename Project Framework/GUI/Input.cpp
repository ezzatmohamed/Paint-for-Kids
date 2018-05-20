#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(double &x, double &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{  
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
		{
			if( Label.size() != 0)
				Label.resize(Label.size() -1 );		
		}
		else
			Label+= Key;
		pO->PrintMessage(Label);
	}
}




string Input::CurrentSelect(Output *pO)const
{
	string x ;
	x = GetSrting(pO);
	/*
	    ( S & s ) For selected Figures .
	    ( C & c ) For Current Change .
	    ( B & b ) For Going back .
	
	*/
	while(x !="S" && x !="C" && x !="B" && x !="s" && x !="c" && x !="b")
	{
		pO->PrintMessage("You entered wrong choice, Please Enter ( C ) to change the current  / OR ( S ) for selected Figures  / OR ( B ) to cancel the operation .");
		x = GetSrting(pO);
	}

	return x;

}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	double x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	int ClickedItemOrder = (int(x) / UI.MenuItemWidth);

	if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}


else if ( y >= 0 && y < UI.ToolBarHeight)
  {
	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
	

		if(UI.SubMode == MODE_MAIN )
		{
			
				
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_ADD: return TO_ADD;
			case ITM_SELC: return SELEC;
			case ITM_COLOR: return TO_CHNG_COLOR;	
			case ITM_ZOOM: return ZOOM;
			case ITM_RESIZE: return RESIZE;
			case ITM_MOVE: return MOVE;
			case ITM_OTHERS: return TO_OTHERS;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_DELETE: return DEL;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_PLAY: return TO_PLAY;
			case ITM_EXIT: return	 EXIT;

			
			default: return EMPTY;	//A click on empty place in desgin toolbar
		}
		
			

		//[2] User clicks on the drawing area
		
		}
		else if(UI.SubMode == MODE_FIGURE)
			{
					
					switch(ClickedItemOrder)
					{
					case ITM_COLOR_BACK :return GO_BACK;
					case ITM_RECT :return DRAW_RECT;
					case ITM_TRI :return DRAW_TRI;
					case ITM_CIRC :return DRAW_CIRC;
					case ITM_LINE :return DRAW_LINE;
					default: return EMPTY;
					}
				

	         }
		else if(UI.SubMode == MODE_SELECT)
			{
					
					switch(ClickedItemOrder)
					{
					case ITM_DONE :return DONE;

					default: return EMPTY;
					}
				

	         }
		else if(UI.SubMode == MODE_SUB_COLOR)
			{
					
					switch(ClickedItemOrder)
					{
					case ITM_SUBCOLOR_BACK :return GO_BACK;
					case ITM_BACKGROUND :return BACKGROUND;
					case ITM_SFILLING :return SFILLING;
					case ITM_SDRAWING :return SDRAWING;
				
					default: return EMPTY;
					}
				
		
		  }

		else if(UI.SubMode == MODE_COLOR)
			{
				
					switch(ClickedItemOrder)
					{
					case ITM_COLOR_B : return TO_CHNG_COLOR;
					case ITM_RED :return CHNG_RED;
					case ITM_PINK :return CHNG_PINK;
					case ITM_ORANGE :return CHNG_ORANGE;
					case ITM_YELLOW :return CHNG_YELLOW;
					case ITM_GREEN :return CHNG_GREEN;
					case ITM_BLUE :return CHNG_BLUE;
					case ITM_CYAN :return CHNG_CYAN;
					case ITM_BLACK :return CHNG_BLACK;
					default: return EMPTY;
					}
				

			}
		else if(UI.SubMode == MODE_Fill_COLOR)
			{
				
					switch(ClickedItemOrder)
					{
					case ITM_COLOR_B1 : return TO_CHNG_COLOR;
					case ITM_UNFILL :return UNFILL;
					case ITM_RED1 :return CHNG_RED;
					case ITM_PINK1 :return CHNG_PINK;
					case ITM_ORANGE1 :return CHNG_ORANGE;
					case ITM_YELLOW1 :return CHNG_YELLOW;
					case ITM_GREEN1 :return CHNG_GREEN;
					case ITM_BLUE1 :return CHNG_BLUE;
					case ITM_CYAN1 :return CHNG_CYAN;
					case ITM_BLACK1 :return CHNG_BLACK;
					default: return EMPTY;
					}
				

			}
			else if(UI.SubMode == MODE_RESIZE)
			{
				
					switch(ClickedItemOrder)
					{
					case ITM_RESIZE_BACK :return GO_BACK;
					case ITM_QUARTER :return QUARTER;
					case ITM_HALF :return HALF;
					case ITM_DOUBLE :return DOUBLe;
					case ITM_FOUR :return FOUR;

					default: return EMPTY;
					}
				

			}
		    else if(UI.SubMode == MODE_WIDTH)
			{
				
					switch(ClickedItemOrder)
					{
					case ITM_WIDTH_BACK :return TO_OTHERS;
					case ITM_SIZE1 :return size1;
					case ITM_SIZE2 :return size2;
					case ITM_SIZE4 :return size4;
					case ITM_SIZE8 :return size8;

					default: return EMPTY;
					}
				

			}
			 else if(UI.SubMode == MODE_ZOOM)
			{
				
					switch(ClickedItemOrder)
					{
					case ZOOM_BACK :return GO_BACK;
					case ITM_IN :return ZOOM_IN;
					case ITM_OUT :return ZOOM_OUT;
					

					default: return EMPTY;
					}
				

			}
			 else if(UI.SubMode == MODE_ROTATE)
			{
				
					switch(ClickedItemOrder)
					{
					case ROTATE_BACK :return GO_BACK;
					case ITM_90 :return ROTATE_90;
					case ITM_180 :return ROTATE_180;
					case ITM_270 :return ROTATE_270;
					

					default: return EMPTY;
					}
				

			}
			else if(UI.SubMode == MODE_OTHERS)
			{
				
					switch(ClickedItemOrder)
					{
					case ITM_OTHERS_BACK    :return GO_BACK;
					case ITM_SWIDTH          :return CHNG_SWIDTH;
					case ITM_ROTATION       :return ROTATE;
					case ITM_SENDB           :return SENDB;
					case ITM_SENDF           :return SENDF;

					default: return EMPTY;
					}

			}
			
			
	
	}
	
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		
		if(UI.SubMode == MODE_PLAY_MAIN)
		{
		switch(ClickedItemOrder)
		{
		case ITM_PICK :return TO_PICK;
		case ITM_FIND :return TO_FIND;
		case ITM_DRAW :return TO_DRAW;
		case ITM_PLAY :return TO_PLAY;

		default: return EMPTY;
		}}
			else if(UI.SubMode == MODE_PICK)
			{
		      switch(ClickedItemOrder)
		      {    
		         case ITM_PICK_BACK :return TO_PLAY;
		        		case ITM_FILL :return BY_FILL;
		        		case ITM_TYPE :return BY_TYPE;
		        		case ITM_AREA :return BY_AREA;
		        		case ITM_BOTH :return BY_BOTH;
	

		        		default: return EMPTY;
	        	}
		   
		    }
		
	}
     }
	 return STATUS;
}	


/////////////////////////////////
	
Input::~Input()
{
}
