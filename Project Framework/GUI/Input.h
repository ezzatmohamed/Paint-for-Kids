#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
public:
	Input(window *pW);		//Consturctor
	void GetPointClicked(double &x, double &y) const;//Get coordinate where user clicks
	string GetSrting(Output* pO) const ;	 //Returns a string entered by the user
	string CurrentSelect(Output *pO)const;    // a Function to determine the choosen change ( width / color ) is for the selected figures / or currnet change .

	ActionType GetUserAction() const; //Read the user click and map to an action

	~Input();
};

#endif