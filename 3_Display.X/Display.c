/* 
 * File:   Display.c
 * Author: Daniel Leyva
 *
 * Created on 8 de febrero de 2021, 06:35 PM
 */

#include <stdio.h>
#include <xc.h>
#include <stdlib.h>
#include <pic16f887.h>

#define _XTAL_FREQ 20000000

void main ()
{
  //TRISX=0b76543210        //Forma Binaria (num Pines)
  //TRISX=0x00;             //Forma Hexadecimal
    TRISB=0b00000000;       //Declarar todo el puerto B como salida

    /*
    while (1)
    {
     //PORTX=0b76543210
       PORTB=0b00000000;
       __delay_ms(100);

       PORTB=0b00000001;
       __delay_ms(100);
       PORTB=0b00000011;
       __delay_ms(100);
       PORTB=0b00000111;
       __delay_ms(100);
       PORTB=0b00001111;
       __delay_ms(100);
       PORTB=0b00011111;
       __delay_ms(100);
       PORTB=0b00111111;
       __delay_ms(100);
       PORTB=0b01111111;
       __delay_ms(100);
       PORTB=0b11111111;
       __delay_ms(100);
    }
*/

     while (1)
    {
     //PORTX=0b.gfedcba
       PORTB=0b00111111;    //0
       __delay_ms(100);
       PORTB=0b00000110;    //1
       __delay_ms(100);
       PORTB=0b01011011;    //2
       __delay_ms(100);
       PORTB=0b01001111;    //3
       __delay_ms(100);
       PORTB=0b01100110;    //4
       __delay_ms(100);
       PORTB=0b01101101;    //5
       __delay_ms(100);
       PORTB=0b01111101;    //6
       __delay_ms(100);
       PORTB=0b00000111;    //7
       __delay_ms(100);
       PORTB=0b01111111;    //8
       __delay_ms(100);
       PORTB=0b01100111;    //9
       __delay_ms(100);
       PORTB=0b01110111;    //A
       __delay_ms(100);
       PORTB=0b01111100;    //B
       __delay_ms(100);
       PORTB=0b00111001;    //C
       __delay_ms(100);
       PORTB=0b01011110;    //D
       __delay_ms(100);
       PORTB=0b01111001;    //E
       __delay_ms(100);
       PORTB=0b01110001;    //F
       __delay_ms(100);
    
    }
}


