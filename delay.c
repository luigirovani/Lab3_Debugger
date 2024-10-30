// delay.c
#include "delay.h"
#include <time.h>
#include <stdio.h>

void __delay_ms(unsigned int ms) {
    clock_t start_time = clock();
    while (clock() < start_time + ms * (CLOCKS_PER_SEC / 1000));
}