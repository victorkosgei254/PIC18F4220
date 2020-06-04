/*
 * File:   Main.c
 * Author: victor
 *
 * Created on June 3, 2020, 2:51 PM
 */


#include <xc.h>
#include "main.h"
void main(void)
{
     OSCCON = 0x76;
    init_LCD();
    put_String("Welcome to ::");
    init_PWM();
    while(1){
        
    }
   
    return;
}
