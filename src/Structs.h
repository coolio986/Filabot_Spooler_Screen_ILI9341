/*
 * Structs.h
 *
 * Created: 5/23/2019 4:42:21 PM
 *  Author: Anthony
 */ 


#ifndef STRUCTS_H_
#define STRUCTS_H_



typedef struct
{
	uint16_t hardwareType; //see hardwareTypes.h
	char *command;
	char *value;
} SerialCommand;

typedef struct 
{
	char charDiameterNoDecimal[10];
	char charDiameterWithDecimal[10];
	int decimalPointLocation;
	uint16_t intDiameterNoDecimal;
	float floatDiameterWithDecimal;
} SpcDiameter;

typedef struct
{
	char *errorDescription;
	byte errorLevel;
	byte errorCode;

} SpcError;

typedef struct
{
	char *RPM;
	
} Puller;

typedef struct
{
	char *RPM;
	char *Weight;
	char *Slippage;
} Spool;


typedef struct
{
	SpcDiameter spcDiameter;
	SpcError spcError;
	Puller puller;
	Spool spool;

} ScreenData;

const int DATASTREAM_VALIDATION_FAILED = 1;
const int DEVICE_DISCONNECTED = 2;

//errorLevel:
// 1 = datastream validation failed
// 2 = device disconnected
// 3 = undefined

const int DIAMETER_DEVICE_DISCONNECTED  = 1;
const int SPC_DATA_ERROR = 2;
//errorCode:
// 1 = DIAMETER DEVICE DISCONNECTED
// 2 = SPC DATA ERROR

typedef struct{
	byte datastream_validation_failed; //indicator
	byte device_disconnected; //spooler
	
} struct_errorLevels;

const static struct_errorLevels errorLevel =
{
	.datastream_validation_failed = DATASTREAM_VALIDATION_FAILED,
	.device_disconnected = DEVICE_DISCONNECTED,
};

typedef struct{
	byte diameter_device_disconnected; //indicator
	byte spc_data_error; //spooler
	
} struct_errorCodes;

const static struct_errorCodes errorCode =
{
	.diameter_device_disconnected = DIAMETER_DEVICE_DISCONNECTED,
	.spc_data_error = SPC_DATA_ERROR,
};


static char *ErrorCodes[3] =
{
		"RESERVED",
		"DIAMETER   DISCONNECT",
		"SPC  DATA  ERROR"
};







#endif /* STRUCTS_H_ */