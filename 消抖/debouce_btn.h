

//定义按钮
typedef struct BTN_t
{
  byte pin;管教
  int keyup;
  int current_time;
  unsigned int debouce_time;
};

BTN_t push_btn = {7, 1, 0,150};

int count;

//**************************
//初始化
void btn_init(byte p)
{
  pinMode(p, INPUT_PULLUP);
}


//按键扫描
void btn_scan(byte p, int *keyup, int *t,unsigned int debouce)
{
  if (*keyup && !digitalRead(p))
  {
    if(millis() - *t > debouce)
    {
      *keyup = 0;
      Serial.println("d");
      *t = millis();
    }
  } else if (digitalRead(p))
  {
    *keyup = 1;
  }
}
