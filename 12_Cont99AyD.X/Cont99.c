/* 
 * File:   Cont99.c
 * Author: Daniel Leyva
 *
 
 * Created on 25 de febrero de 2021, 06:55 PM
 */


#include <stdio.h>
#include <stdlib.h>
#include <pic16f887.h>
#include <xc.h>

#define _XTAL_FREQ 20000000
#pragma config WDTE=OFF			//Desactivar watchdog

unsigned char display[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
int number=0;

int main()
{
    TRISAbits.TRISA0=1;     //Entrada control direccion
    ANSELbits.ANS0=0;
    TRISB=0b00000000;       //Salida display unidades
    TRISD=0b00000000;       //Salida display decenas
    
    while(1)
    {
        int i=number/10;            //Decenas
        int j=number%10;            //Unidades

        if(PORTAbits.RA0==0){       //Ascendente
            if(number==100){
                number=0;
                i=0;
            }
            PORTD=display[i];
            PORTB=display[j];
            __delay_ms(100);
            number++;
        }

        else if(PORTAbits.RA0==1){      //Descendente
            if(number==0){
                number=100;
            }
            PORTD=display[i];
            PORTB=display[j];
            __delay_ms(100);
            number--;
        }

    }
}
