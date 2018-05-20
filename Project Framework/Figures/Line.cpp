#include "Line.h"
#include"../ApplicationManager.h"


CLine::CLine(Point P1, Point P2,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

FigureType CLine::getType()
{
	return LINE;
}
	
Point CLine :: getcenter()
{
	Point c =  ( Corner1 + Corner2 );
	c *(1/2.0);
	return  c;
}

void CLine::Draw(Output* pOut) const
{
	Point p1 = Corner1;

	Point p2 = Corner2;

	GfxInfo FigGfxinfo2 = FigGfxInfo;

	if(UI.ZoomFactor !=1)
	{
		((CFigure*)this)->ZoomPoint(p1);
		((CFigure*)this)->ZoomPoint(p2);
		FigGfxinfo2.BorderWdth*=int(sqrt(UI.ZoomFactor));
	}
	pOut->DrawLINE(p1, p2, FigGfxinfo2, Selected);
}

double CLine::getArea()
{
	return sqrt(pow(Corner1.y-Corner2.y,2)+pow(Corner1.x-Corner2.x,2));
}

bool CLine:: existFigure(double x,double y)
{
	Point p1 = Corner1,p2 = Corner2;
	if(UI.ZoomFactor !=1)
	{
		((CFigure*)this)->ZoomPoint(p1);
		((CFigure*)this)->ZoomPoint(p2);
	}
	//if( p1.x - p2.x == 0)
	//{
	//	if( x <= FigGfxInfo.BorderWdth && x >= -FigGfxInfo.BorderWdth && p1 )
	//	return;
	//}
	double slope =  double((p1.y-p2.y))  / (p1.x-p2.x);
	double z = y - p1.y + slope * (p1.x - x);
	if( z <= FigGfxInfo.BorderWdth && z >= -FigGfxInfo.BorderWdth )
	{
		if( getArea() >= sqrt(pow(Corner1.y-y,2)+pow(Corner1.x-x,2)) && getArea() >= sqrt(pow(y-Corner2.y,2)+pow(x-Corner2.x,2)))
			return true;
	}
	return false;
	
}

 void CLine:: scram()
{
	Corner1.x *= (1.0/2);
	Corner2.x *= (1.0/2);
}
	
  void CLine:: RandFigure()
 {
	 Point delta;
	 delta = Corner1 - Corner2;

		 do 
		 {
			 Corner1.x = ( UI.width ) - rand()% (UI.width  - ( UI.width / 2 )+1);
			 Corner2.x = Corner1.x - delta.x;
		 }while( Corner1.x < ( UI.width / 2 ) || Corner1.x > UI.width || Corner2.x > UI.width ||  Corner2.x < ( UI.width / 2 ) );
		 do 
		 {
			 Corner1.y =  (UI.height - UI.StatusBarHeight ) - rand()%(UI.height - UI.StatusBarHeight)  - ( ( UI.ToolBarHeight / 2 )+1);
			 Corner2.y = Corner1.y - delta.y;
		 }while(Corner1.y < ( UI.ToolBarHeight ) || Corner1.y > (UI.height - UI.StatusBarHeight) || Corner2.y > (UI.height - UI.StatusBarHeight) || Corner2.y < ( UI.ToolBarHeight ) );

}

CFigure* CLine:: cpy()
{
     CFigure * ptr = new CLine(*this);
	 return ptr;
}

bool CLine:: CheckLine(Point P1,Point P2)
{
	if(P1.y < UI.ToolBarHeight || P1.y > UI.height - UI.StatusBarHeight || P2.y < UI.ToolBarHeight || P2.y > UI.height - UI.StatusBarHeight || P1.x > UI.width || P2.x > UI.width || P2.x < 0 || P1.x < 0)
		return false;
	return true;
}

 bool CLine:: Resize(float factor)
 {
	 
	Point center = Corner1 + Corner2;
	center * (1/2.0);
	Corner1.x = center.x + (Corner1.x - center.x)*factor;
	Corner1.y = center.y + (Corner1.y - center.y)*factor;
	Corner2.x = center.x + (Corner2.x - center.x)*factor;
	Corner2.y = center.y + (Corner2.y - center.y)*factor;


	if(!CheckLine(Corner1,Corner2))
		 return false;
	 return true;

 }	//Resize the figure
 

 bool CLine :: Move(Point P) 
 {
	 Point Middle,deltaP1,deltaP2;

	Middle.x = (Corner1.x + Corner2.x) / 2.0;
	Middle.y = (Corner1.y + Corner2.y) / 2.0;

	/////////////////////////////

	deltaP1 = Middle - Corner1 ;
	deltaP2 = Middle - Corner2 ; 

	/////////////////////////////
	Corner1 = P + deltaP1;
	Corner2 = P + deltaP2;


	 if(!CheckLine(Corner1,Corner2))
		 return false;
	 return true;
 }		//Move the figure          

 bool  CLine::rotate(double angle)
 {
	 Point center = getcenter();

	Corner1 = RotatePoint(Corner1,angle,center);
	Corner2 = RotatePoint(Corner2,angle,center);
	if(!CheckLine(Corner1,Corner2))
		 return false;
	return true;
 }


void CLine ::  LoadFig(ifstream &in,CFigure *& Fig)
  {
	  GfxInfo figGfx;

	  Point c1,c2;
	 int id;
	  in >> id >> c1.x >> c1.y >> c2.x >> c2.y >> figGfx.BorderWdth;

	   string clrString;
	in >> clrString ;
	figGfx.DrawClr = ApplicationManager::stringToColor(clrString);	 
	
	  figGfx.isFilled = false;

	  Fig = new CLine(c1,c2,figGfx);
	  	  Fig->setID(id);

  }

 void CLine :: PrintInfo(ofstream &output )
 {
	 output << endl << "LINE     ";
	 output << ID <<"     " << Corner1.x <<"     " << Corner1.y <<"     " << Corner2.x <<"     " <<  Corner2.y <<"     " << FigGfxInfo.BorderWdth <<"     " ;
	  output << ApplicationManager::ColorToString(FigGfxInfo.DrawClr) << "      ";
 
 }

 void CLine :: selectedInfo(string & msg) 
 {
	 
	 msg = "ID = " + to_string(ID);
	 msg+= " , Start Point : ( " + to_string(int(Corner1.x)) + ", "+to_string(int(Corner1.y)) +" ) , ";
	 msg+= " End Point : ( " + to_string(int(Corner2.x)) + ", "+to_string(int(Corner2.y)) +" ) , ";
	 double length =  getArea();
	 msg+= " Length = " + to_string(int(length)); 

	 
 }