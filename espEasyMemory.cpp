#include "Arduino.h"
#include "espEasyMemory.h"
#include <FS.h>




/* Return values: Success -> 1 if filename already existed, else 2. 
				  Fail    -> -1 */
int espEasyMemory::storeIntVariable(int variable, String filename){
	int returnValue;
	File file;

	if (SPIFFS.exists(filename)){ //file already existed
		returnValue = 1;
	}
	else{
		returnValue = 2;
	}

	file = SPIFFS.open(filename, "w");
	file.println(String(variable)); // writes as a String for simplicity, since we can easily add a '\n' with println. We could do a traditional write here too, but then we have to use traditional read on the recover methods.
	file.close();

	if (!SPIFFS.exists(filename)){ //Check if the file was created
		return -1;
	}
	else{
		return (returnValue);
	}
}

int espEasyMemory::storeFloatVariable(float variable, int decimalPoints, String filename){

	int returnValue;
	File file;

	if (SPIFFS.exists(filename)){ //file already existed
		returnValue = 1;
	}
	else{
		returnValue = 2;
	}

	file = SPIFFS.open(filename, "w");
	file.println(String(variable, decimalPoints)); //Writes as a String for simplicity, since we can easily add a '\n' with println. We could do a traditional write here too, but then we have to use traditional read on the recover methods.
	file.close();

	if (!SPIFFS.exists(filename)){ //Check if the file was created
		return -1;
	}
	else{
		return (returnValue);
	}

}

int espEasyMemory::storeDoubleVariable(double variable, int decimalPoints, String filename){

	int returnValue;
	File file;

	if (SPIFFS.exists(filename)){ //file already existed
		returnValue = 1;
	}
	else{
		returnValue = 2;
	}

	file = SPIFFS.open(filename, "w");
	file.println(String(variable, decimalPoints)); //Writes as a String for simplicity, since we can easily add a '\n' with println. We could do a traditional write here too, but then we have to use traditional read on the recover methods.
	file.close();

	if (!SPIFFS.exists(filename)){ //Check if the file was created
		return -1;
	}
	else{
		return (returnValue);
	}


}

int espEasyMemory::storeStringVariable(String variable, String filename){

	int returnValue;
	File file;

	if (SPIFFS.exists(filename)){
		returnValue = 1;
	}
	else{
		returnValue = 2;
	}

	file = SPIFFS.open(filename, "w");
	file.println(variable);
	file.close();

	if (!SPIFFS.exists(filename)){
		return -1;
	}
	else{
		return (returnValue);
	}
}

int espEasyMemory::recoverIntVariable(int *variable, String filename){

	if (!SPIFFS.exists(filename)){ // Trying to recover from a file that does not exist
		return -1; 
	}

	File file = SPIFFS.open(filename, "r");
	int recoveredValue = file.parseInt();
	file.close();

	*variable = recoveredValue;

	return 1;
}
int espEasyMemory::recoverStringVariable(String *variable, String filename){

	if (!SPIFFS.exists(filename)){ // Trying to recover from a file that does not exist
		return -1; 
	}

	File file = SPIFFS.open(filename, "r");
	String recoveredString = file.readStringUntil('\n');
	file.close();

	*variable = recoveredString;

	return 1;
	
}
int espEasyMemory::recoverFloatVariable(float *variable, String filename){

	if (!SPIFFS.exists(filename)){ // Trying to recover from a file that does not exist
		return -1; 
	}

	File file = SPIFFS.open(filename, "r");
	int recoveredValue = file.parseFloat();
	file.close();

	*variable = recoveredValue;

	return 1;
}
int espEasyMemory::recoverDoubleVariable(double *variable, String filename){

	if (!SPIFFS.exists(filename)){ // Trying to recover from a file that does not exist
		return -1; 
	}

	File file = SPIFFS.open(filename, "r");
	int recoveredValue = file.parseFloat();
	file.close();

	*variable = recoveredValue;

	return 1;
	
}

void espEasyMemory::format(){
	SPIFFS.format();
}
