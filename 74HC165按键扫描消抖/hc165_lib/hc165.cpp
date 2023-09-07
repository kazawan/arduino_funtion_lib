
#include "hc165.h"

void  press_handler()
{
  UNUSED(1);
};

void  release_handler()
{
  UNUSED(1);
};

void hc165_init(HC165_typeDef *hc165,BTN165_typeDef *btn165,int key_num)
{
    int i;
    pinMode(hc165->data_pin, INPUT);
    pinMode(hc165->clock_pin, OUTPUT);
    pinMode(hc165->latch_pin, OUTPUT);
    for(i=0;i<key_num;i++)
    {
        btn165[i].keyup = 1;
        btn165[i].current_time = 0;
        btn165[i].debouce_time = 30;
        btn165[i].state = 0;
    }
};


void hc165_scan(HC165_typeDef *hc165,KEYMAP_typeDef *key_map,BTN165_typeDef *btn165){
    int j;
    for(j = 0 ;j < sample_rate; j++)
    {
        LATCHDOWN(hc165->latch_pin);
        LATCHUP(hc165->latch_pin);
        if(j < sample_rate - 1)
        {
            for(int i = 0 ; i < hc165->key_num; i++)
            {
                btn165[i].state = digitalRead(hc165->data_pin);
                CLKUP(hc165->clock_pin);
                CLKDOWN(hc165->clock_pin);
            }
        }else if(j == sample_rate - 1)
        {
            for(int i = 0 ; i < hc165->key_num;i++)
            {
                if(btn165[i].state == 1 && btn165[i].keyup == 1 && btn165[i].state == digitalRead(hc165->data_pin))
                {
                    if(millis() - btn165[i].current_time > btn165[i].debouce_time)
                    {
                        btn165[i].keyup = 0;
                        btn165[i].current_time = millis();
                        // Serial.print("press: ");
                        press_handler();
                        Serial.println(key_map[i].key_value);
                    }
                }else if(btn165[i].keyup == 0 && btn165[i].state == 0)
                {
                    release_handler();
                    Serial.println(key_map[i].key_value);
                    btn165[i].keyup = 1;
                }
                CLKUP(hc165->clock_pin);
                CLKDOWN(hc165->clock_pin);
            }

        }
    }
};