#include "debouce_btn.h"


void setup() {
  Serial.begin(115200);
  pixels.begin();
  btn_init(push_btn.pin);
  
}

void loop() {
  // ws_run(ws.lednum);
  btn_scan(push_btn.pin,
          &push_btn.keyup,
          &push_btn.current_time,
          push_btn.debouce_time);
}
