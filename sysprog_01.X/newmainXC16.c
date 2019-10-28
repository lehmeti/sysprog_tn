/*
 * File:   newmainXC16.c
 * Author: Niklas
 *
 * Created on 15. Oktober 2019, 15:25
 */

#include <xc.h>
#define    FCY    16000000UL // Instruction cycle frequency, Hz - required for __delayXXX() to work
#include <libpic30.h>        // __delayXXX() functions macros defined here
#include "mcc_generated_files/mcc.h"


int main(void) {
        TRISA = 0x0;
        TRISB = 0x0;
        TRISC = 0x0;
    while (1)
    {
        // Add your application code
        
        adc_result_t dutyValue = ADCC_GetSingleConversion(pot); //load the potentiometer value in a 16 bit variable
                      
        if (dutyValue < 90) //if the potentiometer does not give 0 value
            dutyValue = 0; //set the value to 0 when it is below 90 to turn the LED off completely
        
        PWM6_LoadDutyValue(dutyValue); //lod the potentiometer value to the PWM duty cycle
        
                      
    }
    return 0;
}