/* 
 * File:   pwm.c
 * Author: LEYVA
 *
 * Created on 05 de marzo de 2021, 10:36 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f887.h>

#define _XTAL_FREQ 8000000

int main() {
    //Config puertos
    TRISBbits.TRISB0=1;         //Entrada control DC+
    TRISBbits.TRISB4=1;         //Entrada control DC-
    ANSELHbits.ANS12=0;         //Desactivar analogico
    ANSELHbits.ANS11=0;

    //Config PWM
    TRISCbits.TRISC2 = 0;               //PIN RC2 como salida -> PIN PWM
    CCP1CONbits.CCP1M = 0b1100;         // Seleccionar modo PWM
    
    //TMR2 = 8bits - (frec_osc  / (4 * preescaler * frec_deseada))
    //TMR2 = 255 -   (8,000,000 / (4 *   16       *      1000   )) = 130->redondeo a 128 mitad de 256
    PR2 = 128;                          // Valor para el registro de periodo del TMR2
    T2CONbits.T2CKPS = 0b10;            // Preescaler de 1:16
    T2CONbits.TMR2ON = 1;               // Encender Timer2
    CCPR1L=64;                          // Valor para el registro de ciclo de trabajo (50% -> mitad de PR2)
    
    while(1){
        if(PORTBbits.RB0==0 && PORTBbits.RB4==0){
            CCPR1L = CCPR1L;      
        }
        else if(PORTBbits.RB0==1){
            CCPR1L=CCPR1L+13;           //128/10-> 12.8->13 (dividir ciclo en 10 partes)
            __delay_ms(200);
        }
        else if(PORTBbits.RB4==1){
            CCPR1L=CCPR1L-13;
            __delay_ms(200);
        }
        
        __delay_ms(100);                
    }

    return (EXIT_SUCCESS);
}

