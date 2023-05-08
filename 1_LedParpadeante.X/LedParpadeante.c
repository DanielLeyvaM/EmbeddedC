/* 
 * File:   LedParpadeante.c
 * Author: Daniel Leyva
 *
 * Created on 18 de enero de 2021, 07:08 PM
 */

//CABECERAS
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f887.h>

//DEFINICIONES
#define _XTAL_FREQ 20000000 //20MHz

//FUNCIONES

//PRINCIPAL

int main() {
    //Config. Puertos
    TRISBbits.TRISB0= 0;    //Puerto B pin B0-> 0=Salida
    TRISBbits.TRISB1= 0;

    //Bucle principal
    while (1)
    {
        PORTBbits.RB0=1;	//Encender LED RB0
        __delay_ms(200);
        PORTBbits.RB1=1;
        __delay_ms(200);

        PORTBbits.RB0=0;    //Apagar LED RB0
        __delay_ms(200);
        PORTBbits.RB1=0;
        __delay_ms(200);

    }
    return 0;
}

