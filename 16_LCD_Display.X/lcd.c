/*
 * File:   lcd.c
 * Author: LEYVA
 *
 * Created on 15 de marzo de 2021, 12:36 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f887.h>

#define _XTAL_FREQ 20000000
#pragma config WDTE=0FF

#define RS PORTDbits.RD0
#define RW PORTDbits.RD1
#define EN PORTDbits.RD2

//DATA LCD DISPLAY
void lcd_data(unsigned char data){
    PORTB=data;
    RS=1;               //1= Envio Datos
    RW=0;               //0= Write
    EN=1;               //Enable
    __delay_ms(50);
    EN=0;
}

void lcd_string(const unsigned char str[],unsigned char num){
    for(int i=0;i<num;i++){
        lcd_data(str[i]);
    }
}

//COMMAND LCD DISPLAY
void lcd_command(unsigned char cmd){
    PORTB=cmd;
    RS=0;               //0= Modo comando
    RW=0;               //0= Write
    EN=1;               //Enable
    __delay_ms(50);
    EN=0;
}

//LCD INITIALIZATION
void lcd_init(){
    lcd_command(0x38);      //LCD 2x16 8bits
    lcd_command(0x06);      //Increment next element
    lcd_command(0x0C);      //LCD cursor on
    lcd_command(0x01);      //Clear screen 0x01
}


int main() {
    //Config puertos
    TRISDbits.TRISD0=0;
    TRISDbits.TRISD1=0;
    TRISDbits.TRISD2=0;
    
    TRISB=0x00;             //Salidas

    //Config LCD
    lcd_init();

    while(1){
       lcd_command(0x80);               //Fila 0, columna 0
       lcd_string("Embebidos:",10);     //Texto,num caracteres
       lcd_command(0xC0);               //Fila 1, columna 0
       lcd_string("Daniel Leyva",13);   //Texto,num caracteres
    }
    
    return (EXIT_SUCCESS);
}



