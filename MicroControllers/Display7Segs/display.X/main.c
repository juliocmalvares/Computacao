/*
 * File:   main.c
 * Author: User
 *
 * Created on 28 de Março de 2018, 10:53
 */
#include <xc.h>
#include <p18f4550.h>

#pragma config PBADEN = OFF
#pragma WDT CONFIG = OFF


int x = 0;

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

void interrupt low_priority pic_isr(void){
    if(TMR0IF){
        TMR0 = 0;
        INTCONbits.TMR0IF = 0;
        if(x < 10){
            PORTB = display[x];
            x++;
            if(x == 10) x = 0;
            
        }
    }
}


void main(void){
    T0CONbits.TMR0ON = 0; //desabilita Timer
    INTCONbits.TMR0IE = 1; //Habilita interruoção TRM0
    
    INTCONbits.TMR0IF = 0; //Limpa flag de interrupção
    
    T0CONbits.T08BIT = 0; //Temporizador/contador de 16Bits
    T0CONbits.PSA = 0;
    T0CONbits.T0PS0 = 1;
    T0CONbits.T0PS1 = 1;
    T0CONbits.T0PS2 = 0;
    
    T0CONbits.T0CS = 0; //desabilita clock interno
    TMR0 = 0; //zera o contador da interrupção
    
    T0CONbits.TMR0ON = 1; //habilita o timer 0
    
    INTCONbits.GIEH = 1; //Global interrupt enable - high
    INTCONbits.GIEL = 1; //global interrupt enable - low
    
    
    ///Configuração da interrupção até aqui.
    
    //Configurando port B
    ADCON1 = 0x0F;
    TRISB = 0x00;
    
    while(1){
        
    }
    return;
}
