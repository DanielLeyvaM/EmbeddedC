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

#define _XTAL_FREQ 20000000

//Hablitar osc interno y deshabilitar configuraciones
//                         WatchDog Timer(Contador para reinico automatico)
//                                   PowerTimer(Cuenta el tiempo desde primer ejecucion)
//                                              MasterClear(reset PIN MCLR)
//                                                        Code Protection (Seguridad que evita copias de codigo/vulnerabilidades)
//                                                                         Detecta si el PIC se inhabilita o traba
//                                                                                    Switch entre los modos de conteo del PIC
//                                                                                              FailSafeClockMonitor(monitorea ejecucion)
#pragma config FOSC=0b100, WDTE=0FF, PWRTE=OFF, MCLRE=ON, CP=OFF, CPD=OFF, BOREN=OFF, IESO=OFF, FCMEN=OFF


int main() {
    //config. puertos
    TRISB=0x00;

    //config. TIMER
    OPTION_REGbits.T0CS=0;         //Usar osc interno
    OPTION_REGbits.PSA=0;          //Asignar preescaler al contador timer0
    OPTION_REGbits.PS=0b111;       //pre-escalado a 1:256

    //TMR0 = 8bits - (frec_osc  / (4 * preescaler * frec_deseada))  100Hz-> 10ms
    //TMR0 = 255 -  (20,000,000 / (4 *   256      *      100    ))  -> TMR0=59

    while(1){
        INTCONbits.T0IF=0;          //Limpiar bandera de interrupcion
        TMR0=59;                    //Reiniciar contador
        INTCONbits.T0IE=1;          //Habilitar bandera de interrupcion

        while(INTCONbits.T0IF==0){
            PORTBbits.RB0=0;
        }
        PORTBbits.RB0=1;            //Parpadeo al completarse conteo
    }
    
    return (EXIT_SUCCESS);
}

