#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	GO_BACK,  // going back to drawing toolbar	          

	/*Menu DrawingMode Tool Bar Actions */
	TO_ADD,         //Going to Figures ToolBar
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	TO_CHNG_COLOR,  //Going to Changing color items Toolbar

	ZOOM,           //ZOOMING IN and OUT.
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	RESIZE,			//Resize a figure(s)
	SELEC,          //Selecting Figures
	COPY,           //Copying Figures
	CUT,            //Cutting figures
	PASTE,          //Pasting Figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application
	/*Play Mode Actions*/
	TO_PICK,        // Pick & hide Figure game
	TO_FIND,        // Find Figures Game
	
	RESTART,        // Restart The game 
	/////////////////////
	/* PICK&HIDE Mode Actions*/
	BY_FILL,        // Pick & hide by Filling Color
	BY_TYPE,        // Pick & hide by Figure Type
	BY_BOTH,        // Pick & hide by Filling color and type
	BY_AREA,        // Pick & hide by Figure Area.
	/////////////////////

	ZOOM_IN,
	ZOOM_OUT,
	////////////////////
	ROTATE_90,
	ROTATE_180,
	ROTATE_270,
	/*Others Actions*/
	
	TO_OTHERS,     //Going  to the others Toolbar 

	CHNG_SWIDTH,
	ROTATE,         //rotating figures
	SENDB,          //send figures back
	SENDF,          //send figures front
	/////////////////////
	/*Resize Actions*/

	HALF,           //resize figure to its half size
	QUARTER,        //resize figure to its 1/4 size
	DOUBLe,         //resize figure to its 2 size
	FOUR,           //resize figure to its 4 size

	/////////////////////
	/*Select Actions*/

	SELECT_ALL,           //resize figure to its half size
	DONE,        //resize figure to its 1/4 size

	/////////////////////
	/*Width Actions*/
	 
	size1,           //change the width to 1.
	size2,           //change the width to 2.
	size4,           //change the width to 4.
	size8,           //change the width to 8.
	/////////////////////
	/////////////////////
	/*SubColors Actions*/
	BACKGROUND,      //change the background color.
	SFILLING,
	SDRAWING,
	/////////////////////
	/*Colors Actions*/
	UNFILL,
	CHNG_RED,        //red color.
	CHNG_PINK,        //pink color.
	CHNG_ORANGE,        //orange color.
	CHNG_YELLOW,        //yellow color.
	CHNG_GREEN,        //green color.
	CHNG_BLUE,        //blue color.
	CHNG_CYAN,        //cyan color.
	CHNG_BLACK,        //black color.
	//////////////////
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY			//Switch interface to Play mode

	///TODO: Add more action types (if needed)
};


enum TypeArea // Pick by area ( Max , Min , still undefined )
{
	undef,
	MAX,
	MIN
};
enum FigureType
{
	NOTYPE,
	RECTANGLE,
	TRIANGLE,
	LINE,
	CIRC
};


struct Point	//To be used for figures points
{ 

	double x,y;

	Point operator+(Point p)
	{
		Point P;
		P.x = x +p.x;
		P.y = y +p.y;


		return P;
	}
	Point operator-(Point p)
	{
		Point P;
		P.x = x - p.x;
		P.y = y - p.y;
		return P;
	}
	void operator*(double r)
	{

		x*=r;
		y*=r;
	}
	Point operator+(double z)
	{
		Point P;
		P.x = x + z;
		P.y = y + z;
		return P;
	}
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};


#endif
