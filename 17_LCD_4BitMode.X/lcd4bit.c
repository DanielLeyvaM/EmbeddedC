 /*
 * File:   lcd4bit.c
 * Author: LEYVA
 *
 * Created on 17 de marzo de 2021, 02:36 PM
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
    PORTB=(data&0xF0);  //EJ:10101100 AND 11110000-> Se seleccionan los primeros 4 bits de DATA(1010)
    RS=1;               //1= Envio Datos
    RW=0;               //0= Write
    EN=1;               //Enable
    __delay_ms(50);
    EN=0;
    PORTB=(data<<4)&0xF0;   //Recorrimiento de DATA:11001010-> AND 11110000-> Se seleccionan los 4 primeros bits(1100)
    RS=1;                   //1= Envio Datos
    RW=0;                   //0= Write
    EN=1;                   //Enable
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
    PORTB=(cmd&0xF0);
    RS=0;               //0= Command Mode
    RW=0;               //0= Write
    EN=1;               //Enable
    __delay_ms(50);
    EN=0;
    PORTB=(cmd<<4)&0xF0;
    RS=0;                   //0= Command Mode
    RW=0;                   //0= Write
    EN=1;                   //Enable
    __delay_ms(50);
    EN=0;
}

//LCD INITIALIZATION
void lcd_init(){
    lcd_command(0x02);      //Return home
    lcd_command(0x28);      //LCD 2x16-> 4bit mode
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
