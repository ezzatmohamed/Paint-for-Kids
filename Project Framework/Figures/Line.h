#pragma once
#include "CFigure.h"
class CLine :
	public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	
public:

	CLine(Point,Point, GfxInfo FigureGfxInfo );

	virtual void Draw(Output* pOut) const;
	
	virtual Point getcenter();
	
	virtual bool existFigure(double x,double y);

	static bool CheckLine(Point,Point);

	virtual bool Resize(float resize) ;	//Resize the figure

	virtual bool Move(Point P) ;		//Move the figure          

	virtual bool rotate(double angle) ;

	virtual double getArea();

	virtual void PrintInfo(ofstream & output);

	static void LoadFig(ifstream &in,CFigure *& Fig);
	virtual void scram(); 
	virtual void RandFigure();
	virtual CFigure* cpy();
	FigureType getType();
	 void selectedInfo(string & msg) ;

};

