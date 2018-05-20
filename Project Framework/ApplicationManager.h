#include<fstream>
#include "All_Includes.h"

#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200};	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	
	int ClipboardCount;
	CFigure* ClipboardList[MaxFigCount]; //List of all copied/cut Figures.

	int SelectFig;
	
	//Pointers to Input and Output classes
	
	Input *pIn;
	Output *pOut;

	bool Exit;

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void ExecuteAction(ActionType);   //Execute an action.
	void ErrorMsg() const;            //display an error message if a figure is drawn out of the drawing area.
	void ErrorMsgSelect()const;       //display an error message if no figure is selected.
	void PrintSelectMsg()const;       //display a message when user selects figures.

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type

	ActionType GetUserAction() const;

	// -- Figures Management Functions

	void AddFigure(CFigure* pFig);           //Adds a new figure to the FigList
	void AddToClipboard(CFigure* pFig);      //Add the copied( or cut ) figures to the clipboard.
    Point AvgCenterSelc(CFigure*L[] , int);  //Calculates the average centers point of the selected Figures in a list .



	// -- Actions Functions ............................
	void Move(Point New );                   //Move The selected figure to the point (New).
	bool Select(Point P);                    //Select The figure that exists at a point P.
	void resize(float ratio);                //Resize the selected figures .
	void Rotate(double angle);               //Rotate the selected figures by angle ( angle ).
	void ChngBckClr(color Bclr);             //Change the background color to Bclr.
	void ChngCDrawClr(color Dclr);           //Change the current drawing color to Dclr.
	void ChngCFillClr(color Fclr,bool);      //Change the current Filling color to Fclr.
	void ChngSFillClr(color Fclr,bool );     //Change the selected figures filling color to Fclr.
	void ChngSDrawClr(color Dclr);           //Change the selected figures drawing color to Dclr.
	void ChngSWidth(int New);                //Change the selected figures BorderWidth to New .
	void  ChngCWidth(int New);                   //Change the current Width  to New .
	void Copy();                             //Copy the selected figures to the clipboard.
	void Paste(Point);                       //Pasting the the copied/cut figures .
	void SendFigsBack();                     //Sending the selected figures back the other figures.
	void SendFigsFront();                    //Sending the selected figures front the other figures.
	void Zoom(float Factor);                 //Zooming the graph with factor ( Factor ).
	void Delete();                           //Removing the selected figures from the FigureList.
	void Save(string);                       //Saving the graph.
	void Load(string);                       //Loading a graph.
	void restartGame(CFigure **list,int count); //Restoring the original figures that were drawn before the game.
	void scrum()const;                          //Recreates the figure in random positions to play ( scramble & find ) Game. 
	void DrawScrumFigs(CFigure **List) const;             
    void IsExit(bool,bool);                     //Exiting the program and saving before exiting.
	////////////////////////////////////////////////////

	void CpyFigList(CFigure **&list)const;           //Copying the figures in the FigureList to the list ( List ) .
	CFigure *GetFigure(double x, double y) const;    //Search for a figure given a point inside the figure
	int FiguresCount(FigureType T);                  //Counting the number of Figure that have a type of ( T ).
	int FigCountFill(color F,bool);                  //Counting the number of Figure that have the same color ( F ).
	int FiguresCountT_F(FigureType T, color F,bool); //Counting the number of Figures that have the type and color ( T & F ).
	void DelFig(int);                                //Delete a Figure from the FigureList by its ID .
	void ClearClipBoard();                           //Delete the fiures in the clipboard.
	void MaxMinArea(CFigure *& Max ,CFigure *& Min);      //Find the figure that has the maximum area, and the figure that has the minimum area.
	void RandomFigures(CFigure **List) const;             //ReCreates the figures in random positions.
	CFigure * RandSelect(CFigure **&);
	
//==================================================================================//
//							       Get Functions			        				//
//==================================================================================//

	int getFigCount()const;           //Get The number of figures in the FigureList.

	int GetSelectCount() const;       //Get The number of selected figures in the FigureList.
	int GetClipBoardCount()const;     //Get The number of figures in the clipboard.
	int GetMaxFigCount()const;        //Get The Maximum number of figures in the figure list.
	bool getExit()const;              //Get the Exit boolean to exit the program if it's true.

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output

//////////////////////////////////////////////////////////////////////////////////////

	void UpdateInterface() const;	//Redraws all the drawing window	

	static color stringToColor(string );  //Convert a string to its color.
	static string ColorToString(color);   //Convert a color to its string.

};



#endif