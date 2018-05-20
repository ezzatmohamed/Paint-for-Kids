#include "..\defs.h"
#include "..\GUI\Output.h"
#include "Circle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "Line.h"
#include<fstream>

#ifndef CFIGURE_H
#define CFIGURE_H


//Base class for all figures
class CFigure
{
protected:
	static int IdCounter ;     //
	int ID;		               //Each figure has an ID
	bool Selected;	           //true if the figure is selected.
	GfxInfo FigGfxInfo;	       //Figure graphis info
public:
	CFigure(GfxInfo FigureGfxInfo);
    static void  setIdCount(int);   
	void SetSelected(bool s);	       //select/unselect the figure
	bool IsSelected() const;	       //check whether fig is selected
	bool IsFilled() const;             //Check whether fig is filled.
	void SetFilled(bool f);            //Setting Filled by ( f ).
	void setID(int id);                //set The Figure ID.

	Point RotatePoint(Point P1,double angel,Point P2);

	virtual Point getcenter() = 0 ;

	virtual bool existFigure(double x,double y)=0;

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	virtual CFigure* cpy() = 0;

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color

	void ChngFillClr(color Fclr);	//changes the figure's filling color

	void ChngWidth(int w);

	virtual bool Resize(float resize) = 0;	//Resize the figure

	virtual bool Move(Point P) = 0;		//Move the figure          

	virtual bool rotate(double angle) = 0;

	virtual double getArea() = 0;

	virtual void scram() = 0;

	virtual void RandFigure() = 0;
	
	GfxInfo getFigGfxInfo();

	int getID();

	virtual void PrintInfo(std::ofstream &) = 0;

	virtual FigureType getType() = 0;

	color getFillColor();

	void ZoomPoint(Point&);

	virtual void selectedInfo(string & msg) = 0;
};

#endif