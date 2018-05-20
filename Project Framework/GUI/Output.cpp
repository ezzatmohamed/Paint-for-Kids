#include "Output.h"


	
Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;
	UI.ZoomFactor =1;
	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	
	UI.DrawColor = BLUE;	                ///Drawing color
	UI.FillColor = GREEN;     	            //Filling color
	UI.isFilled = false;
	UI.MsgColor = BLACK;		            //Messages color
	UI.BkGrndColor = CYAN;	//Background color
	UI.HighlightColor = MAGENTA;  	        //This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = color(63,147,190);
	UI.PenWidth = 3;	                    //width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);

	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);

	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearToolBar() const
{
	//Clear Tool bar by drawing a filled white rectangle.
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0,0,UI.width,UI.ToolBarHeight);
	
	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////


void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	UI.SubMode = MODE_MAIN;
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];

	MenuItemImages[ITM_SELC] = "images\\MenuItems\\SELC.jpg";
	MenuItemImages[ITM_ZOOM] = "images\\MenuItems\\ZOOM.jpg";
	
	if(UI.ZoomFactor ==1)
	{
		MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Resize.jpg";
		MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
		MenuItemImages[ITM_OTHERS] = "images\\MenuItems\\others.jpg";
		MenuItemImages[ITM_PASTE] = "images\\MenuItems\\paste.jpg";
	    MenuItemImages[ITM_PLAY] = "images\\MenuItems\\play.jpg";
		MenuItemImages[ITM_ADD] = "images\\MenuItems\\add.jpg";

	}
	else
	{
		MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Resize2.jpg";
		MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move2.jpg";
		MenuItemImages[ITM_OTHERS] = "images\\MenuItems\\others2.jpg";
		MenuItemImages[ITM_PASTE] = "images\\MenuItems\\paste2.jpg";
		MenuItemImages[ITM_PLAY] = "images\\MenuItems\\play2.jpg";
		MenuItemImages[ITM_ADD] = "images\\MenuItems\\add2.jpg";

	}
	MenuItemImages[ITM_COLOR] = "images\\MenuItems\\change_color.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\cut.jpg";
	
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list
	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatePlayToolBar() const
{
	if( UI.ZoomFactor !=1)
		return;
	ClearToolBar();
	UI.InterfaceMode = MODE_PLAY;
	UI.SubMode = MODE_PLAY_MAIN;
	///TODO: write code to create Play mode menu

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[PLAY_ITM_COUNT];

	MenuItemImages[ITM_PICK] = "images\\PlayItems\\hide.jpg";
	MenuItemImages[ITM_FIND] = "images\\PlayItems\\find.jpg";
	MenuItemImages[ITM_DRAW] = "images\\PlayItems\\drawing.jpg";
	
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

		

	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
void Output :: CreateGameBar()const
{
	ClearToolBar();
	UI.SubMode = MODE_GAME;
	///TODO: write code to create Play mode menu

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[GAME_COUNT];

	MenuItemImages[ITM_RESTART] = "images\\PlayItems\\rotate.jpg";
	MenuItemImages[ITM_MENU] = "images\\PlayItems\\back.jpg";
	
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<GAME_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

		

	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}

void Output :: CreatePickBar()const
{
	ClearToolBar();
	UI.SubMode = MODE_PICK;
	///TODO: write code to create Play mode menu

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[PICK_ITM_COUNT];

	MenuItemImages[ITM_TYPE] = "images\\Pick&Hide\\type.jpg";
	MenuItemImages[ITM_FILL] = "images\\Pick&Hide\\byfilling.jpg";
	MenuItemImages[ITM_BOTH] = "images\\Pick&Hide\\both.jpg";
	MenuItemImages[ITM_AREA] = "images\\Pick&Hide\\area.jpg";
	MenuItemImages[ITM_PICK_BACK] = "images\\Pick&Hide\\back.jpg";
	
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<PICK_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

		

	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output:: CreateColorsBar()const
{
	ClearToolBar();
	UI.SubMode = MODE_COLOR;

	string MenuItemImages[COLORS_COUNTER];
	MenuItemImages[ITM_COLOR_B] = "images\\Colors\\back.jpg";
	MenuItemImages[ITM_BLUE] = "images\\Colors\\blue.jpg";
	MenuItemImages[ITM_RED] = "images\\Colors\\red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\Colors\\green.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\Colors\\orange.jpg";
	MenuItemImages[ITM_CYAN] = "images\\Colors\\cyan.jpg";
	MenuItemImages[ITM_PINK] = "images\\Colors\\pink.jpg";
	MenuItemImages[ITM_BLACK] = "images\\Colors\\black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\Colors\\yellow.jpg";
	
	for(int i=0; i<COLORS_COUNTER; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

	

	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
void Output:: CreateFillColorsBar()const
{
	ClearToolBar();
	UI.SubMode = MODE_Fill_COLOR;

	string MenuItemImages[COLORS_COUNTER1];
	MenuItemImages[ITM_COLOR_B1] = "images\\Colors\\back.jpg";
	MenuItemImages[ITM_UNFILL] = "images\\unfill.jpg";
	MenuItemImages[ITM_BLUE1] = "images\\Colors\\blue.jpg";
	MenuItemImages[ITM_RED1] = "images\\Colors\\red.jpg";
	MenuItemImages[ITM_GREEN1] = "images\\Colors\\green.jpg";
	MenuItemImages[ITM_ORANGE1] = "images\\Colors\\orange.jpg";
	MenuItemImages[ITM_CYAN1] = "images\\Colors\\cyan.jpg";
	MenuItemImages[ITM_PINK1] = "images\\Colors\\pink.jpg";
	MenuItemImages[ITM_BLACK1] = "images\\Colors\\black.jpg";
	MenuItemImages[ITM_YELLOW1] = "images\\Colors\\yellow.jpg";
	
	for(int i=0; i<COLORS_COUNTER1; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

	

	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
void Output:: CreateSubColorBar()const
{
	ClearToolBar();
	UI.SubMode = MODE_SUB_COLOR;

	string MenuItemImages[SUBCOLORW_COUNT];
	MenuItemImages[ITM_SUBCOLOR_BACK] = "images\\ChangeColor\\back.jpg";
	MenuItemImages[ITM_BACKGROUND] = "images\\ChangeColor\\background.jpg";
	MenuItemImages[ITM_SDRAWING] = "images\\ChangeColor\\current_drawing.jpg";
	MenuItemImages[ITM_SFILLING] = "images\\ChangeColor\\current_filling.jpg";
	

	for(int i=0; i<SUBCOLORW_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
void Output:: CreateSelectToolBar()const
{
	ClearToolBar();
	UI.SubMode = MODE_SELECT;

	string MenuItemImages[SELC_COUNT];
	MenuItemImages[ITM_DONE] = "images\\select\\done.jpg";
	
	
	for(int i=0; i<SELC_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}

void Output::CreateFigureToolBar() const
{
	if( UI.ZoomFactor !=1)
		return;

	ClearToolBar();
	UI.SubMode = MODE_FIGURE;
	///TODO: write code to create Play mode menu

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way ... READ MY SASD
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[FIGURE_ITM_COUNT];
	MenuItemImages[ITM_COLOR_BACK] = "images\\FiguresItems\\back.jpg";
	MenuItemImages[ITM_RECT] = "images\\FiguresItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\FiguresItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_TRI] = "images\\FiguresItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_LINE] = "images\\FiguresItems\\Menu_Line.jpg";
	
	

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<FIGURE_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

	

	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
void Output:: CreateResizeBar()const
{
	if( UI.ZoomFactor !=1)
		return;
	ClearToolBar();
	UI.SubMode = MODE_RESIZE;

	string MenuItemImages[RESIZE_COUNTER];
	MenuItemImages[ITM_RESIZE_BACK] = "images\\Resize\\back.jpg";
	MenuItemImages[ITM_HALF] = "images\\Resize\\1-2.jpg";
	MenuItemImages[ITM_QUARTER] = "images\\Resize\\1-4.jpg";
	MenuItemImages[ITM_DOUBLE] = "images\\Resize\\2.jpg";
	MenuItemImages[ITM_FOUR] = "images\\Resize\\4.jpg";

	
	for(int i=0; i<RESIZE_COUNTER; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}

void Output::CreateZoomBar()const
{
	ClearToolBar();
	UI.SubMode = MODE_ZOOM;

	string MenuItemImages[ZOOM_COUNT];
	MenuItemImages[ZOOM_BACK] = "images\\Zoom\\back.jpg";
	MenuItemImages[ITM_IN] = "images\\Zoom\\in.jpg";
	MenuItemImages[ITM_OUT] = "images\\Zoom\\out.jpg";
	

	
	for(int i=0; i<ZOOM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
void Output::CreateRotateBar()const
{
	ClearToolBar();
	UI.SubMode = MODE_ROTATE;

	string MenuItemImages[ROTATE_COUNT];
	MenuItemImages[ROTATE_BACK] = "images\\Zoom\\back.jpg";
	MenuItemImages[ITM_90] = "images\\Rotate\\90.jpg";
	MenuItemImages[ITM_180] = "images\\Rotate\\180.jpg";
	MenuItemImages[ITM_270] = "images\\Rotate\\270.jpg";

	

	
	for(int i=0; i<ROTATE_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}

void Output :: CreateWidthBar()const
{
	ClearToolBar();
	UI.SubMode = MODE_WIDTH;

	string MenuItemImages[WIDTH_COUNTER];
	MenuItemImages[ITM_WIDTH_BACK] = "images\\Width\\back.jpg";
	MenuItemImages[ITM_SIZE1] = "images\\Width\\size1.jpg";
	MenuItemImages[ITM_SIZE2] = "images\\Width\\size2.jpg";
	MenuItemImages[ITM_SIZE4] = "images\\Width\\size4.jpg";
	MenuItemImages[ITM_SIZE8] = "images\\Width\\size8.jpg";

	
	for(int i=0; i<WIDTH_COUNTER; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
	

}

void Output::Drawimage(string image,double x,double y,double width,double height)
{
	pWind->DrawImage(image, int(x),int(y),int(width), int(height));
}

void Output ::CreateOthersBar() const
{
	if( UI.ZoomFactor !=1)
		return;
		ClearToolBar();
	UI.SubMode = MODE_OTHERS;

	string MenuItemImages[OTHERS_COUNT];
	MenuItemImages[ITM_OTHERS_BACK] = "images\\Others\\back.jpg";
	MenuItemImages[ITM_SWIDTH] = "images\\Others\\width.jpg";
	MenuItemImages[ITM_ROTATION] = "images\\Others\\rotate.jpg";

	MenuItemImages[ITM_SENDB] = "images\\Others\\send_back.jpg";
	MenuItemImages[ITM_SENDF] = "images\\Others\\send_front.jpg";

	
	for(int i=0; i<OTHERS_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(color(114,180,196), 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}


void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
bool Output::getIsFilled() const
{
	return UI.isFilled;

}
color Output::getBkgrColor() const
{
	return UI.BkGrndColor;
	
}
	

int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}


SUB_MODES Output:: getMode() const
{
	return UI.SubMode;
}

float Output :: getZoomFactor()const
{
	return UI.ZoomFactor;
}
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

bool Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(int(P1.x),int(P1.y),int(P2.x),int(P2.y),style);
	return true;
	
}
bool Output :: DrawTRI(Point P1, Point P2,Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = TriGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, TriGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawTriangle(int(P1.x), int(P1.y), int(P2.x), int(P2.y),int(P3.x), int(P3.y), style);
	return true;
}
bool Output ::DrawLINE(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = LineGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	pWind->DrawLine(int(P1.x), int(P1.y), int(P2.x), int(P2.y),FRAME);
	return true;
}
bool Output ::DrawCIRC(Point P1, float radius, GfxInfo CircGfxInfo, bool selected) const
{
	color DrawingClr;

	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = CircGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, CircGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CircGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawCircle(int(P1.x), int(P1.y),int(radius),style);
	return true;
}
bool Output ::setZoom(float Factor)
{
	UI.ZoomFactor *= Factor;
	if(UI.ZoomFactor < 1)
	{
		UI.ZoomFactor = 1;
		return false;
	}
	return true;
}
void Output ::chngFillClr(color c)
{
	UI.FillColor = c;
}
void Output :: chngDrawClr(color c)
{
	UI.DrawColor = c;
}
void Output ::chngBckClr(color c)
{
	UI.BkGrndColor = c;
}
void Output ::chngPenWidth(int x)
{
	UI.PenWidth = x;
}

void Output :: setFilled(bool s)
{ UI.isFilled = s;}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

