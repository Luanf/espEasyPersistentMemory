#include <espEasyMemory.h>


espEasyMemory memManager;

String varString = "";
void setup()
{
  Serial.begin(115200);
  SPIFFS.begin();
}

void loop()
{
  
  Serial.println("");
  Serial.println(""); 
  
  if(memManager.recoverStringVariable(&varString, "varString") > 0 ){
    Serial.println(varString);
  }
  else{
    Serial.println("Error! File did not existed!");
  }
  varString = varString + ".";

  memManager.storeStringVariable(varString, "varString");

  ESP.deepSleep(10000);
}
