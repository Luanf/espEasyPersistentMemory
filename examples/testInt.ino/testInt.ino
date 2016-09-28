#include <espEasyMemory.h>


espEasyMemory memManager;
int var = 0;
void setup()
{
  Serial.begin(115200);
  SPIFFS.begin();
}

void loop()
{
  
  Serial.println("");
  Serial.println(""); 
  
  if(memManager.recoverIntVariable(&var, "var") > 0 ){
    Serial.println(var);
  }
  else{
    Serial.println("Error! File did not existed!");
  }
  var++;

  memManager.storeIntVariable(var, "var");

  ESP.deepSleep(10000);
}