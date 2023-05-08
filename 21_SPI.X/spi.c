/* 
 * File:   spi.c
 * Author: LEYVA
 *
 * Created on 24 de abril de 2021, 06:36 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f887.h>

#define _XTAL_FREQ 20000000

//Funciones SPI
void spi_write(unsigned int v){
	SSPBUF=v;
	while(!SSPSTATbits.BF){		//Flag==1 Delay for receive completed
		//Nothing
	}
}

unsigned char spi_read(){
	SSPBUF=0x00;			//Initiate bus cycle
	while(!PIR1bits.SSPIF){		//Delay until cycle completed
		//nothing
	}
	return (SSPBUF);
}

int main() {
    //Config puertos
    TRISCbits.TRISC3=0;		//Serial clock (output)
    TRISCbits.TRISC4=1;		//MISO (input)
    TRISCbits.TRISC5=0;		//MOSI (output)
    TRISDbits.TRISD0=0;		//Slave select (output)

    //Config SPI
    SSPCONbits.SSPEN=1;         //1=Enables serial ports SCK,SDO,SDI,SS
    SSPCONbits.CKP=0;		//0=Idle state low / 1=Idle high level
    SSPCONbits.SSPM=0b0000;	//SPI master mode clock=fosc/4

    SSPSTATbits.SMP=0;		//0=Input data sampled at the middle of out data time
    SSPSTATbits.CKE=0;		//0=Transmit ocurrs on transision from idle to active

    while(1){
        PORTDbits.RD0=0;        //Select slave
        spi_write(8);           //Send data
        PORTDbits.RD0=1;        //Deselect slave
        __delay_ms(100);

        unsigned char a =spi_read();
        __delay_ms(100);
    }

    return (EXIT_SUCCESS);
}

