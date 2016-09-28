#include <espEasyMemory.h>
#define FORMAT_TAG 1

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

  if(FORMAT_TAG){
    memManager.format();
    Serial.println("Finished formatting!");
    Serial.println("Please flash me again now");
    delay(999999999);
  }

  //code
  //more code
  //more more code
  //more more more code
  //more more code
  //more code
  //code
  
}

