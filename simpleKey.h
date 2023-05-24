#include <Arduino.h>
#define btn 23

typedef struct{
  byte pin;
  unsigned char key_up = 1;
  
}SIMPLE_BTN_t;

SIMPLE_BTN_t btnGroup[] = {
  {14,1},
  {15,1},
  {16,1}
};

void keyInit(SIMPLE_BTN_t b[])
{
  int len  = sizeof(b)/sizeof(b[0]);
  for(int i = 0 ; i < len ; i++ )
  {
    pinMode(b[i].pin,INPUT_PULLUP);
  }
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


