#ifndef PIC18F4550_SIM_H
#define PIC18F4550_SIM_H

#include <stdint.h>
#include <time.h>

struct PORTD_t {
    volatile uint8_t RD0 : 1;
    volatile uint8_t RD1 : 1;
    volatile uint8_t RD2 : 1;
    volatile uint8_t RD3 : 1;
    volatile uint8_t RD4 : 1;
    volatile uint8_t RD5 : 1;
    volatile uint8_t RD6 : 1;
    volatile uint8_t RD7 : 1;
};

struct PORTC_t {
    volatile uint8_t RC0 : 1;
    volatile uint8_t RC1 : 1;
    volatile uint8_t RC2 : 1;
    volatile uint8_t RC3 : 1;
    volatile uint8_t RC4 : 1;
    volatile uint8_t RC5 : 1;
    volatile uint8_t RC6 : 1;
    volatile uint8_t RC7 : 1;
};

extern volatile struct PORTD_t PORTDbits;
extern volatile struct PORTC_t PORTCbits;

struct TRISD_t {
    volatile uint8_t RD0 : 1;
    volatile uint8_t RD1 : 1;
    volatile uint8_t RD2 : 1;
    volatile uint8_t RD3 : 1;
    volatile uint8_t RD4 : 1;
    volatile uint8_t RD5 : 1;
    volatile uint8_t RD6 : 1;
    volatile uint8_t RD7 : 1;
};
extern volatile struct TRISD_t TRISDbits;

struct TRISC_t {
    volatile uint8_t RC0 : 1;
    volatile uint8_t RC1 : 1;
    volatile uint8_t RC2 : 1;
    volatile uint8_t RC3 : 1;
    volatile uint8_t RC4 : 1;
    volatile uint8_t RC5 : 1;
    volatile uint8_t RC6 : 1;
    volatile uint8_t RC7 : 1;
};
extern volatile struct TRISC_t TRISCbits;

extern volatile uint8_t RBPU;


#endif // PIC18F4550_SIM_H