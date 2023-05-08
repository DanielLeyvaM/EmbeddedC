/*
 * File:   Display.c
 * Author: Daniel Leyva
 *
 * Created on 8 de febrero de 2021, 06:35 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic16f887.h>
#include <xc.h>

#define _XTAL_FREQ 20000000

unsigned char display[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
                         0x7F,0x67,0x77,0x7C,0x39,0x5E,0x79,0x71};
                                            
int main ()
{
    //TRISX=0b76543210      //Forma Binaria (num Pines)
    //TRISX=0x00;           //Forma Hexadecimal
    TRISB=0x00;             //Declarar todo el puerto B como salida

    while (1)
    {
        for(int i=0;i<16;i++){
            PORTB=display[i];
            __delay_ms(100);
       }
    }
    return (EXIT_SUCCESS);
}