/*
 * File:   main.c
 * Author: User
 *
 * Created on 4 de Abril de 2018, 14:04
 */

/*
 * Verde 7 segundos
 vermelho 4 segundos
 amarelo 2 segundos
 */

#include <xc.h>
#include <p18f4550.h>
#pragma WDT CONFIG = OFF
#pragma config PBADEN = OFF

char estado_atual = 0;
char cont_segundos = 0;

char contador_interrupcao = 0;
char contador_um_segundo = 0;

//verde = 0
//amarelo = 1
//vermelho = 2

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

void troca_estado(){
    if(estado_atual == 0){
        //verde passa pro amarelo
        //desliga verde, acende amarelo
        estado_atual = 1;
        cont_segundos = 2;
    }else if(estado_atual == 1){
        // amarelo passa pro vermelho
        // desliga amarelo liga vermelho
        estado_atual = 2;
        cont_segundos = 4; 
    }else{
        //vermelho passa pra verde
        // desliga vermelho liga verde
        estado_atual = 0;
        cont_segundos = 7;
    }
}

void trata_segundo(){
    if(cont_segundos > 0 && estado_atual == 0){
        PORTCbits.RC1 = 0;
        PORTCbits.RC0 = 1;
        PORTCbits.RC2 = 0;
        PORTB = display[cont_segundos];
        cont_segundos--;
        if(cont_segundos == 0){
            troca_estado();
        }
    }else if(cont_segundos > 0 && estado_atual == 1){
        PORTCbits.RC1 = 1;
        PORTCbits.RC0 = 0;
        PORTCbits.RC2 = 0;
        PORTB = display[cont_segundos];
        cont_segundos--;
        if(cont_segundos == 0){
            troca_estado();
        }
    }else if (cont_segundos > 0 && estado_atual == 2){
        PORTCbits.RC0 = 0;
        PORTCbits.RC2 = 1;
        PORTCbits.RC1 = 0;
        PORTB = display[cont_segundos];
        cont_segundos--;
        if(cont_segundos == 0){
            troca_estado();
        }
    }
}

void interrupt low_priority pic_isr(void){
    if(TMR0IF){
        TMR0 = 32768;
        INTCONbits.TMR0IF = 0;
        contador_interrupcao++;
        if(contador_interrupcao == 2){
            contador_um_segundo = 1;
            contador_interrupcao = 0;
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
    TMR0 = 32768; //zera o contador da interrupção
    
    T0CONbits.TMR0ON = 1; //habilita o timer 0
    
    INTCONbits.GIEH = 1; //Global interrupt enable - high
    INTCONbits.GIEL = 1; //global interrupt enable - low
    
    
    ///Configuração da interrupção até aqui.
    
    //Configurando port B
    ADCON1 = 0x0F;
    TRISB = 0x00;
    TRISC = 0x00;
    
   // PORTCbits = 0x00;
    
    
    estado_atual = 0;
    cont_segundos = 7;
    PORTCbits.RC0 = 1;
    
    while(1){
        if(contador_um_segundo == 1){
            trata_segundo();
            contador_um_segundo = 0;
        }
    }
    return;
}
