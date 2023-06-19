//todo 优化



#define DATA 25
#define CLOCK 26
#define LATCH 27
#define SAMPLE_RATE 1000 //采样次数
const int numBits = 8; //按键数量 位号码



struct BTN_t
{
  int key_code;              // key
  int keyup;                 // 按键状态
  int current_time;          // 时间
  unsigned int debouce_time; // 消抖时间
  int state;                 // 状态 1 按下 0 未按下
};

BTN_t btn[] = {
    {1, 1, 0, 50, 0},
    {2, 1, 0, 50, 0},
    {3, 1, 0, 50, 0},
    {4, 1, 0, 50, 0},
    {5, 1, 0, 50, 0},
    {6, 1, 0, 50, 0},
    {7, 1, 0, 50, 0},
    {8, 1, 0, 50, 0},
};

//初始化
void shifter_init()
{
  pinMode(DATA, INPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
};

//按键扫描
void shifter_read()
{
  for (int i = 0; i < SAMPLE_RATE; i++)
  {
    digitalWrite(LATCH, 0);
    digitalWrite(LATCH, 1);
    // Serial.print("Bits: ");
    if (i < SAMPLE_RATE - 1)
    {
      for (int i = 0; i < numBits; i++)
      {
        btn[i].state = digitalRead(DATA);

        digitalWrite(CLOCK, 1);
        digitalWrite(CLOCK, 0);
      }
    }
    else if (i == SAMPLE_RATE - 1)
    {
      for (int i = 0; i < numBits; i++)
      {
        if (btn[i].state == 1 && btn[i].keyup == 1 && btn[i].state == digitalRead(DATA))
        {
          if (millis() - btn[i].current_time > btn[i].debouce_time)
          {
            btn[i].current_time = millis();
            btn[i].keyup = 0;
            Serial.print("按下: ");
            press(i);
          }
        }
        else if (btn[i].keyup == 0 && btn[i].state == 0 )
        {
          Serial.print("稀放: ");
          release(i);
          btn[i].keyup = 1;
        }

        digitalWrite(CLOCK, 1);
        digitalWrite(CLOCK, 0);
      }
    }
  }

  // Serial.println();
  // delayMicroseconds(80);
  // delay(1000);
};


//按下
void press(int i)
{
  switch (i)
  {
  case KEY_1:
    Serial.println("KEY_1");
    bleKeyboard.press('1');

    break;
  case KEY_2:
    Serial.println("KEY_2");
    bleKeyboard.press('2');

    break;
  case KEY_3:
    Serial.println("KEY_3");
    bleKeyboard.press('3');

    break;
  case KEY_4:
    Serial.println("KEY_4");
    bleKeyboard.press('4');

    break;
  case KEY_5:
    Serial.println("KEY_5");
    bleKeyboard.press('5');

    break;
  case KEY_6:
    Serial.println("KEY_6");
    bleKeyboard.press('6');

    break;
  case KEY_7:
    Serial.println("KEY_7");
    bleKeyboard.press('7');

    break;
  case KEY_8:
    Serial.println("KEY_8");
    bleKeyboard.press('8');

    break;
  }
}


//释放
void release(int i)
{
  switch (i)
  {
  case KEY_1:
    Serial.println("KEY_1");
  
    bleKeyboard.release('1');
    break;
  case KEY_2:
    Serial.println("KEY_2");
  
    bleKeyboard.release('2');
    break;
  case KEY_3:
    Serial.println("KEY_3");
  
    bleKeyboard.release('3');
    break;
  case KEY_4:
    Serial.println("KEY_4");
  
    bleKeyboard.release('4');
    break;
  case KEY_5:
    Serial.println("KEY_5");
  
    bleKeyboard.release('5');
    break;
  case KEY_6:
    Serial.println("KEY_6");
  
    bleKeyboard.release('6');
    break;
  case KEY_7:
    Serial.println("KEY_7");
  
    bleKeyboard.release('7');
    break;
  case KEY_8:
    Serial.println("KEY_8");
  
    bleKeyboard.release('8');
    break;
  }
}
