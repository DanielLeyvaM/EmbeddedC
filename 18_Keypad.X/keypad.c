/*
 * File:   keypad.c
 * Author: LEYVA
 *
 * Created on 22 de marzo de 2021, 04:36 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f887.h>

#define _XTAL_FREQ 20000000
#pragma config WDTE=0FF

#define RS PORTCbits.RC0
#define RW PORTCbits.RC1
#define EN PORTCbits.RC2

//KEYPAD difinitions
#define UNO PORTDbits.RD0
#define DOS PORTDbits.RD1
#define TRES PORTDbits.RD2

#define A PORTDbits.RD4
#define B PORTDbits.RD5
#define C PORTDbits.RD6
#define D PORTDbits.RD7

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
    lcd_command(0x38);      //LCD 2x16
    lcd_command(0x06);      //Increment next element
    lcd_command(0x0C);      //LCD cursor on
    lcd_command(0x01);      //Clear screen 0x01
}

//KEYPAD
void keypad(){
    UNO=1; DOS=0; TRES=0;
        if(A==1){
            lcd_data('1');
            while(A==1);    //Antirebote
        }
        else if(B==1){
            lcd_data('4');
            while(B==1);    //Antirebote
        }
        else if(C==1){
            lcd_data('7');
            while(C==1);    //Antirebote
        }
        else if(D==1){
            lcd_data('*');
            while(D==1);    //Antirebote
        }

    UNO=0; DOS=1; TRES=0;
        if(A==1){
            lcd_data('2');
            while(A==1);    //Antirebote
        }
        else if(B==1){
            lcd_data('5');
            while(B==1);    //Antirebote
        }
        else if(C==1){
            lcd_data('8');
            while(C==1);    //Antirebote
        }
        else if(D==1){
            lcd_data('0');
            while(D==1);    //Antirebote
        }
    
    UNO=0; DOS=0; TRES=1;
        if(A==1){
            lcd_data('3');
            while(A==1);    //Antirebote
        }
        else if(B==1){
            lcd_data('6');
            while(B==1);    //Antirebote
        }
        else if(C==1){
            lcd_data('9');
            while(C==1);    //Antirebote
        }
        else if(D==1){
            lcd_data('#');
            while(D==1);    //Antirebote
        }
}

int main() {
    //Config puertos
    TRISCbits.TRISC0=0;
    TRISCbits.TRISC1=0;
    TRISCbits.TRISC2=0;

    TRISB=0x00;             //Salidas
    TRISD=0xF0;             //Keypad

    //Config LCD
    lcd_init();
    lcd_command(0x80);               //Fila 0, columna 0
    lcd_string("KEYPAD:",7);        //Texto,num caracteres
    lcd_command(0xC0);

    while(1){
        keypad();
    }

    return (EXIT_SUCCESS);
}
