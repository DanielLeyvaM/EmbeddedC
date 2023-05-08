/* 
 * File:   Display16seg.c
 * Author: Daniel Leyva
 *
 * Created on 12 de febrero de 2021, 06:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f887.h>

#define _XTAL_FREQ 20000000

void main ()
{
	//TRISX=0b76543210      //Forma Binaria
	//TRISX=0x00            //Forma Hexadecimal
    TRISB=0b00000000;       //Declarar todo el puerto B como salida
    TRISC=0b00000000;
  
     while (1)
    {
	//PORTX=0b|hgfedcba
    //PORTX=0b|ponmlkji
       PORTB=0b00000000;    //-
       PORTC=0b00011000;
       __delay_ms(100);
       PORTB=0b00111111;    //D
       PORTC=0b01000010;
       __delay_ms(100);
       PORTB=0b11001111;    //A
       PORTC=0b00011000;
       __delay_ms(100);
       PORTB=0b11001100;    //N
       PORTC=0b10000001;
       __delay_ms(100);
       PORTB=0b00110011;    //I
       PORTC=0b01000010;
       __delay_ms(100);
       PORTB=0b11110011;    //E
       PORTC=0b00001000;
       __delay_ms(100);
       PORTB=0b11110000;    //L
       PORTC=0b00000000;
       __delay_ms(100);
       
       PORTB=0b00000000;    //-
       PORTC=0b00011000;   
       __delay_ms(100);
       
       PORTB=0b11110000;    //L
       PORTC=0b00000000;
       __delay_ms(100);
       PORTB=0b11110011;    //E
       PORTC=0b00001000;
       __delay_ms(100);
       PORTB=0b00000000;    //Y
       PORTC=0b01000101;
       __delay_ms(100);
       PORTB=0b11000000;    //V
       PORTC=0b00100100;
       __delay_ms(100);
       PORTB=0b11001111;    //A
       PORTC=0b00011000;
       __delay_ms(100);
       
      
    }
}



