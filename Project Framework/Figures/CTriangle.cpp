#include "CTriangle.h"
#include"../ApplicationManager.h"

CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
	
FigureType CTriangle::getType()
{
	return TRIANGLE;
}
 Point CTriangle :: getcenter()
 {
	  Point Center = Corner1 + Corner2 + Corner3;
	 Center* (1/3.0);
	 return Center;
 }

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	Point p1 = Corner1;
	
	Point p2 = Corner2;

    Point p3 = Corner3;

	GfxInfo FigGfxinfo2 = FigGfxInfo;

	if(UI.ZoomFactor !=1)
	{
		((CFigure*)this)->ZoomPoint(p1);
		((CFigure*)this)->ZoomPoint(p2);
		((CFigure*)this)->ZoomPoint(p3);
		FigGfxinfo2.BorderWdth*=int(sqrt(UI.ZoomFactor));

	}
	pOut->DrawTRI(p1, p2 ,p3, FigGfxinfo2, Selected);
}
 void CTriangle:: scram()
{
	Corner1.x *=(1.0/2);
	Corner2.x *=(1.0/2);
	Corner3.x *=(1.0/2);
}
 void CTriangle:: RandFigure()
{
	 Point delta1 , delta2;
	 delta1 = Corner1 - Corner2;
	 delta2 = Corner1 - Corner3;

		 do 
		 {
			 Corner1.x = ( UI.width ) - rand()% (UI.width  - ( UI.width / 2 )+1);
			 Corner2.x = Corner1.x - delta1.x;
			 Corner3.x = Corner1.x - delta2.x;
		 }while( Corner1.x < ( UI.width / 2 ) || Corner1.x > UI.width || Corner2.x > UI.width  || Corner3.x > UI.width ||  Corner2.x < UI.width/2 || Corner3.x < UI.width / 2 );
		 do 
		 {
			 Corner1.y =  (UI.height - UI.StatusBarHeight ) - rand()%(UI.height - UI.StatusBarHeight)  - ( ( UI.ToolBarHeight / 2 )+1);
			 Corner2.y = Corner1.y - delta1.y;
			 Corner3.y = Corner1.y - delta2.y;
		 }while(Corner1.y < ( UI.ToolBarHeight ) || Corner2.y < ( UI.ToolBarHeight ) ||Corner3.y < ( UI.ToolBarHeight )  || Corner1.y > (UI.height - UI.StatusBarHeight) || Corner2.y > (UI.height - UI.StatusBarHeight) || Corner3.y > (UI.height - UI.StatusBarHeight) );
}

 CFigure* CTriangle:: cpy()
 {
	 CFigure * ptr = new CTriangle(*this);
	 return ptr;
 }
 bool CTriangle:: existFigure(double x,double y)
 {
	 Point p1 = Corner1,p2 = Corner2,p3 = Corner3;
	if(UI.ZoomFactor !=1)
	{
		((CFigure*)this)->ZoomPoint(p1);
		((CFigure*)this)->ZoomPoint(p2);
		((CFigure*)this)->ZoomPoint(p3);

	}
	 Point p;
	 p.x=x;
	 p.y=y;
	 double a1=CalcArea(p,p1,p2);
	 double a2=CalcArea(p,p1,p3);
	 double a3=CalcArea(p,p3,p2);
	 double a4=a1+a2+a3;
	 double a=CalcArea(p1,p2,p3);

	 if(floor(a4) <= ceil(a))
		 return true ;

	 return false;
 }

	
  bool CTriangle:: CheckTri(Point P1,Point P2,Point P3)
  {
	  if(P1.y < UI.ToolBarHeight || P1.y > UI.height - UI.StatusBarHeight || P2.y < UI.ToolBarHeight || P2.y > UI.height - UI.StatusBarHeight || P3.y < UI.ToolBarHeight || P3.y > UI.height - UI.StatusBarHeight ||P1.x > UI.width || P2.x > UI.width || P2.x < 0 || P1.x < 0 || P3.x < 0  || P3.x > UI.width)
		  return false;
	  return true;
  }

double CTriangle::	CalcArea(Point p1,Point p2,Point p3)
{
	double dis1= sqrt(pow(p1.y-p2.y,2)+pow(p1.x-p2.x,2));
	double dis2= sqrt(pow(p1.y-p3.y,2)+pow(p1.x-p3.x,2));
	double dis3= sqrt(pow(p3.y-p2.y,2)+pow(p3.x-p2.x,2));
	double area = abs(p1.x*((p2.y-p3.y)+p2.x*(p3.y-p1.y)+p3.x*(p1.y-p2.y))/2.0);
	double s = (dis1+dis2+dis3)/2.0;

	return sqrt(s*(s-dis1)*(s-dis2)*(s-dis3));
}

double CTriangle::	getArea()
{
   return CalcArea(Corner1,Corner2,Corner3);
}
 bool CTriangle:: Resize(float resize)
 {
	 double x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	 double y = (Corner1.y + Corner2.y + Corner3.y) / 3;


	 Corner1.x = x + (Corner1.x - x )*resize;
	 Corner2.x = x + (Corner2.x - x )*resize;
	 Corner3.x = x + (Corner3.x - x )*resize;
	 Corner3.y = y + (Corner3.y - y )*resize;
	 Corner2.y = y + (Corner2.y - y )*resize;
	 Corner1.y = y + (Corner1.y - y )*resize;

	 if(!CheckTri(Corner1,Corner2,Corner3))
		 return false;
	 return true;

 }  //Resize the figure

 bool CTriangle::Move(Point P) 
 {
	 Point Center = Corner1 + Corner2 + Corner3;
	 Center* (1/3.0);

	 Point delta1 = Corner1-Center;
	 Point delta2= Corner2-Center;
	 Point delta3= Corner3-Center;

	 Corner1= delta1 + P;
	 Corner2= delta2 + P;
	 Corner3= delta3 + P;

	 
	 if(!CheckTri(Corner1,Corner2,Corner3))
		 return false;
	 return true;
 }		//Move the figure          

 bool  CTriangle::rotate(double angle)
 {
	 Point center = getcenter();
	 Corner1 = RotatePoint(Corner1,angle,center);
	 Corner2 = RotatePoint(Corner2,angle,center);
	 Corner3 = RotatePoint(Corner3,angle,center);
	 if(!CheckTri(Corner1,Corner2,Corner3))
		 return false;
	 return true;
 }

   void CTriangle:: PrintInfo(ofstream &output)
  {
	  
	  output << endl << "Triangle     ";
	  output << ID <<"     " << Corner1.x <<"     " << Corner1.y <<"     " << Corner2.x <<"     " <<  Corner2.y <<"     " << Corner3.x <<"     " << Corner3.y<<"      " << FigGfxInfo.BorderWdth <<"     ";
	
	  output << ApplicationManager::ColorToString(FigGfxInfo.DrawClr) << "      ";

	  if(FigGfxInfo.isFilled)
	  {
		output << ApplicationManager::ColorToString(FigGfxInfo.FillClr) <<"     ";
	  }
	  else
		  output << "NOT_FILLED";

  }


   void CTriangle ::  LoadFig(ifstream &in,CFigure *& Fig)
  {
	  GfxInfo figGfx;

	  Point c1,c2,c3;
	 int id;
	  in >> id >> c1.x >> c1.y >> c2.x >> c2.y >> c3.x >> c3.y >> figGfx.BorderWdth ;

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

	  Fig = new CTriangle(c1,c2,c3,figGfx);
	  	  Fig->setID(id);

 }

  void CTriangle :: selectedInfo(string & msg) 
 {
	 
	 msg = "ID = " + to_string(ID);
	 msg+= " , Corner1 : ( " + to_string(int(Corner1.x)) + ", "+to_string(int(Corner1.y)) +" ) , ";
	 msg+= " Corner2 : ( " + to_string(int(Corner2.x)) + ", "+to_string(int(Corner2.y)) +" ) , ";
	 msg+= " Corner3 : ( " + to_string(int(Corner3.x)) + ", "+to_string(int(Corner3.y)) +" ) , ";

	 double area =  getArea();

	 msg+= " Area  = " + to_string(int(area)); 
 }