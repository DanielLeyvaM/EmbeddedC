/* 
 * File:   Compuertas.c
 * Author: Daniel Leyva
 *
 * Created on 8 de febrero de 2021, 06:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f887.h>

//DEFINICIONES
#define _XTAL_FREQ 20000000

#define A PORTBbits.RB1
#define B PORTBbits.RB2
#define X PORTBbits.RB0

int main() {

    TRISBbits.TRISB1=1;     //entrada 1
    TRISBbits.TRISB2=1;     //entrada 2
    TRISBbits.TRISB0=0;     //salida
	
    ANSELHbits.ANS10=0;     //desactivar el ADC
    ANSELHbits.ANS8=0;      //desactivar el ADC

    while(1){
        //DESCRIPCION FUNCIONAL
        /*
        //PORTBbits.RB0 =  PORTBbits.RB1 & PORTBbits.RB2;       //AND
        //PORTBbits.RB0 =  PORTBbits.RB1 | PORTBbits.RB2;       //OR
        PORTBbits.RB0 =  PORTBbits.RB1 ^ PORTBbits.RB2;         //XOR
        */

        //SINTAXIS SIMLIFICADA
        X= A&B;
    }
    
    return(EXIT_SUCCESS);
}

