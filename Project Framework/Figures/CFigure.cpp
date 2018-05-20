#include "CFigure.h"

int CFigure :: IdCounter =0;       //Initialize the counter for Figures ID

CFigure::CFigure(GfxInfo FigureGfxInfo) 
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;           //Default the figure is not selected .
	ID = IdCounter;             
	IdCounter++;

}
void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

bool CFigure::IsFilled() const
{	return FigGfxInfo.isFilled; }

void CFigure::SetFilled(bool f) 
{	 FigGfxInfo.isFilled = f; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngWidth(int w)
{	FigGfxInfo.BorderWdth = w; }

void CFigure::ChngFillClr(color Fclr)
{	

	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

GfxInfo CFigure::getFigGfxInfo()
{
	return FigGfxInfo;
}


color CFigure::getFillColor()
{
	return FigGfxInfo.FillClr;
}


Point CFigure::RotatePoint(Point P1,double angle,Point P2)
{ 
  const double PI = 3.14259;
  angle = angle * PI / 180;
  double s = sin(angle);
  double c = cos(angle);
  double x,y;
  x = P1.x;
  y= P1.y;
  // translate point back to origin:
  x -= P2.x;
  y -= P2.y;

  // rotate point
  double xnew = x * c - y * s;
  double ynew = x * s + y * c;

  // translate point back:
  x = xnew + P2.x;
  y = ynew + P2.y;

  P1.x= x;
  P1.y = y;
  return P1;
}

void CFigure :: setID(int id)
{
	ID = id;
}



void CFigure ::ZoomPoint(Point &p1)
{
	p1.x = (p1.x - (UI.width /2 ))* sqrt( UI.ZoomFactor ) + ( UI.width/2);
	p1.y = (p1.y - (UI.height /2 )) * sqrt(UI.ZoomFactor) + ( UI.height/2);
}


int CFigure :: getID()
{
	return ID;
}

void CFigure :: setIdCount(int x)
{
	IdCounter = x;
}
