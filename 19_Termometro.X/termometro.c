/*
 * File:   timers.c
 * Author: LEYVA
 *
 * Created on 30 de marzo de 2021, 04:36 PM
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

void lcd_data(unsigned char data);
void lcd_string(const unsigned char str[],unsigned char num);
void lcd_command(unsigned char cmd);
void lcd_init();


int main() {
    //Config puertos
    TRISAbits.TRISA0=1;     //Entrada LM35
    
    TRISDbits.TRISD0=0;
    TRISDbits.TRISD1=0;
    TRISDbits.TRISD2=0;
    TRISB=0x00;             //Salidas

    //Config ADC
    int valor,aux;
    float temp;
    ADCON1bits.ADFM=1;  	//Forzar Justificacion a la derecha (lsb=der)
    ADCON1bits.VCFG1=0;  	//Voltaje referencia negativo 0=VSS
    ADCON1bits.VCFG0=0; 	//Voltaje referencia positivo 0=VDD

    ADCON0bits.ADCS=0b001;	//Analog digital converter (default 1=2us)
    ADCON0bits.CHS=0b000;	//Chanel selector 000=PIN0 /111=PIN7
    ADCON0bits.ADON=1;		//Encender ADC
   
    //Config LCD
    lcd_init();
    lcd_command(0x80);               //Fila 0, columna 0
    lcd_string("TEMPERATURA:",12);   //Texto,num caracteres
    
    while(1){
        ADCON0bits.GO=1;            //Iniciar conversion
        while(ADCON0bits.GO==1){
            //Nothing
        }
	valor=(ADRESH<<8)+ADRESL;       //Guardar valor ADC
        //SENSOR LM35-> Escala 10mV ->0.01
        //Se divide el valor de VDD entre la resolucion(10bits)-> 5V/1024
        temp = (valor*((5.0/1024.0)/0.01));

        lcd_command(0xC0);              //Fila 1, columna 0

        aux=(int)temp/100;              //155/100-> 1
        lcd_data((aux%10)+'0');         //1%10-> 1 digito1
        aux=(int)temp/10;               //145/10-> 14
        lcd_data((aux%10)+'0');         //1%10-> 4 digito2
        aux=(int)temp;                  //155
        lcd_data((aux%10)+'0');         //155%10-> 5 digito3
        lcd_data(' ');
        lcd_data('C');                  //Centigrados
    }

    return (EXIT_SUCCESS);
}


//DATA LCD DISPLAY
void lcd_data(unsigned char data){
    PORTB=data;
    RS=1;               //1= Envio Datos
    RW=0;               //0= Write
    EN=1;               //Enable
    __delay_ms(5);
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
    __delay_ms(5);
    EN=0;
}

//LCD INITIALIZATION
void lcd_init(){
    lcd_command(0x38);      //LCD 2x16 8bits
    lcd_command(0x06);      //Increment next element
    lcd_command(0x0C);      //LCD cursor on
    lcd_command(0x01);      //Clear screen 0x01
}