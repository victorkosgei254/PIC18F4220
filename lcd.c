/*
 * File:   lcd.c
 * Author: victor
 *
 * Created on June 3, 2020, 2:54 PM
 */


#include <xc.h>
#include "main.h"

//LCD PINS
#define PIN_7 PORTDbits.RD0
#define PIN_6 PORTDbits.RD1
#define PIN_5 PORTDbits.RD2
#define PIN_4 PORTDbits.RD3
#define PIN_3 PORTDbits.RD4
#define PIN_2 PORTCbits.RC3
#define PIN_1 PORTCbits.RC4
#define PIN_0 PORTCbits.RC5

#define RS_PIN PORTBbits.RB7
#define RW_PIN PORTBbits.RB6
#define E_PIN PORTBbits.RB5

void clock_LCD(void){
    E_PIN = 0;
     __delay_ms(1);
    E_PIN = 1;
    __delay_ms(1);
    E_PIN = 0;
}
void send_Command(char command){
    RW_PIN = 0;
    RS_PIN = 0;
    PIN_7 = (command & 0x08)>>3;
    PIN_6 = (command & 0x04)>>2;
    PIN_5 = (command & 0x02)>>1;
    PIN_4 = (command & 0x01)>>0;
    PIN_3 = (command & 0x10)>>4;
    PIN_2 = (command & 0x20)>>5;
    PIN_1 = (command & 0x40)>>6;
    PIN_0 = (command & 0x80)>>7;
    clock_LCD();
    
}

void put_Char(char x){
    RS_PIN = 1;
    RW_PIN = 0;
        RW_PIN = 0;
    RS_PIN = 0;
    PIN_7 = (x & 0x08)>>3;
    PIN_6 = (x & 0x04)>>2;
    PIN_5 = (x & 0x02)>>1;
    PIN_4 = (x & 0x01)>>0;
    PIN_3 = (x & 0x10)>>4;
    PIN_2 = (x & 0x20)>>5;
    PIN_1 = (x & 0x40)>>6;
    PIN_0 = (x & 0x80)>>7;
    clock_LCD();
    clock_LCD();
}

void set_DDRAMAddr(uint8_t addr){
    RW_PIN = 0;
    RS_PIN = 0;
    PIN_7 = 1;
    PIN_6 = (uint8_t )((addr & 0x40)>>6);
    PIN_5 = (uint8_t )((addr & 0x20)>>5);
    PIN_4 = (uint8_t )((addr & 0x10)>>4);
    PIN_3 = (uint8_t )((addr & 0x08)>>3);
    PIN_2 = (uint8_t )((addr & 0x04)>>2);
    PIN_1 = (uint8_t )((addr & 0x02)>>1);
    PIN_0 = (uint8_t )((addr & 0x01)>>0);
    clock_LCD();
}
void put_String(char *msg){
    int count = 0;
    while(msg[count] != '\0'){
        put_Char(msg[count]);
        count++;
        
    }
}
void init_LCD(void){
    TRISD = 0x00; //setting as outputs
    TRISBbits.RB7 = 0;
    TRISBbits.RB6 = 0;
    TRISBbits.RB5 = 0;
    TRISC = 0x00;
    
    //setting the display options
    
    RS_PIN = 0;
    RW_PIN = 0;
    E_PIN = 0;
    
    __delay_ms(20);
    send_Command(0x30);
    __delay_ms(5);
    send_Command(0x30);
    __delay_ms(5);
    send_Command(0x30);
    __delay_ms(5);
    send_Command(0x3C);
    send_Command(0x08); //DISPLAY OFF
    send_Command(0x01); //DISPLAY ON
    send_Command(0x06); //ENTRY MODE SET
//    send_Command(0x80);
    clock_LCD();
}