/* 
 * File:   interrupciones.c
 * Author: LEYVA
 *
 * Created on 11 de febrero de 2021, 10:05 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f887.h>

#define _XTAL_FREQ 20000000
#define BOTON PORTBbits.RB0     //PIN RB0 (INT=Interrupcion)
#define LED1 PORTBbits.RB1
#define LED2 PORTBbits.RB2

//FUNCIONES
void __interrupt interrupcion(void){
    if(INTCONbits.INTF){
        for(int i=0;i<5;i++){
           LED1=0;
           __delay_ms(200);
           LED1=1;
           __delay_ms(200);
        }
        INTCONbits.INTF=0;
        __delay_ms(200);        //Delay recomendable
    }
}


int main() {
    //Config. Puertos
    TRISB=0b00000001;           //RB0-> Entrada
    ANSELHbits.ANS12=0;         //Cambiar estado PIN a Digital

    //Config. PIC
    OPTION_REGbits.INTEDG=1;    //Interrupcion flanco subida
    //INTerrupcionCONtrol
    INTCONbits.GIE=1;           //Habilitar interrupcion global
    INTCONbits.INTE=1;          //Interrupcion externa por PIN
    INTCONbits.INTF=0;          //Resetear bandera de interrupcion

    while(1){
        LED2=1;
        __delay_ms(200);
        LED2=0;
        __delay_ms(200);
    }
    
    return (EXIT_SUCCESS);
}

