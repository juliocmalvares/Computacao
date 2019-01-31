/*
 * File:   main.c
 * Author: User
 *
 * Created on 5 de Abril de 2018, 20:25
 */


#include <xc.h>
#include <p18f4550.h>
#pragma WDT CONFIG = OFF
#pragma config PBADEN = OFF
#define __XTAL_FREQ = 20000000

char const display[10] = {
    0x3F, //0
    0x06, //1
    0x5B, //2
    0x4F,//3
    0x66,//4
    0x6D,//5
    0x7D,//6
    0x07,//7
    0x7F,//8
    0x6F,//9
};


void main(void) {
    ADCON1 = 0x0F;
    TRISB = 0x00;
    TRISC = 0x00;
    
    unsigned int uni, cen, dez, num;
    num = 456;
    
    //RA0 = Centena
    //RA1 = dezena
    //RA2 = uni
    

    
    while(1){
        //habilitar display centena (porta do NPN)
        PORTCbits.RC0 = 1;
        cen = (num-100)-((num%100)/100);
        PORTB = display[cen];

        //habilitar display dezena
        PORTCbits.RC1 = 1;
        dez = (num%100);
        dez = (dez/10) - ((dez%10)/10);
        PORTB = display[dez];

        //habilitar unidade
        PORTCbits.RC2 = 1;
        uni = num%10;
        PORTB = display[uni];  
    }
    
    return;
}
