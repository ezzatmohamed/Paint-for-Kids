#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"


class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateStatusBar() const;	        //create the status bar
	/////////////////////////////////////////////////////////////////////////////////////

	                  /*   Creating  the ToolBars  */

	void CreateDrawToolBar() const;	        //creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;     	//creates Play mode toolbar & menu
	void CreatePickBar()const;             //create a ToolBar to change the figures width.
	void CreateGameBar()const;
	void CreateFigureToolBar() const;       //create the Figures bar
	void CreateSelectToolBar() const;       //create the Figures bar
	void CreateColorsBar()const;            //create the Colors Bar
	void CreateFillColorsBar()const;
	void CreateResizeBar()const;            //create The Resize Bar
	void CreateZoomBar()const;
	void CreateRotateBar()const;
	void CreateSubColorBar()const;          //create the changing color Mode Bar
	void CreateOthersBar()const;            //create a ToolBar For Other Actions Mode.
	void CreateWidthBar()const;             //create a ToolBar to change the figures width.
	            /////////////////////////////////////////////

	Input* CreateInput()  const;        //creates a pointer to the Input object	
	void ClearStatusBar() const;	    //Clears the status bar
	void ClearDrawArea()  const;	    //Clears the drawing area
	void ClearToolBar()   const;        //Clears the toolbar.


	                 // -- Figures Drawing functions -- //

    bool DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
    bool DrawTRI(Point P1, Point P2,Point P3, GfxInfo TriGfxInfo, bool selected=false) const; //Draw a Triangle
    bool DrawLINE(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected=false) const;        //Draw a Line
    bool DrawCIRC(Point P1, float, GfxInfo CircGfxInfo, bool selected=false) const;   //Draw a Circle

	            /////////////////////////////////////////////

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	bool getIsFilled()const;
	color getBkgrColor()const;
	SUB_MODES getMode()const;
	float getZoomFactor()const;
	void Drawimage(string image,double x,double y,double width,double height);
	//bool  getFilledState();
	int getCrntPenWidth() const;		//get current pen width
	bool setZoom(float Factor);
	void chngFillClr(color);
	void chngDrawClr(color);
	void chngBckClr(color);
	void chngPenWidth(int);
	void setFilled(bool);
	~Output();
};

#endif

