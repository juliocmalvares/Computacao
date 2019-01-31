#include <stdlib.h>
#include <stdio.h>
#include <xc.h>
#include <plib/usart.h>
#include <p18f4550.h>

void enviaByte(unsigned char);
void tx_data();

#define _XTAL_FREQ 12000000 //The speed of your internal(or)external oscillator

#define IDLE 0			//estado da máquina
#define VERIFICACRC 1	//estado da maquina
#define COMRECEBIDO 2	//estado da máquina
#define ENVIARESPOSTA 3	//estado da máquina
#define ENVIAACK 4		//estado da máquina
#define ENVIANACK 5		//estado da máquina

#define ALTERACAO 2 	//estado de comando
#define LEITURA 1  		//estado de comando

#define ACK 	0x05	//estado de comando aceito
#define NACK 	0x15	//estado de comando recusado

#define FREQ 12000000    // Frequency = 12MHz
#define baud 9600
#define spbrg_value (((FREQ/64)/baud)-1)    // Refer to the formula for Baud rate calculation in Description tab
#define POLY    0x8408	//constante de calculo de crc

#define comando_versao 	0
#define comando_hora 	1
#define comando_data	2
#define comando_alarme	3

unsigned char serial_data;
unsigned int i = 0;

unsigned char BUFFCOM[7], BUFFRESP[7];

char estado = IDLE; // estado idle

char versao = 1;
char revisao = 2;

unsigned short crc16(char *data_p, unsigned short length){
      unsigned char i;
      unsigned int data;
      unsigned int crc = 0xffff;
      if (length == 0)
            return (~crc);

      do{
            for (i=0, data=(unsigned int)0xff & *data_p++; i < 8; i++, data >>= 1){
                  if ((crc & 0x0001) ^ (data & 0x0001))
                        crc = (crc >> 1) ^ POLY;
                  else  crc >>= 1;
            }
      } while (--length);

      crc = ~crc;
      data = crc;
      crc = (crc << 8) | (data >> 8 & 0xff);
      return (crc);
}


void calculaCRCBUFFRESP(){
	int crc = crc16(BUFFCOM, 5);
	char crc1 = crc >> 8;
	char crc2 = crc & 0xFF;
	memcpy(BUFFCOM[5], crc1, sizeof(BUFFCOM[5]));
	memcpy(BUFFCOM[6], crc2, sizeof(BUFFCOM[6]));
	estado = ENVIARESPOSTA;
}

void trataComando(){
	//verifica se e comando de leitura ou alteracao	
	switch(BUFFCOM[0]){
		case LEITURA:
			memcpy(BUFFRESP[0], BUFFCOM[0], sizeof(BUFFCOM[0]));
			memcpy(BUFFRESP[1], BUFFCOM[1], sizeof(BUFFCOM[1]));
			switch(BUFFCOM[1]){
				//consulta a versao e revisao do sistema
				case comando_versao:
					BUFFRESP[2] = versao;
					BUFFRESP[3] = revisao;
					BUFFRESP[4] = 0xFF; //posição vazia
					break;			
				
				//consulta a hora atual do sistema
				case comando_hora:
					BUFFRESP[2] = hora;
					BUFFRESP[3] = minuto;
					BUFFRESP[4] = segundo;
					break;

				//consulta a data atual do sistema
				case comando_data:
					BUFFRESP[2] = dia;
					BUFFRESP[3] = mes;
					BUFFRESP[4] = ano;
					break;

				//consulta a data atual do alarme
				case comando_alarme:
					BUFFRESP[2] = hora_alarme;
					BUFFRESP[3] = minuto_alarme;
					BUFFRESP[4] = segundo_alarme;;
					break;
				
				default:
					break;
				
			}	
			break;

		case ALTERACAO:
			int i = 0;
			for(i = 0; i < 5; i++)
				memcpy(BUFFRESP[i], BUFFCOM[i], sizeof(BUFFCOM[i]));

			// verifica o que deve ser lido
			switch(BUFFCOM[1])
			{
				//altera versao e revisao
				case comando_versao:		
					versao  = BUFFCOM[2];
					revisao = BUFFCOM[3];
					break;			
				
				//altera hora
				case comando_hora:
					hora = BUFFCOM[2];
					minuto = BUFFCOM[3];
					segundo = BUFFCOM[4];
					break;
				
				//altera data
				case comando_data:
					dia = BUFFCOM[2];
					mes = BUFFCOM[3];
					ano = BUFFCOM[4];
					break;
				
				//altera hora do alarme
				case comando_alarme:
					hora_alarme = BUFFCOM[2];
					minuto_alarme = BUFFCOM[3];
					segundo_alarme = BUFFCOM[4];
				default:
					break;
			}
		break;		
	}
	calculaCRCBUFFRESP();	
}



void verificaCRCBUFFCOM(){
	char CRC_OK;
	int crc = crc16(BUFFCOM, 5);
	char crc1 = crc >> 8;
	char crc2 = crc & 0xFF;

	if(crc1 == BUFFCOM[5] && BUFFCOM[6] == crc2) CRC_OK = 1;
	else CRC_OK = 0;
	

	if(CRC_OK == 1) estado = ENVIAACK;
	else estado = ENVIANACK;
}

void maquinaEstado(){
	switch(estado){
		case VERIFICACRC:
			verificaCRCBUFFCOM();
			break;
		
		case COMRECEBIDO:
			trataComando();
			break;
		
		case ENVIARESPOSTA:
			tx_data();
			break;	
		
		case ENVIAACK:
			enviaByte(ACK);
			break;
		
		case ENVIANACK:
			enviaByte(NACK);
			break;
		
		default:
			break;
	}
}

void main(){
    SPBRG = spbrg_value;                                // Fill the SPBRG register to set the Baud Rate
    //RCSTA.SPEN=1;                                     // To activate Serial port (TX and RX pins)
   // TXSTA.TXEN=1;                                     // To enable transmission
   // RCSTA.CREN=1;                                     // To enable continuous reception   
    RCSTA = 0b10010000; // 0x90 (SPEN RX9 SREN CREN ADEN FERR OERR RX9D)
    TXSTA = 0b00100000; // 0x20 (CSRC TX9 TXEN SYNC - BRGH TRMT TX9D)
    TRISCbits.RC6 = 0; //TX pin set as output
    TRISCbits.RC7 = 1; //RX pin set as input
    //compare with the table above
    RCIF = 0; //reset RX pin flag
    RCIP = 0; //Not high priority
    RCIE = 1; //Enable RX interrupt
    PEIE = 1; //Enable pheripheral interrupt (serial port is a pheripheral)
    
    while(1){
       maquinaEstado();
    }
}

void enviaByte(char BYTE){
	while(!TXIF);                            // Wait until RCIF gets low
	TXREG = BYTE;

	if(BYTE==ACK)
		estado = COMRECEBIDO;
	else
		estado = IDLE;
}

//envia buffer de resposta pela serial
void tx_data(){
	int cont;
	for(cont=0;cont<7;cont++){
    	while(!TXIF);                            // Wait until RCIF gets low
    	TXREG = BUFFRESP[cont];
	}
	estado = IDLE;
}

void interrupt SerialRxPinInterrupt(){
    //check if the interrupt is caused by RX pin
    if(PIR1bits.RCIF == 1){
        if(i<7){
        while(!RCIF);                            // Wait until RCIF gets low
            BUFFCOM[i]= RCREG;                                   // Retrieve data from reception register
            
          i++;  
        }else{
            PIR1bits.RCIF = 0; // clear rx flag
            i=0;
            estado = VERIFICACRC;
            
        }
    }
}