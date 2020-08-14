/*
 * File:   main.c
 * Author: georg
 *
 * Created on August 8, 2020, 9:48 PM
 */

#include <xc.h>
#include "bit_settings.h"
#include "config.h"
#include "oled.h"

void main(void) 
{
    IO_First_Init();
    Configure_Clock();
    
    
    TRISCbits.TRISC3=1;//i2c
    TRISCbits.TRISC4=1;//i2c
    
    OLED_Init(0x3C);
    OLED_clear();
    OLED_string("Hello World!", 0, 0);
    OLED_write();
    
    while(1){
        LATCbits.LATC7 = 0;
        __delay_us(1);
        LATCbits.LATC7 = 1;
        __delay_us(1);
    }
    
    
    
}
