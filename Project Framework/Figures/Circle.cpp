#include "Circle.h"
#include "..\ApplicationManager.h"
CCircle::CCircle(Point P, float radius,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center = P;
	r= radius;
}
	
FigureType CCircle::getType()
{
	return CIRC;
}
void CCircle::Draw(Output* pOut) const
{

	Point p1 = center;
	
	float rad = r;

	GfxInfo FigGfxinfo2 = FigGfxInfo;
	if(UI.ZoomFactor !=1)
	{

		((CFigure*)this)->ZoomPoint(p1);
		rad *=sqrt(UI.ZoomFactor);
		FigGfxinfo2.BorderWdth *=int(sqrt(UI.ZoomFactor));
	}
	
	pOut->DrawCIRC(p1, rad, FigGfxinfo2, Selected);
}

 void CCircle:: scram()
{
	r = r/2;
	center.x *= (1.0/2);
}

 void CCircle:: RandFigure()
 {
		 do 
		 {
			 center.x = ( UI.width ) - rand()% (UI.width  - ( UI.width / 2 )+1);
		 }while(center.x < ( UI.width / 2 ) || center.x > UI.width || (center.x - ( UI.width / 2 ) < r ) || ( (UI.width - center.x) < r ) );
		 do 
		 {
			 center.y =  (UI.height - UI.StatusBarHeight ) - rand()%(UI.height - UI.StatusBarHeight)  - ( ( UI.ToolBarHeight / 2 )+1);
		 }while(center.y < ( UI.ToolBarHeight) || center.y > (UI.height - UI.StatusBarHeight) || ( ( (center.y - UI.ToolBarHeight) < r ) || ( (UI.height - UI.StatusBarHeight) - center.y )  < r ));
	
 }
 CFigure* CCircle:: cpy()
 {
	 CFigure * ptr = new CCircle(*this);
	 return ptr;
 }



bool CCircle:: CheckCircle(Point P1,float radius) 
{

	if(P1.y < UI.ToolBarHeight || P1.y > UI.height - UI.StatusBarHeight )
		return false;	
	if(P1.y - UI.ToolBarHeight <  radius || ( UI.height - UI.StatusBarHeight ) - P1.y < radius)
		return false;
	if(P1.x + radius > UI.width || P1.x - radius <0)
		return false;


	return true;
}


Point CCircle :: getcenter()
{
	return center;
}

bool CCircle:: existFigure(double x,double y)
{
	Point c = center;
	float rad = r;
	
	if(UI.ZoomFactor !=1)
	{
		((CFigure*)this)->ZoomPoint(c);
		rad *= sqrt(UI.ZoomFactor);
	}
	double distance = sqrt(pow(c.y-y,2)+pow(c.x-x,2));

	if( distance <= rad)
		return true;
	return false;
}


 bool CCircle:: Resize(float resize) 
 {
	 r = sqrt(r *r *resize);

	 if(!CheckCircle(center,r))
		 return false;
	 return true;
	 
 }

 bool CCircle::Move(Point P)
 {
	
	  center = P;
	 if(!CheckCircle(center,r))
		 return false;
	 return true;

 }		//Move the figure          

bool  CCircle::rotate(double angle)
{
	return true;
	//There's no rotation in Circles !
}

double CCircle:: getArea()
{
	
	const double PI = 3.14259;

	return PI * r * r;
}



 void CCircle :: PrintInfo(ofstream & output )
 {
	 output << endl << "Circle     "; 
	  output << ID <<"     " << center.x <<"     " << center.y <<"     " <<r <<"       "<< FigGfxInfo.BorderWdth <<"     " ;
	  
	  output << ApplicationManager::ColorToString(FigGfxInfo.DrawClr) << "      ";

	  if(FigGfxInfo.isFilled)
	  {
		output << ApplicationManager::ColorToString(FigGfxInfo.FillClr) <<"     ";
	  }
	  else
		  output << "NOT_FILLED";


	 
 }


  void CCircle ::  LoadFig(ifstream &in,CFigure *& Fig)
  {
	  GfxInfo figGfx;

	  Point c;
	  float r;
	  int id;
	  in >> id >> c.x >> c.y >> r >> figGfx.BorderWdth ;

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
		  figGfx.isFilled = false;


	  Fig = new CCircle(c,r,figGfx);
	  Fig->setID(id);

  }

  void CCircle :: selectedInfo(string & msg) 
 {
	
	 msg = "ID = " + to_string(ID);
	 msg+= " , Center Point : ( " + to_string(int(center.x)) + ", "+to_string(int(center.y)) +" ) , ";
	 double area =  getArea();
	 msg += " radius = " + to_string(int(r)) + " , ";
	 msg+= " Area  = " + to_string(int(area)); 
 }