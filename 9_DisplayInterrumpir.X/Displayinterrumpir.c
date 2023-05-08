/*
 * File:   Displayinterrupcion.c
 * Author: Daniel Leyva
 * 
 
 * Created on 11 de febrero de 2021, 11:08 PM
 */


#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f887.h>

#define _XTAL_FREQ 20000000

void __interrupt interrumpir (void)
{
    if(INTCONbits.INTF)
    {
        while(1){
            PORTBbits.RB1=1;
            __delay_ms (100);
            PORTBbits.RB1=0;
            __delay_ms (100);
        }
    }
    INTCONbits.INTF=0;
}


int main ()
{
    
    TRISC=0b00000000;
    TRISBbits.TRISB0=1;         //entrada
    TRISBbits.TRISB1=0;         //salida
    ANSELHbits.ANS12=0;         //Deshabilitar Analogico
    //ANSEL=0b00000000;         //Deshabilita entradas analógicas de la 0 a la 7
    
    OPTION_REGbits.INTEDG=1;    //interrupcion flanco de subida
    INTCONbits.GIE=1;           //interrupcion global
    INTCONbits.INTE=1;          //interrupcion ecterna por PIN
    INTCONbits.INTF=0;          //resetear bandera externa de interrupcion
	
    while (1)
    {
     //PORTX=0b.gfedcba
       PORTC=0b00111111;    //0
       __delay_ms(100);
       PORTC=0b00000110;    //1
       __delay_ms(100);
       PORTC=0b01011011;    //2
       __delay_ms(100);
       PORTC=0b01001111;    //3
       __delay_ms(100);
       PORTC=0b01100110;    //4
       __delay_ms(100);
       PORTC=0b01101101;    //5
       __delay_ms(100);
       PORTC=0b01111101;    //6
       __delay_ms(100);
       PORTC=0b00000111;    //7
       __delay_ms(100);
       PORTC=0b01111111;    //8
       __delay_ms(100);
       PORTC=0b01100111;    //9
       __delay_ms(100);
       PORTC=0b01110111;    //A
       __delay_ms(100);
       PORTC=0b01111100;    //B
       __delay_ms(100);
       PORTC=0b00111001;    //C
       __delay_ms(100);
       PORTC=0b01011110;    //D
       __delay_ms(100);
       PORTC=0b01111001;    //E
       __delay_ms(100);
       PORTC=0b01110001;    //F
       __delay_ms(100);
    }
    
    return (EXIT_SUCCESS);
}

