#include "CRectangle.h"
#include"../ApplicationManager.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
} 
	
FigureType CRectangle::getType()
{
	return RECTANGLE;
}
Point CRectangle :: getcenter()
{
	Point c =  ( Corner1 + Corner2 );
	c *(1/2.0);
	return  c;
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	Point p1 = Corner1;
	
	Point p2 = Corner2;

	GfxInfo FigGfxinfo2 = FigGfxInfo;

	if(UI.ZoomFactor !=1)
	{
		((CFigure*)this)->ZoomPoint(p1);
		((CFigure*)this)->ZoomPoint(p2);
		FigGfxinfo2.BorderWdth = int(FigGfxinfo2.BorderWdth * sqrt(UI.ZoomFactor));
	}
	pOut->DrawRect( p1, p2, FigGfxinfo2, Selected);
}

 CFigure* CRectangle:: cpy()
 {
	 CFigure * ptr = new CRectangle(*this);
	 return ptr;
 }

 void CRectangle:: scram()
{
	Corner1.x *= (1.0/2);
	Corner2.x *=(1.0/2);
}

 void CRectangle:: RandFigure()
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

bool CRectangle::CheckRect(Point P1,Point P2)
{
	if(P1.y < UI.ToolBarHeight || P1.y > UI.height - UI.StatusBarHeight || P2.y < UI.ToolBarHeight || P2.y > UI.height - UI.StatusBarHeight || P1.x > UI.width || P2.x > UI.width || P2.x < 0 || P1.x < 0 )
		return false;
	return true;
}


double CRectangle ::	CalcArea(Point p1,Point p2,Point p3)
{
	double dis1= sqrt(pow(p1.y-p2.y,2)+pow(p1.x-p2.x,2));
	double dis2= sqrt(pow(p1.y-p3.y,2)+pow(p1.x-p3.x,2));
	double dis3= sqrt(pow(p3.y-p2.y,2)+pow(p3.x-p2.x,2));
	double area = abs(p1.x*((p2.y-p3.y)+p2.x*(p3.y-p1.y)+p3.x*(p1.y-p2.y))/2.0);
	double s = (dis1+dis2+dis3)/2.0;

	return sqrt(s*(s-dis1)*(s-dis2)*(s-dis3));
}

 bool CRectangle::existFigure(double x,double y)
 {
	Point p1 = Corner1,p2 = Corner2;
	if(UI.ZoomFactor !=1)
	{
		((CFigure*)this)->ZoomPoint(p1);
		((CFigure*)this)->ZoomPoint(p2);
	}
	Point Max,Min;	

	if( p1.x >p2.x)
	{
		Max.x = p1.x;
		Min.x = p2.x;
	}
	else 
	{
		Max.x = p2.x;
		Min.x = p1.x;
	}
	if(p1.y > p2.y)
	{
		Max.y = p1.y;
		Min.y = p2.y;
	}
	else
	{
		Max.y = p2.y;
		Min.y = p1.y;
	}


	if( x > Min.x && x < Max.x && y > Min.y && y < Max.y)
		return true;


	return false;
 }

 bool CRectangle:: rotate(double angle)
 {
	 Point center = getcenter();
	 Corner1 = RotatePoint(Corner1,angle,center);
	 Corner2 = RotatePoint(Corner2,angle,center);
	 if(!CheckRect(Corner1,Corner2))
		return false;
	 return true;
 }

 double CRectangle::getArea()
 {
	 double width = abs(Corner1.x - Corner2.x);
	 double length = abs(Corner1.y - Corner2.y);

	 return double(width*length);
 }
bool CRectangle::Resize( float resize)
{
	double L1 = Corner2.y - Corner1.y;
	double W1 = Corner1.x - Corner2.x;
	double L2 = L1 * sqrt(resize);
	double W2 = W1 * sqrt(resize);
	
	
	Corner1.x -= (W1-W2)/2;
	Corner1.y += (L1-L2)/2;
	Corner2.x += (W1-W2)/2;
	Corner2.y -= (L1-L2)/2;
	
	if(!CheckRect(Corner1,Corner2))
		return false;

	return true;
}
 bool CRectangle :: Move(Point P)
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

	 if(!CheckRect(Corner1,Corner2))
		return false;

	return true;
 }


 void CRectangle :: PrintInfo(ofstream &output )
 {
	 output << endl << "RECTANGLE     ";
	  output << ID <<"     " << Corner1.x <<"     " << Corner1.y <<"     " << Corner2.x <<"     " <<  Corner2.y <<"     " << FigGfxInfo.BorderWdth <<"     ";
	  
	  output << ApplicationManager::ColorToString(FigGfxInfo.DrawClr) << "      ";

	  if(FigGfxInfo.isFilled)
	  {
		output << ApplicationManager::ColorToString(FigGfxInfo.FillClr) <<"     ";
	  }
	  else
		  output << "NOT_FILLED";

 
 }

   void CRectangle ::  LoadFig(ifstream &in,CFigure *& Fig)
 {
	  GfxInfo figGfx;

	  Point c1,c2;
	  int id;
	  in >> id >> c1.x >> c1.y >> c2.x >> c2.y >> figGfx.BorderWdth ;

	  
	  
     string clrString;
	in >> clrString ;
	figGfx.DrawClr = ApplicationManager::stringToColor(clrString);	 
	

	in >> clrString ;
	if(clrString != "NOT_FILLED")
	  {
		  figGfx.FillClr = ApplicationManager::stringToColor(clrString);
		  figGfx.isFilled = true;
	  }
	  else 
	  {
		  figGfx.FillClr = GREEN;
		  figGfx.isFilled = false;
	}

	  Fig = new CRectangle(c1,c2,figGfx);
    Fig->setID(id);
  }

  void CRectangle :: selectedInfo(string & msg) 
 {
	 
	 msg = "ID = " + to_string(ID);
	 msg+= " , Start Point : ( " + to_string(int(Corner1.x)) + ", "+to_string(int(Corner1.y)) +" ) , ";
	 msg+= " End Point : ( " + to_string(int(Corner2.x)) + ", "+to_string(int(Corner2.y)) +" ) , ";
	 double area =  getArea();
	 msg += " width = " + to_string(abs(int(Corner1.x-Corner2.x))) + " , ";
	 msg += " length = " + to_string(abs(int(Corner1.y-Corner2.y))) + " , ";

	 msg+= " Area  = " + to_string(int(area)); 
 }