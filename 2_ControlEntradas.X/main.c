/* 
 * File:   main.c
 * Author: Daniel Leyva
 *
 * Created on 24 de enero de 2021, 07:00 PM
 */

//CABECERAS
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f887.h>

//DEFINICIONES
#define _XTAL_FREQ 20000000

int main(int argc, char** argv) {
    //Config puertos
    TRISBbits.TRISB0=1;     //1=Entrada
    ANSELHbits.ANS12=0;     //Cambiar estado de Pin a Digital ANSEL {0-7}, ANSELH {8-13}
    
    TRISBbits.TRISB1=0;     //0=Salida
    
    //Bucle principal
    while(1){
        //PORTB modificar y leer valores
        if(PORTBbits.RB0==1){   //Leer estado de entrada
            PORTBbits.RB1=1;    //Modificar salida
            __delay_ms(200);
            PORTBbits.RB1=0;
            __delay_ms(200);
        }
        else{
            PORTBbits.RB1=0;
        }
    }
    return (EXIT_SUCCESS);
}

