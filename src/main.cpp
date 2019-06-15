#include <Arduino.h>
#include "Screen.h"
#include "DataConversions.h"
#include "wiring_private.h"
#include "Serial_Commands.h"
#include "Globals.h"
#include "Structs.h"

Screen screen;
Serial_Commands _serial_Commands;

int startTime = 0;

void setup()
{

  pinPeripheral(2, PIO_SERCOM);
  pinPeripheral(3, PIO_SERCOM);

  Serial.begin(115200);

  //while(!Serial);

  screen.init();
  _serial_Commands.init();

  // // Initialize TFT hardware.  If this fails, it's usually a problem
  // // with the constructor, like an invalid timer number or data pin.
  // if(tft.begin()) {
  //   Serial.println("Init fail");
  //   pinMode(LED_BUILTIN, OUTPUT);
  //   for(bool i=true;;i=!i) {
  //     digitalWrite(LED_BUILTIN, i);
  //     delay(100);
  //   }
  // }

  // Serial.println("Init OK!");

  // tft.update(); // Clear display

  // startTime = millis();
}

// This draws each frame of animation...
void loop()
{
  ScreenData screenData;

  _serial_Commands.commandsProcess();

  if (_serial_Commands.SpoolHasNewData())
  {
    int diameter = 0;                          // = random(170, 181);
    diameter = _serial_Commands.GetDiameter(); //atof(_serial_Commands.GetDiameter());

    SpcDiameter spcDiameter;
    CONVERT_FLOAT_TO_STRING(diameter, spcDiameter.charDiameterWithDecimal);
    CONVERT_NUMBER_TO_STRING(FLOAT_FORMAT, diameter / (pow(10, 2)), spcDiameter.charDiameterWithDecimal);

    spcDiameter.charDiameterNoDecimal[sizeof(spcDiameter.charDiameterNoDecimal) - 1] = 0;
    spcDiameter.charDiameterWithDecimal[sizeof(spcDiameter.charDiameterWithDecimal) - 1] = 0;
    spcDiameter.decimalPointLocation = _serial_Commands.GetDiameterDecimalLocation();
    spcDiameter.floatDiameterWithDecimal = diameter / (pow(10, spcDiameter.decimalPointLocation));
    spcDiameter.intDiameterNoDecimal = diameter;

    if (_serial_Commands.HasFilamentDiameterError())
    {
      screenData.spcError.errorCode = _serial_Commands.GetDiameterError();
      screenData.spcError.errorDescription = ErrorCodes[screenData.spcError.errorCode];
    }
    else
    {
      screenData.spcError.errorCode = 0;
      screenData.spcError.errorDescription = "";
      screenData.spcDiameter = spcDiameter;
    }

    screen.UpdateDiameter(&screenData);
  }

  if (_serial_Commands.SpoolHasNewData())
  {
    screenData.spool.RPM = _serial_Commands.GetSpoolRPM();
    screen.UpdateSpool(&screenData);
  }

  if (_serial_Commands.PullerHasNewData())
  {
    screenData.puller.RPM = _serial_Commands.GetPullerRPM();
    screen.UpdatePuller(&screenData);
  }
}
