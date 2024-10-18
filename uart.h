#include "MKL25Z4.h"
#include "TpUart.h"
char dato;
void UART0_INIT(){
SIM->SCGC4|=SIM_SCGC4_UART0_MASK;
SIM->SCGC5|=SIM_SCGC5_PORTA_MASK;
PORTA->PCR[1]=PORT_PCR_MUX(2);
PORTA->PCR[2]=PORT_PCR_MUX(2);
UART0->c2=0;
UART0->BDH=A0;
UART0->BDL=26;//9600 BAUDIOS
UART0->c1=0x00;
UART0->0x0C;
}
char UART0_SEND(char dato){
while(!(UART0->S1&UART_S1_TDRE_MASK));
    UART0->D=dato;
}
char UART0_RECIBE(){
    while(!(UART0->S1&UART_S1_TDRE_MASK));
    return UART0->d;
}
