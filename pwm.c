/*
 * File:   pwm.c
 * Author: victor
 *
 * Created on June 3, 2020, 4:35 PM
 */


#include <xc.h>
#include "main.h"

void init_PWM(void){
    /*
     * STEPS FOR PWM Oop
     * Configure PWM pins P1A and P1B as inputs TRISC and D
     * Set PWM period by loading PR2 register
     * Configure ECCP for the desired PWM Mode and configuration by loading the CCP1CON register with
     * appropriate values
     *  -> Select one of available output configurations and direction with the P1M1:P1M0 bits
     *  -> Select the polarities of the PWM output signals with CCP1M3:CCP1M0 bitss
     * Set PWM duty cycle by loading the CCPR1L register and CCP1CON<5:4> 
     *For HALF_BRIDGE MODE set the dead band delay by loading the PWM1CON<6:0> with appropriate value
     * If auto shut down is required load the ECCPAS register
     * IF Auto-Restart operation is required set the PRSEN bit in PWM1CON<7>
     * Configure and Start TMR2
     *  ->Clear TMR2 interrupt Flag
     *  ->Set TMR2 Prescaler
     *  -> Enable TMR2ON
     * 
     * Enable PWM outputs after new PWM cycle has started
     *  -> Wait until TMR2 overfloes (TMr2IF is set)
     *  -> Enable P1A, p1B,P1C and or P1D pins as output by clearing their TRIS bits
     *  -> Clear the ECCPASE bit
     */
    
    TRISCbits.RC2 = 1;
    TRISDbits.RD5 = 1;
    TRISBbits.RB3 = 1;
    TRISCbits.RC1 = 1;
    TRISDbits.RD6 = 1;
    TRISDbits.RD7 = 1;
    PR2 = 19;
    CCP1CON = 0x8F;
    CCPR1L = 9;
    PWM1CON = 0x85;
    T2CON = 0x04;
    
    while(!TMR2IF);
    ECCPASE = 0x00;
    TRISCbits.RC2 = 0;
    TRISDbits.RD5 = 0;
    TRISBbits.RB3 = 0;
    TRISCbits.RC1 = 0;
    TRISDbits.RD6 = 0;
    TRISDbits.RD7 = 0;
    
    
}