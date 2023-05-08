/*
 * File:   timers.c
 * Author: LEYVA
 *
 * Created on 27 de febrero de 2021, 08:10 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f887.h>

#define _XTAL_FREQ 20000000
#define PARTE1      1024/5
#define PARTE2      (1024/5)*2
#define PARTE3      (1024/5)*3
#define PARTE4      (1024/5)*4
#define PARTE5      1024-1

unsigned char display[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};

int main() {
    int valor;                  //Variable para guardar valor de ADC
    int digito=0;
    
    //config puertos
    TRISAbits.TRISA0=1;         //Entrada
    TRISB=0b00000000;           //Salida fraccionaria
    TRISD=0b00000000;           //Salida unidades

    //config ADC
    ADCON1bits.ADFM=1;  	//Forzar Justificacion a la derecha (lsb=der)
    ADCON1bits.VCFG1=0;  	//Voltaje referencia negativo 0=VSS
    ADCON1bits.VCFG0=0; 	//Voltaje referencia positivo 0=VDD

    ADCON0bits.ADCS=0b001;	//Analog digital converter (default 1=2us)
    ADCON0bits.CHS=0b000;	//Chanel selector 000=PIN0 /111=PIN7
    ADCON0bits.ADON=1;		//Encender ADC

    while(1){
        __delay_us(5);                  //delay para sig lectura
        ADCON0bits.GO=1;                //Iniciar conversion
        while(ADCON0bits.GO==1){        //Esperar a que termine
            //nothing
        }
        valor=(ADRESH<<8)+ADRESL;	//Combinar 10 bits del ADC

        
        if(valor<PARTE1){           //0.0V -> 1.0V
            PORTD=display[0];
            digito=valor/20;        //.0V -> .9V
            PORTB=display[digito];
        }
        else if(valor<PARTE2){      //1.0V -> 2.0V
            PORTD=display[1];
            digito=(valor-PARTE1)/20;
            PORTB=display[digito];
        }
        else if(valor<PARTE3){      //2.0V -> 3.0V
            PORTD=display[2];
            digito=(valor-PARTE2)/20;
            PORTB=display[digito];
        }
        else if(valor<PARTE4){      //3.0V -> 4.0V
            PORTD=display[3];
            digito=(valor-PARTE3)/20;
            PORTB=display[digito];
        }
        else if(valor<PARTE5){      //4.0V -> 4.9V
            PORTD=display[4];
            digito=(valor-PARTE4)/20;
            PORTB=display[digito];
        }
        else{                       //5.0V
            PORTD=display[5];
            PORTB=display[0];
        }
    }

    return (EXIT_SUCCESS);
}