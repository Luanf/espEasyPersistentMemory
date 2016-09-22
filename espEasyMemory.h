#ifndef espEasyMemory_h
#define espEasyMemory_h
#include "Arduino.h"
#include <FS.h>

class espEasyMemory{
public:
	int storeIntVariable(int variable, String filename);
	int storeFloatVariable(float variable, int decimalPoints, String filename);
	int storeDoubleVariable(double variable, int decimalPoints, String filename);
	int storeStringVariable(String variable, String filename);
	int recoverIntVariable(int *variable, String filename);
	int recoverStringVariable(String *variable, String filename);
	int recoverFloatVariable(float *variable, String filename);
	int recoverDoubleVariable(double *variable, String filename);
};
#endif
