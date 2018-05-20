#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );

	virtual void Draw(Output* pOut) const;
	static bool CheckRect(Point,Point) ;
	virtual CFigure* cpy();

	double CRectangle ::CalcArea(Point p1,Point p2,Point p3);

	virtual Point getcenter();
	virtual bool Resize(float resize);
	virtual bool rotate(double angle);
	virtual bool Move(Point P);

	virtual double getArea();
	virtual void scram(); 
	virtual void RandFigure();
	virtual bool existFigure(double x,double y);
		virtual void PrintInfo(ofstream &);
		static void LoadFig(ifstream&,CFigure *&);
		FigureType getType();
		 void selectedInfo(string & msg) ;
};

#endif