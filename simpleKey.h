#include <Arduino.h>


typedef struct{
  int pin;
  int key_up;
  
}SIMPLE_BTN_t;

SIMPLE_BTN_t btnGroup[] = {
  {14,1},
  {15,1},
  {16,1}
};

void keyInit(SIMPLE_BTN_t btn[])
{
  // int len  = sizeof(btn)/sizeof(btn[0]);
  for (int i = 0; i < 3; i++)
  {
    pinMode(btn[i].pin, INPUT_PULLUP);
  }
}


void keyScan(SIMPLE_BTN_t btn[])
{
  // int len  = sizeof(btn)/sizeof(btn[0]);
  for (int i = 0; i < 3; i++)
  {
    if (btn[i].key_up && !digitalRead(btn[i].pin))
    {
      
      
      switch (i)
      {
      
      case 0:
        Serial.println("key_1");
       
        break;
      case 1:
        Serial.println("key_2");
       
        break;
      case 2:
        Serial.println("key_3");
        
        break;
      }
      btn[i].key_up = 0;

    }
    else if (digitalRead(btn[i].pin))
    {
      btn[i].key_up = 1;
      
    }
  }
}


