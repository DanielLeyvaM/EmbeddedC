/*
 * File:   timers.c
 * Author: LEYVA
 *
 * Created on 27 de febrero de 2021, 04:10 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f887.h>

#define _XTAL_FREQ 20000000

int main() {
    int valor;                  //Variable para guardar valor de ADC
    //config puertos
    TRISAbits.TRISA0=1;         //Entrada
    TRISB=0b00000000;

    //config ADC
    ADCON1bits.ADFM=1;  	//Forzar Justificacion a la derecha (lsb=der)
    ADCON1bits.VCFG1=0;  	//Voltaje referencia negativo 0=VSS
    ADCON1bits.VCFG0=0; 	//Voltaje referencia positivo 0=VDD

    ADCON0bits.ADCS=0b001;	//Analog digital converter (default 1=2us)
    ADCON0bits.CHS=0b000;	//Chanel selector 000=PIN0 /111=PIN7
    ADCON0bits.ADON=1;		//Encender ADC

    while(1){
        __delay_us(5);              //delay recomendado
        ADCON0bits.GO=1;            //Iniciar conversion
        while(ADCON0bits.GO==1){    //Esperar a que termine
            //nothing
        }
        valor=(ADRESH<<8)+ADRESL;	//Combinar 10 bits del ADC

	if(valor<205){                  //1024/5V-> 204.8
		PORTB=0b00000001;
	}
        else if(valor<410){		
		PORTB=0b00000011;
	}
        else if(valor<615){		
		PORTB=0b00000111;
	}
        else if(valor<820){		
		PORTB=0b00001111;
	}
        else{
            PORTB=0b00011111;
        }
    }

    return (EXIT_SUCCESS);
}

