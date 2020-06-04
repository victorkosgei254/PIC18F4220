/*
 * File:   interr.c
 * Author: victor
 *
 * Created on June 3, 2020, 3:49 PM
 */


#include <xc.h>
#include "main.h"

void __interrupt(high_priority) high_ISR(void){
    
    INTCONbits.GIEH = 0;
    
    if(INTCONbits.INT0IF){
        INTCONbits.INT0IF = 0;
    }
    INTCONbits.GIEH = 1;
}

void __interrupt(low_priority) low_ISR(void){
    INTCONbits.GIEL = 0;
    if(INTCONbits.RBIF){
        if(LATBbits.LATB1){
            //INT 1 handles
        }else if(LATBbits.LATB1){
            //INT 2 handles
        }
        INTCONbits.RBIF = 0;
    }
    INTCONbits.GIEL = 1;
}
void init_Interrupts(void){
    //to be set
    RCON = 0x80;
    INTCON = 0xD8;
    INTCON2 = 0xF0;
    
    //Setting INTO, INT1 and INT2 as INPuts
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    TRISBbits.RB2 = 1;
    
}