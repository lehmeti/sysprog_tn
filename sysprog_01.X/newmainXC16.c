/*
 * File:   newmainXC16.c
 * Author: Niklas, Tim
 *
 * Created on 15. Oktober 2019, 15:25
 */


#include "xc.h"
#include <time.h>
#include <stdio.h>

#define FCY 16000000UL
#include <libpic30.h>

#ifdef _WIN32
    #include <windows.h>
#endif


void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}

void myDelay (int seconds) {
    int counter = 0;
    while(counter < seconds)
        ;
}




int main(void) {
    // 0x00 => output
    // 0xFF => input
    TRISA = 0x00;
    TRISB = 0x00; 
    TRISC = 0x00;
    TRISAbits.TRISA12 = 1;
    TRISAbits.TRISA11 = 1;

    PORTAbits.RA0 = 0;
    PORTAbits.RA1 = 0;
    PORTCbits.RC7 = 0;
    
    while(1)
    {
              
        
        while(PORTAbits.RA12 == 0) {
            // S2 is set
            
            if(PORTAbits.RA11 == 0) {
                // S1 is set
                // light BLUE constantly, clear all other lights
                PORTAbits.RA1 = 0;
                PORTAbits.RA0 = 0;
                PORTCbits.RC7 = 1;
            
            } else {
                // if S1 is not set, clear BLUE
                PORTCbits.RC7 = 0;
            }
            
            
            // blink RED and GREEN in interval
            PORTAbits.RA0 = 1;
            __delay_ms(10);
            PORTAbits.RA0 = 0;
            __delay_ms(10);
            
            
        }
        
        // configure potentiometer?
        
   
        
    } 
    return 0;
}
