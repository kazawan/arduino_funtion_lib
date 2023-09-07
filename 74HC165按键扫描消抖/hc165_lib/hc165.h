#ifndef HC165_H
#define HC165_H
#include "Arduino.h"

#define _weak_ __attribute__((weak))
#define sample_rate 1000
#define LATCHDOWN(latch) digitalWrite(latch,0)
#define LATCHUP(latch) digitalWrite(latch,1)
#define CLKDOWN(clock) digitalWrite(clock,0)
#define CLKUP(clock) digitalWrite(clock,1)
#define UNUSED(X) (void)X //需加这个在weak函数中...否侧程序跑飞

struct HC165_typeDef
{
    uint8_t data_pin;
    uint8_t clock_pin;
    uint8_t latch_pin;
    int key_num;

};

struct KEYMAP_typeDef
{
    uint8_t key_value;
};

struct BTN165_typeDef
{
    int keyup;
    int current_time;
    unsigned int debouce_time; // 消抖时间
    int state;
};

_weak_ void  press_handler();
_weak_ void  release_handler();

void hc165_init(HC165_typeDef *hc165,BTN165_typeDef *btn165,int key_num);
void hc165_scan(HC165_typeDef *hc165,KEYMAP_typeDef *key_map,BTN165_typeDef *btn165);

#endif