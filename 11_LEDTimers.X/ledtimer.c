/*
 * File:   timers.c
 * Author: LEYVA
 *
 * Created on 20 de febrero de 2021, 04:10 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f887.h>

//#define _XTAL_FREQ 20000000
char valor=0;

void __interrupt contador(){
    if(TMR0IF==1){
        valor=~valor;
        TMR0=201;
        TMR0IF=0;       //Bajar bandera de interrupcion T0
    }
}

int main() {
    //Config puertos
    TRISBbits.TRISB0=0;

    //Config Timers
    OPTION_REGbits.T0CS=0;          //Usar reloj instrucciones interno
    OPTION_REGbits.PSA=0;           //Asignar pre-escalador a T0
    OPTION_REGbits.PS=0b111;        //Preescalar a 1:256 -> 80us

    //Config Interrupciones
    TMR0=200;                      //Registro 8 bits(0-255) 16ms
    INTCONbits.GIE=1;              //Habilitar interrupcion global
    INTCONbits.PEIE=1;             //Habilitar interrupcion por perifericos
    INTCONbits.TMR0IE=1;           //Habilitar interrupcion por desbordamiento

    while(1){
        PORTBbits.RB0=valor;
    }

    return (EXIT_SUCCESS);
}

