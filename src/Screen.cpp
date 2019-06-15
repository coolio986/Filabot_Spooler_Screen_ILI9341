/*
* Screen.cpp
*
* Created: 4/3/2019 11:10:52 AM
* Author: Anthony
*/

#include "Screen.h"
#include <Adafruit_TFTDMA.h>
#include "Adafruit_GFX.h"
#include "Queue.h"
#include "Structs.h"
#include "Fonts/FreeSans12pt7b.h"
#include "Fonts/FreeSans9pt7b.h"
#include "diameter.c"

#include "DataConversions.h"
#include "Error.h"

// TFT hardware config:
#define TC 2		   // Timer/counter index
#define RESET A0	   // Reset pin (-1 if not used)
#define CS A4		   // Chip-select pin (-1 if not used -- tie to GND)
#define CD A3		   // Command/data pin
#define RD A2		   // Read-strobe pin
#define WR A5		   // Write-strobe pin (CCL-modified output from timer)
#define D0 13		   // Data bit 0 pin (MUST be on PORT byte boundary)
#define PERIPH PIO_CCL // Peripheral type of WR pin (PIO_CCL, PIO_TIMER, etc.)

TFT_framebuffer tft(TC, RESET, CS, CD, RD, WR, D0, PERIPH);

Screen *Screen::firstInstance;
int i = 0;

int graphFilamentDiameter;

uint16_t graphColor = ILI9341_BLUE;
uint16_t pointColor = ILI9341_BLACK;
uint16_t lineColor = ILI9341_LIGHTBLUE;
uint16_t upperLimitColor = ILI9341_RED;
uint16_t lowerLimitColor = ILI9341_RED;
uint16_t nominalDiameterColor = ILI9341_LIMEGREEN;

uint16_t upperLimit = 180;
uint16_t lowerLimit = 170;
uint16_t nominalDiameter = 175;

const int numberOfHorizontalDivisions = 80;
Queue<int> yLocationStack(numberOfHorizontalDivisions);

int graphRange = 180;
int markSize = 3;

//const int numberOfVerticalDivisions = 3;

const int originX = 0;
const int originY = 239;
const int sizeX = 320;
const int sizeY = 150;
//const int deviation = originX;

int boxSize = (sizeX / numberOfHorizontalDivisions);
//int mark[] = {(boxSize + deviation), ((boxSize * 2) + deviation), ((boxSize * 3) + deviation), ((boxSize * 4) + deviation), ((boxSize * 5) + deviation), ((boxSize * 6) + deviation), ((boxSize * 7) + deviation), ((boxSize * 8) + deviation)};
int *mark = (int *)malloc(numberOfHorizontalDivisions * sizeof(int));
const int minorSizeY = (originY + 10);
const int minorSizeX = (originX - 10);

int divisionNumbers[] = {lowerLimit, 175, upperLimit}; // number of divisions must match variable "numberOfVerticalDivisions"
int verticalDivisions = sizeof(divisionNumbers) / sizeof(divisionNumbers[0]);

uint16_t *verticalPixels = (uint16_t *)malloc(240 * sizeof(uint16_t));

bool isInit = false;
bool previousHadError = false;

// default constructor
Screen::Screen()
{
	if (!firstInstance)
	{
		firstInstance = this;
	}
} //Screen

void Screen::init()
{

	if (tft.begin())
	{
		Serial.println("Init fail");
		pinMode(LED_BUILTIN, OUTPUT);
		for (bool i = true;; i = !i)
		{
			digitalWrite(LED_BUILTIN, i);
			delay(100);
		}
	}

	tft.waitForUpdate();

	tft.fillScreen(ILI9341_BLACK);
	tft.setRotation(ROTATION180);
	tft.setFont(&FreeSans12pt7b);

	tft.update();

	for (int i = 0; i < numberOfHorizontalDivisions; i++)
	{
		mark[i] = (boxSize * i);
	}

	ScreenData screenData;
	UpdateDiameter(&screenData);
	UpdateSpool(&screenData);
	//errorVector.setStorage(errorArray);
	//
	//Error error;
	//
	//
	//error_vector.push_back(error);
	//error_vector.remove(0);
	isInit = true;
}
void Screen::UpdateScreen(SpcDiameter *spcDiameter)
{
	tft.waitForUpdate();
	tft.setFont(&FreeSans12pt7b);
	tft.setCursor(0, 25);
	tft.fillRect(0, 0, 320, (originY - sizeY), ILI9341_BLACK);
	graphFilamentDiameter = constrain(spcDiameter->intDiameterNoDecimal, 170, 180); //random(170, 180);

	//ScreenData screenData;
	//UpdateDiameter(&screenData);

	//UpdateSpool(&screenData);
	//UpdateWheels();

	graph();
	isInit = true;

	tft.update();
}

void Screen::UpdateDiameter(SpcDiameter *spcDiameter)
{

	tft.waitForUpdate();
	tft.setCursor(0, 25);
	tft.fillRect(0, 0, 320, (originY - sizeY), ILI9341_BLACK);

	graphFilamentDiameter = constrain(spcDiameter->intDiameterNoDecimal, 170, 180); //random(170, 180);

	tft.setTextSize(1);
	tft.setTextColor(ILI9341_LIMEGREEN, ILI9341_BLACK);

	if (!isInit)
	{
		tft.println("Diameter: 0.00");
	}
	else
	{
		tft.print("Diameter: ");
		tft.println(spcDiameter->charDiameterWithDecimal);
	}
	graph();
	tft.update();
}

void Screen::UpdateDiameter(ScreenData *screenData)
{
	SpcDiameter spcDiameter = screenData->spcDiameter;

	tft.waitForUpdate();
	tft.setFont(&FreeSans12pt7b);
	tft.setCursor(0, 18);
	//tft.fillRect(0, 0, 320, 30, ILI9341_BLACK);
	tft.fillRect(0, 0, 320, 19, ILI9341_BLACK);

	tft.setTextSize(1);
	tft.setTextColor(ILI9341_LIMEGREEN, ILI9341_BLACK);

	if (screenData->spcError.errorCode > 0)
	{
		tft.setTextColor(ILI9341_RED, ILI9341_BLACK);
		tft.println(ErrorCodes[screenData->spcError.errorCode]);
	}
	else
	{
		graphFilamentDiameter = constrain(spcDiameter.intDiameterNoDecimal, 170, 180); //random(170, 180);

		if (!isInit)
		{
			tft.println("Diameter: 0.00");
		}
		else
		{
			//tft.print("Diameter: ");
			//tft.println(spcDiameter.charDiameterWithDecimal);
			char c[50] = {0};
			ConcantenateChars("         Diameter: ", spcDiameter.charDiameterWithDecimal, c);
			ConcantenateChars(c, " mm", c);

			tft.println(c);
			graph();
		}
	}

	tft.update();
}

void Screen::UpdateSpool(ScreenData *screenData)
{
	tft.waitForUpdate();
	tft.setFont(&FreeSans9pt7b);
	tft.setCursor(0, 40);
	tft.fillRect(0, 23, 170, 25, ILI9341_BLACK);

	tft.setTextSize(1);
	tft.setTextColor(ILI9341_LIMEGREEN, ILI9341_BLACK);
	if (!isInit)
	{
		tft.println("Spool RPM: 0");
		tft.println("Spool Weight: 0 g");
		tft.println("Spool Slippage: 0 g");
	}
	else
	{
		//char randomNum[5] = {0};
		//CONVERT_NUMBER_TO_STRING(INT_FORMAT, random(0, 1000), randomNum); //random for now
		tft.print("Spool RPM: ");
		tft.println(screenData->spool.RPM);
	}

	tft.update();
}

void Screen::UpdatePuller(ScreenData *screenData)
{
	tft.waitForUpdate();
	tft.setFont(&FreeSans9pt7b);
	tft.setCursor(170, 40);
	tft.fillRect(170, 23, 320, 25, ILI9341_BLACK);

	tft.setTextSize(1);
	tft.setTextColor(ILI9341_LIMEGREEN, ILI9341_BLACK);

	if (!isInit)
	{
		tft.println("Puller RPM: 0");
	}
	else
	{
		//char randomNum[5] = {0};
		//CONVERT_NUMBER_TO_STRING(INT_FORMAT, random(0, 1000), randomNum); //random for now
		tft.print("Puller RPM: ");
		tft.println(screenData->puller.RPM);
	}

	tft.update();
}

//original graph
//void graph()
//{
//
//int yLocation = map(_diameter, verticalMaxValue, verticalMinValue, originY, (originY - sizeY));
//yLocationStack.push( yLocation);
//
//
//if (yLocationStack.count() < numberOfHorizontalDivisions)
//{
//
//if (yLocationStack.count() > 1)
//{
//int xLocation = mark[yLocationStack.count()];
//
//
////if (lastXPosition != 0)
////{
////void ILI9341_due::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
//tft.drawLine(mark[yLocationStack.count()], yLocation, mark[yLocationStack.count() - 1], yLocationStack.peekAt(yLocationStack.count() - 2), lineColor);
//}
//
//}
//else
//{
//// clear the graph's canvas
//tft.fillRect((originX), (originY - sizeY), sizeX, sizeY, ILI9341_BLACK);
//
//for(int i = 0; i < yLocationStack.count() - 1; i++)
//{
//tft.drawLine(mark[i], yLocationStack.peekAt(yLocationStack.count() - (i + 1)), mark[i + 1], yLocationStack.peekAt(yLocationStack.count() - (i + 2)), lineColor);
//}
//}
//}

void Screen::graph(void)
{

	int yLocation = map(graphFilamentDiameter, lowerLimit, upperLimit, originY, (originY - sizeY));
	int _upperLimit = map(upperLimit, lowerLimit, upperLimit, originY, (originY - sizeY));
	int _lowerLimit = map(lowerLimit, lowerLimit, upperLimit, originY, (originY - sizeY));
	int _nominalDiameter = map(nominalDiameter, lowerLimit, upperLimit, originY, (originY - sizeY));
	yLocationStack.push(yLocation);

	if (yLocationStack.count() < numberOfHorizontalDivisions)
	{

		if (yLocationStack.count() > 1)
		{
			tft.drawLine(mark[yLocationStack.count()], yLocationStack.peekAt(yLocationStack.count() - 1), mark[yLocationStack.count() - 1], yLocationStack.peekAt(yLocationStack.count() - 2), lineColor);
		}
	}
	else
	{
		// clear the graph's canvas
		tft.fillRect((originX), (originY - sizeY), sizeX, sizeY, ILI9341_BLACK);
		//tft.sully(originX, (originY - sizeY));
		///tft.sully(sizeX,sizeY);

		for (int i = 0; i < yLocationStack.count() - 1; i++)
		{
			//tft.drawLine(mark[i], yLocationStack.peekAt(numberOfHorizontalDivisions - (i + 1)), mark[i + 1], yLocationStack.peekAt(numberOfHorizontalDivisions- (i + 2)), lineColor);
			//tft.drawLine(mark[numberOfHorizontalDivisions - (i + 1)], yLocationStack.peekAt(i + 1), mark[numberOfHorizontalDivisions - ( i + 2)], yLocationStack.peekAt(i + 2), lineColor);
			
			if (yLocationStack.peekAt(i) >= _upperLimit && yLocationStack.peekAt(i) <= _lowerLimit && yLocationStack.peekAt(i + 1) >= _upperLimit && yLocationStack.peekAt(i + 1) <= _lowerLimit)
			{
				//int16_t y0 = yLocationStack.peekAt(i);
				//int16_t y1 = yLocationStack.peekAt(i + 1);
				tft.drawLine(mark[i], yLocationStack.peekAt(i), mark[i + 1], yLocationStack.peekAt(i + 1), lineColor);
			}
			
			
		}
	}
	//Draw horizontal lines after diameter line
	tft.drawLine(0, _upperLimit, 320, _upperLimit, upperLimitColor);
	tft.drawLine(0, _lowerLimit, 320, _lowerLimit, lowerLimitColor);
	tft.drawLine(0, _nominalDiameter, 320, _nominalDiameter, nominalDiameterColor);
}

void ConcantenateChars(char *buffer_A, char *buffer_B, char *outputBuffer)
{
	sprintf(outputBuffer, SCREENFORMAT, buffer_A, buffer_B);
}



void Screen::DisplayError(void)
{
	//for (int i = 0; i < 10; i++)
	//{
	//errors[i] = eError[i];
	//}

	//errors = *eError;
}

void Screen::ClearError(void)
{
	//error.errorLevel = 0;
}

// default destructor
Screen::~Screen()
{
} //~Screen
