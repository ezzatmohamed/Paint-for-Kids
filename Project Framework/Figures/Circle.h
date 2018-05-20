#pragma once
#include "CFigure.h"
class CCircle : 	public CFigure
{private:
	Point center;	
	float r;
	
public:

	CCircle(Point,float, GfxInfo FigureGfxInfo );

	virtual void Draw(Output* pOut) const;
	
	static bool CheckCircle(Point ,float)  ;

		virtual CFigure* cpy();

	virtual Point getcenter();

	virtual bool existFigure(double x,double y);

	virtual bool Resize(float resize) ;	//Resize the figure

	virtual bool Move(Point P) ;		//Move the figure          

	virtual bool rotate(double angle) ;

	virtual double getArea();
	virtual void scram(); 
	virtual void RandFigure();

	virtual void PrintInfo(ofstream &);
	static void LoadFig(ifstream&,CFigure *&);

	FigureType getType();
	 void selectedInfo(string & msg) ;
};

