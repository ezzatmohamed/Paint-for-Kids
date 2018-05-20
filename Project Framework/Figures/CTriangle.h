#ifndef CTriang_H
#define CTriang_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Corner3;
public:

	CTriangle(Point , Point, Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;

	virtual Point getcenter();

	virtual bool existFigure(double x,double y);
	static bool CheckTri(Point,Point,Point);
		virtual CFigure* cpy();

	double CalcArea(Point p1,Point p2,Point p3);
	virtual double 	getArea();
	virtual void scram(); 
	virtual void RandFigure();
	virtual bool Resize(float resize) ;	//Resize the figure

	virtual bool Move(Point P) ;		//Move the figure          

	virtual bool rotate(double angle) ;
		virtual void PrintInfo(ofstream &);
		static void LoadFig(ifstream &in,CFigure *& Fig);
		FigureType getType();
	 void selectedInfo(string & msg) ;
};

#endif