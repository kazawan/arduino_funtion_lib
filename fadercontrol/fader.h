#include <Arduino.h>

#define LED_BUILTIN 13

struct RxCmd{
  String cmd;
  String cmd_tag; 
};

RxCmd rxCmd = {"", "/"};

int cmd_flag = 0;

void ledTask()
{
  switch (cmd_flag)
  {
    case 0:
      digitalWrite(LED_BUILTIN, 1);
      delay(1000);
      digitalWrite(LED_BUILTIN, 0);
      delay(1000);
      break;
    case 1:
      digitalWrite(LED_BUILTIN, 1);
      delay(100);
      digitalWrite(LED_BUILTIN, 0);
      delay(100);
      break;
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ledTask();
}


void serialEvent1(){
  while(Serial1.available()){
    rxCmd.cmd += char(Serial1.read());
    delay(2);
  };
  if(rxCmd.cmd.indexOf(rxCmd.cmd_tag) >= 0){
    cmd_flag = 1;
    rxCmd.cmd = "";
  }else{
    cmd_flag = 0;
    rxCmd.cmd = "";
  }
}
