#include <Arduino.h>
#define btn 23

void keyInit()
{
  pinMode(btn, INPUT_PULLUP); 
}


void keyScan()
{
  static unsigned char key_up = 1;
  

  // sw key
  if (key_up && !digitalRead(btn))
  {
    //按下状态
    key_up = 0;
    
  }
  else if (digitalRead(btn))
  {
    key_up = 1;
    //抬起状态
  }


}


