/* 
* Screen.h
*
* Created: 4/3/2019 11:10:52 AM
* Author: Anthony
*/


#ifndef __SCREEN_H__
#define __SCREEN_H__
#include <Arduino.h>
#include "Error.h"
#include "Structs.h"


class Screen
{
//******variables******//
public:
	bool IsInSimulationMode;

protected:

private:
	float SPCDiameter;


	//*****FUNCTIONS***/////
	public:
	void UpdateDiameter(SpcDiameter *spcDiameter);
	void UpdateDiameter(ScreenData *screenData);
	void UpdateSpool(ScreenData *screenData);
	void UpdatePuller(ScreenData *screenData);
	protected:

	private:
	void graph(void);
	
	
	









//*******functions******//
public:
	Screen();
	~Screen();
	void init();
	void UpdateScreen(SpcDiameter *spcDiameter);
	void UpdateScreen(double diameter);
	void ClearError(void);
	void AddError(Error *eError);

protected:

private:
	Screen( const Screen &c );
	Screen& operator=( const Screen &c );
	static Screen *firstInstance;
	void RunScreenSimulation();
	void DisplayError(void);
	
	

}; //Screen

void ConcantenateChars(char *buffer_A, char *buffer_B, char *outputBuffer);
void drawGraph();
void graph();

#endif //__SCREEN_H__
