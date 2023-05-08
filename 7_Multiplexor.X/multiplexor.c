/* 
 * File:   multiplexor.c
 * Author: LEYVA
 *
 * Created on 8 de febrero de 2021, 06:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f887.h>

#define _XTAL_FREQ 20000000
#define S PORTBbits.RB0
#define A PORTBbits.RB1
#define B PORTBbits.RB2
#define X PORTBbits.RB3

int main() {
    TRISB=0b00000111;
    ANSELH=0b000000;    //ANS12,ANS10,ANS8
    
    //DESCRIPCION FUNCIONAL ~SA+SB
    //X=((~S)&A)|(S&B);
        
    //DESCRIPCION COMPORTAMENTAL
    if(S==0){
        X=A;
    }
    else{
        X=B;;
    }

    return (EXIT_SUCCESS);
}

