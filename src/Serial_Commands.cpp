/*
* Serial_Commands.cpp
*
* Created: 3/13/2019 3:35:39 PM
* Author: Anthony
*/

#include "Serial_Commands.h"
#include <Arduino.h>
#include "Serial_Processing.h"
#include "Globals.h"

char *ConcantenateCharandInt(char *s1, uint32_t number);
uint16_t filamentDiameter;
uint8_t filamentDiameterDecimalLocation;
bool diameterHasNewData = false;
bool hasFilamentDiameterError = false;
bool spoolHasNewData = false;
bool pullerHasNewData = false;
uint16_t filamentDiameterCode = 0;
char *spoolRPM = {0};
char *pullerRPM = {0};

Serial_Processing _Serial_Processing;

CMD_STR(SPCDiameter, "");
CMD_STR(SPCDiameterDecimalLocation, "");
CMD_STR(SPCDiameterError, "");
CMD_STR(SpoolRPM, "");
CMD_STR(PullerRPM, "");

sCommand Cmds[] =
    {
        COMMAND(SPCDiameter),
        COMMAND(SPCDiameterDecimalLocation),
        COMMAND(SPCDiameterError),
        COMMAND(SpoolRPM),
        COMMAND(PullerRPM),
        {"", 0}

};

static int SPCDiameter_cmd(int argc, char str[MAX_CMD_LENGTH], char arguments[MAX_CMD_LENGTH])
{
  //Serial.println(str);
  filamentDiameter = atoi(arguments);
  //diameterHasNewData = true;
}

static int SPCDiameterDecimalLocation_cmd(int argc, char str[MAX_CMD_LENGTH], char arguments[MAX_CMD_LENGTH])
{
  //Serial.println(str);
  filamentDiameterDecimalLocation = atoi(arguments);
  diameterHasNewData = true;
}

static int SPCDiameterError_cmd(int argc, char str[MAX_CMD_LENGTH], char arguments[MAX_CMD_LENGTH])
{
  hasFilamentDiameterError = true;
  filamentDiameterCode = atoi(arguments);
  Serial.println(arguments);
  //Serial.println(str);
  //filamentDiameterDecimalLocation = atoi(arguments);
  diameterHasNewData = true;
}

static int SpoolRPM_cmd(int argc, char str[MAX_CMD_LENGTH], char arguments[MAX_CMD_LENGTH])
{
  spoolRPM = arguments;
  //Serial.print(arguments);
  spoolHasNewData = true;
}

static int PullerRPM_cmd(int argc, char str[MAX_CMD_LENGTH], char arguments[MAX_CMD_LENGTH])
{
  pullerRPM = arguments;
  //Serial.print(arguments);
  pullerHasNewData = true;
}

void Serial_Commands::init(void)
{
  _Serial_Processing.Setup();
}

int Serial_Commands::commandsProcess(void)
{

  _Serial_Processing.CommandsProcess(Cmds);
}

char *ConcantenateCharandInt(char *s1, uint32_t number)
{

  char *output;
  output = new char[MAX_CMD_LENGTH + 1];
  output = s1;

  sprintf(output + strlen(output), "%d", number);

  return output;
}

uint16_t Serial_Commands::GetDiameter(void)
{
  diameterHasNewData = false;
  return filamentDiameter;
}

uint8_t Serial_Commands::GetDiameterDecimalLocation(void)
{
  diameterHasNewData = false;
  return filamentDiameterDecimalLocation;
}

uint16_t Serial_Commands::GetDiameterError(void)
{
  diameterHasNewData = false;
  hasFilamentDiameterError = false;
  return filamentDiameterCode;
}

char *Serial_Commands::GetSpoolRPM(void)
{
  spoolHasNewData = false;
  
  return spoolRPM;
}

char *Serial_Commands::GetPullerRPM(void)
{
  pullerHasNewData = false;
  
  return pullerRPM;
}

bool Serial_Commands::DiameterHasNewData(void)
{
  return diameterHasNewData;
}

bool Serial_Commands::HasFilamentDiameterError(void)
{
  return hasFilamentDiameterError;
}

bool Serial_Commands::SpoolHasNewData(void)
{
  
  return spoolHasNewData;
}

bool Serial_Commands::PullerHasNewData(void)
{
  
  return pullerHasNewData;
}
// default constructor
Serial_Commands::Serial_Commands()
{
} //Serial_Commands

// default destructor
Serial_Commands::~Serial_Commands()
{
} //~Serial_Commands
