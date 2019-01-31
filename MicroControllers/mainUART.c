

#include <xc.h>

#include <plib/usart.h>
#include <p18f4550.h>

#define _XTAL_FREQ 12000000 //The speed of your internal(or)external oscillator


void tx_data(unsigned char);

unsigned char rx_data(void);
unsigned char serial_data;
unsigned int i=0;

#define FREQ 12000000    // Frequency = 12MHz
#define baud 9600
#define spbrg_value (((FREQ/64)/baud)-1)    // Refer to the formula for Baud rate calculation in Description tab

int dado;

void main()
{
    SPBRG=spbrg_value;                                // Fill the SPBRG register to set the Baud Rate
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
    
    while(1)
    {
        serial_data=rx_data();    // Receive data from PC
        tx_data(serial_data);        // Transmit the same data back to PC
    }


}

void tx_data(unsigned char data1)
{
    while(!TXIF);                            // Wait until RCIF gets low
    TXREG = data1;
}



unsigned char rx_data(void)
{
    while(!RCIF);                            // Wait until RCIF gets low
    return RCREG;                                   // Retrieve data from reception register
}

void interrupt SerialRxPinInterrupt()
{
    //check if the interrupt is caused by RX pin
    if(PIR1bits.RCIF == 1)
    {
        if(i<5)
        {
        while(!RCIF);                            // Wait until RCIF gets low
            dado[i]= RCREG;                                   // Retrieve data from reception register
            
          i++;  
        }else
        {
            PIR1bits.RCIF = 0; // clear rx flag
            i=0;
        }
        
        
        
    }

}