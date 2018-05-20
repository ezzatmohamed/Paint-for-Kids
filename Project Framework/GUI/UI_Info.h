#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};
enum SUB_MODES //Drawing and Play Mode has Some additional modes
{
	MODE_PLAY_MAIN,
	MODE_PICK,
	MODE_GAME,
	MODE_MAIN,
	MODE_FIGURE,
	MODE_SELECT,
	MODE_ZOOM,
	MODE_ROTATE,
	MODE_COLOR,
	MODE_Fill_COLOR,
	MODE_RESIZE,
	MODE_SUB_COLOR,
	MODE_WIDTH,
	MODE_OTHERS
	
};
enum ZOOM_MODE
{
	ITM_IN,
	ITM_OUT,
	ZOOM_BACK,

	ZOOM_COUNT
};
enum ROTATE_MODE
{
	ITM_90,
	ITM_180,
	ITM_270,
	ROTATE_BACK,

	ROTATE_COUNT
};
enum SELECT_MODE
{
	ITM_DONE,

	SELC_COUNT
};
enum Play_Game
{
	ITM_RESTART,
	ITM_MENU,

	GAME_COUNT
};
enum PICK_MODE
{
	ITM_PICK_BACK,
	ITM_TYPE,
	ITM_FILL,
	ITM_BOTH,
	ITM_AREA,

	PICK_ITM_COUNT
};
enum OTHERS // Other Actions Mode Items
{
	ITM_OTHERS_BACK,
	ITM_SWIDTH,
	ITM_ROTATION,
	ITM_SENDB,
	ITM_SENDF,
	
	OTHERS_COUNT
}; 
enum SubColor //Items for the mode that changes Colors
{
	ITM_SUBCOLOR_BACK,
	ITM_BACKGROUND,
 
	ITM_SFILLING,
	ITM_SDRAWING,

	SUBCOLORW_COUNT

};
enum Color	//Colors Items
{
	ITM_COLOR_B,
	ITM_RED,	
	ITM_PINK,
	ITM_ORANGE,
	ITM_YELLOW,
	ITM_GREEN,
	ITM_BLUE,
	ITM_CYAN,
	ITM_BLACK,
	

	COLORS_COUNTER
};
enum FillColor	//Colors Items
{
	ITM_COLOR_B1,
	ITM_UNFILL,
	ITM_RED1,	
	ITM_PINK1,
	ITM_ORANGE1,
	ITM_YELLOW1,
	ITM_GREEN1,
	ITM_BLUE1,
	ITM_CYAN1,
	ITM_BLACK1,
	

	COLORS_COUNTER1
};
enum WIDTH
{
	ITM_WIDTH_BACK,
	ITM_SIZE1,
	ITM_SIZE2,
	ITM_SIZE4,
	ITM_SIZE8,

	WIDTH_COUNTER
};
enum RESIZE //Resize Mode that changes figures SIZE.
{
	ITM_RESIZE_BACK,
	ITM_HALF,
	ITM_QUARTER,
	ITM_DOUBLE,
	ITM_FOUR,


	RESIZE_COUNTER

};


enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_ADD,
	ITM_SELC,
	ITM_COLOR,
	ITM_ZOOM,
	ITM_RESIZE,
	ITM_MOVE,
	
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_DELETE,
	ITM_OTHERS,
	ITM_SAVE,
	ITM_LOAD,
	//TODO: Add more items names here
	ITM_PLAY,
	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT,	//no. of menu items ==> This should be the last line in this enum
};

enum AddFigureItem //The items of Figures .
{
	ITM_COLOR_BACK,
	ITM_RECT,
	ITM_CIRC,
	ITM_TRI,
	ITM_LINE,
	
	FIGURE_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};


enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	ITM_PICK,
	ITM_FIND,
	ITM_DRAW,
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	SUB_MODES SubMode;

	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	float ZoomFactor;

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	bool isFilled;
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color



	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif