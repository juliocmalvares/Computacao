/*
 * File:   main.c
 * Author: Efrem
 *
 * Created on 1 de Junho de 2017, 09:44
 */
#include <p18f4550.h>
#include <xc.h>
#include <delays.h>
#include <adc.h>

#define _XTAL_FREQ = 48000000;

float voltage=0;
 
unsigned int ADCResult = 0;
float voltage;

void init_ADC(void)        //Configure ADC with 3 analog channels
{

OpenADC(ADC_FOSC_64 &              // ADC_FOSC_64:      Clock de conversão do A/D igual a
                        //               FAD = FOSC/64 = 48MHz/64 = 750kHz
                        //               Desta Forma, TAD=1/FAD = 1,33us.
         ADC_RIGHT_JUST &            // ADC_RIGHT_JUST:    Resultado da conversão ocupará os
                        //               bits menos significativos dos regis-
                        //               tradores ADRESH e ADRESL.
         ADC_12_TAD,               // ADC_12_TAD:              Determina o tempo de conversão de uma
                        //               palavra de 10-bits. Neste caso será
                        //               igual a 12*TAD = 12*1,33us = 16us.
         
         ADC_CH0 &          // ADC_CH0:         Atua sobre os bits CHS3:CHS0 do ADCON0
                        //               para selecionar o canal no qual será
                        //               realizada a conversão. Neste caso o AN0.
         ADC_INT_OFF &       // ADC_INT_OFF:      Habilita ou Desabilita a interrupção de términio de
                        //               conversão.
         ADC_REF_VDD_VSS,    //ADC reference voltage from VDD & VSS
         ADC_1ANA);         // BITs PCFG3:PCFG0:        Configura os pinos  AN1(RA1) e AN0(RA0) como Entradas Analógicas
}




void main(void)
{
    init_ADC();                        // Call initialize ADC
    while(1)
    {
        ADCResult = 0;
    //---sample and convert---- 
        for(unsigned char i=0;i<=2;i++) //Loop 3 times to sample and read each channel individually.
        {
            SetChanADC(ADC_CH0);//ADCON0 = 0b00000000;  //Select a channel to sample (index i = 0 (first channel) when the loop
            //runs for the first time, i will be 1 then 2 for each successive runs)
            ConvertADC();         // Convert Analog to Digital
            while(BusyADC());
            ADCResult += (unsigned int) ReadADC();   //Read each channel
            
        }

        voltage = ((ADCResult/15)*5.0)/1023;            //convert 10-bit ADC data into voltage 
    }
}

/*
 * para interupcao
  if(PIR1bits.ADIF == 1)
  {
    PIR1bits.ADIF = 0; 
    voltage = (ADRESL*5.0)/1023; 
    voltage = (((ADRESH<<8)+ ADRESL)*5.0)/1023; 
    ADCON0bits.GO_DONE = 1; 
  } 
  
 * */
