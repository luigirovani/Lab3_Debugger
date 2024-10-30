#include "pic18f4550_sim.h"
#include <stdint.h>
#include "delay.h"
#include <stdio.h>
#include <windows.h>


#define _XTAL_FREQ 20000000
#define DELAY 100

const uint8_t MAX_COUNT = 9;
const uint8_t MIN_COUNT = 0;

volatile struct PORTD_t PORTDbits;
volatile struct PORTC_t PORTCbits;
volatile struct TRISD_t TRISDbits;
volatile struct TRISC_t TRISCbits;
volatile uint8_t RBPU = 1;


void check_SW_10(uint8_t SW_10, uint8_t* count) {
    if (SW_10 == 0) {
        __delay_ms(DELAY);
        if ((*count) < MAX_COUNT) {
            (*count)++;
        }
    }
}

void check_SW_11(uint8_t SW_11, uint8_t* count) {
    if (SW_11 == 0) {
        __delay_ms(DELAY);
        if ((*count) > MIN_COUNT) {
            (*count)--;
        }
    }
}

void print_PORTD_values() {
    while (1) {
        printf("PORTD Values: %d%d%d%d\n",
            PORTDbits.RD0, PORTDbits.RD1, PORTDbits.RD2, PORTDbits.RD3);
        __delay_ms(DELAY);
    }
}

DWORD WINAPI thread_print(LPVOID lpParam) {
    print_PORTD_values();
    return 0;
}

DWORD WINAPI simulate_random_button_press(LPVOID lpParam) {
    srand((unsigned int)time(NULL)); 
    while (1) {
        int random_button = rand() % 2; 

        if (random_button == 0) {
            PORTCbits.RC0 = 0;  
            __delay_ms(100);     
            PORTCbits.RC0 = 1;  
        }
        else {
            PORTCbits.RC1 = 0; 
            __delay_ms(100);     
            PORTCbits.RC1 = 1;   
        }

    }
    return 0;
}


void print_LED(uint8_t count) {
    uint8_t bcd = count & 0x0F;

    PORTDbits.RD0 = (bcd >> 0) & 1;
    PORTDbits.RD1 = (bcd >> 1) & 1;
    PORTDbits.RD2 = (bcd >> 2) & 1;
    PORTDbits.RD3 = (bcd >> 3) & 1;
}


void main(void) {
    TRISCbits.RC0 = 1;
    TRISCbits.RC1 = 1;

    TRISDbits.RD0 = 0;
    TRISDbits.RD1 = 0;
    TRISDbits.RD2 = 0;
    TRISDbits.RD3 = 0;

    RBPU = 1;

    HANDLE print_handle = CreateThread(NULL, 0, thread_print, NULL, 0, NULL);
    HANDLE press_handle = CreateThread(NULL, 0, simulate_random_button_press, NULL, 0, NULL);

    uint8_t count = 0;
    while (1) {
		printf("Count: %d\n", count);
        check_SW_10(PORTCbits.RC0, &count);
        check_SW_11(PORTCbits.RC1, &count);
        print_LED(count);
    }
}