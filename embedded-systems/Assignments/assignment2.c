#include <stdbool.h>  
#include <stdio.h> 
#include <stdint.h> 
#include <string.h> 
#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h" 
volatile char temp1 = 'A'; 
bool flag=false; 
bool flagb=false; 
bool buzoff =false; 
float f; 
int e; 
int temp; 
int result=0; 
void EnableInterrupts(void) 
{ 
__asm("cpsie i\n");
} 
void UART0Tx(char c) 
{ 
	UART0_DR_R = c; 
} 
void Buzzer()//USING PE4 
{ 
SYSCTL_RCGCPWM_R |=2; //Enabling clock to PWM1 
SYSCTL_RCGCGPIO_R|=0x10; //Enabling clock to PortE 
SYSCTL_RCC_R &=~0x00100000; //No clock pre-divider for PWM 
GPIO_PORTE_AFSEL_R=0x10; //Alternate Function Enable for PE4 
GPIO_PORTE_PCTL_R = 0x50000;//Alternate Function value for PE4  
GPIO_PORTE_DIR_R |=0x10; //PE4 as output 
GPIO_PORTE_DEN_R |=0x10; //Enabling Digital at PE4 
PWM1_1_CTL_R = 0; //Stop Counter 
PWM1_1_GENA_R = 0x8C; //Output Set when reload and clear when matches CMPA 
PWM1_1_LOAD_R = 16000; //for 1KHz wave 
PWM1_1_CMPA_R = 8000; //50% duty cycle 
PWM1_1_CTL_R = 1; //Start Counter PWM1_ENABLE_R |= 0x4; //Enable PWM 
} 
void GPIO_Int_En(void) 
{ 
GPIO_PORTF_IM_R |=0x1; //Enabling intruppt on PF0 
NVIC_EN0_R |=(1<<30); //IRQ of PORT F 
GPIO_PORTF_IS_R &= ~(0x1); //Edge triggered on PF0 
GPIO_PORTF_IEV_R |= 0x1; // Rising edge 
} 
void Uart_Int_En(void) 
{ 
NVIC_EN0_R |=(1<<5);//IRQ of Port A 
UART0_IM_R |= 0x00030; //Rx Tx intruppt enable 
} 
void PortF_Init(void) 
{ 
SYSCTL_RCGCGPIO_R |= 0x00000020; // activate clock for Port F 
while((SYSCTL_PRGPIO_R&0x00000020) == 0){};// ready? 
GPIO_PORTF_LOCK_R = 0x4C4F434B; // unlock GPIO Port F 
GPIO_PORTF_CR_R |= 0x01; //Allow changes at PF0 
GPIO_PORTF_DIR_R &= (~0x01); //Input at PF0 
GPIO_PORTF_PUR_R |= 0x01; //Pull Up register at PF0 
GPIO_PORTF_DEN_R |= 0x01; //Digital enable at PF0 
} 
void delay() 
{ 
uint32_t counter=0; 
for (counter=0; counter<1500;counter++); 
} 
void UART_Init(void) 
{ 
SYSCTL_RCGCUART_R |= 0x0001; // activate UART0 
SYSCTL_RCGCGPIO_R |= 0x0001; // activate port A 
UART0_CTL_R &= ~0x0001; // disable UART 
UART0_IBRD_R = 8; //Decimal part of Baud rate 
UART0_FBRD_R = 44; //Fractional part of Baud Rate 
UART0_LCRH_R = 0x0060; // 8-bit length, disable FIFO 
UART0_CTL_R = 0x0301; // enable RXE, TXE and UART
GPIO_PORTA_AFSEL_R |= 0x03; // alt funct on PA1-0 
GPIO_PORTA_PCTL_R = 0x00000011; //Alternate function value 
GPIO_PORTA_DEN_R |= 0x03; // digital I/O on PA1-0 
GPIO_PORTA_DIR_R=2; //Output on PA1-0 
GPIO_PORTA_AMSEL_R &= ~0x03; // No analog on PB1-0 
} 
void UART0_Handler(void) 
{ 
if (UART0_MIS_R & 0x0010) //check on recieve flag 
{ 
temp1=UART0_DR_R; //store data in temp1 
UART0_ICR_R=0x0010; //Clearing recieving flag 
if(temp1=='b') 
{ 
PWM1_ENABLE_R &= ~0x4; //disable PWM 
buzoff=true; //buzzer flag  
} 
} 
else 
UART0_ICR_R=0x0020; //check on transmit flag 
} 
void sendString(char*ptr) 
{  
int i; 
for(i=0;i<strlen(ptr);i++) 
{ 
UART0Tx(ptr[i]); //sending string 
delay(); 
} 
} 
void GPIOPortF_Handler(void) 
{ 
sendString("\r*............INTRUDER DETECTED..........*\r"); 
Buzzer(); 
for(e=0;e<10000000;e++); 
GPIO_PORTF_ICR_R|=1; //clearing flag 
} 
void ADC0Seq3_Handler(void) //Temperature Intruppt 
{ 
result = ADC0_SSFIFO3_R; 
f=(result*330)/4096; 
if(f>70) 
{ 
if(buzoff==false) 
Buzzer();  
sendString(" .........*TEMPERATURE IS  HIGH*................\r");
flag=true; 
} 
else 
{ 
if(flagb==false) 
{ 

buzoff=false; 
} 
flag=false; 
} 
temp=f; 
sendString("Temperature = "); 
delay(); 
if(temp/100!=0) 
{ UART0Tx((temp/100)+48); 
delay(); 
temp%=100; 
} 
UART0Tx(temp/10+48); 
delay(); 
UART0Tx(temp%10+48); 
delay(); 
sendString("'C "); 
delay(); 
ADC0_ISC_R=8; 
} 
void ADC1Seq3_Handler(void)//Smoke Intruppt 
{ 
result = ADC1_SSFIFO3_R; 
f=(result*330)/4096; 
temp=f; 
sendString("Smoke = "); 
delay(); 
if(temp/100!=0) 
{ UART0Tx((temp/100)+48); 
delay(); 
temp%=100; 
} 
UART0Tx(temp/10+48); 
delay(); 
//UART0Tx(46); 
UART0Tx(temp%10+48); 
delay(); 
//UART0Tx(0x85); 
//sendString(" \r");
if(f>200) 
{ 
if(buzoff==false) 
Buzzer(); 
sendString(".......*HAZARDOUS SMOKE DETECTED*..........\r"); 
flagb=true; 
} 
else 
{ 
if(flag==false) 
{ 
sendString(" \r"); 
buzoff=false; 
} 
flagb=false; 
} 
//UART0Tx('\r'); 
sendString("\r"); 
ADC1_ISC_R=8; 
for(e=0;e<1000000;e++); 
} 
void ADC_Init(void) 
{ 
SYSCTL_RCGCGPIO_R |= 0x8; //Unlocking Port D 
SYSCTL_RCGCADC_R |=3; //Enabling ADC Module 0 & 1 
GPIO_PORTD_LOCK_R = 0x4C4F434B; //Unlock 
GPIO_PORTD_AFSEL_R |=3; //Alternate function for PD1-0 
GPIO_PORTD_DEN_R &=~3; //Digital Disable PD1-0 
GPIO_PORTD_AMSEL_R |=3; //Analog Enable PD1-0 
ADC0_ACTSS_R &=~8; //Disable ADC0 seq3 
ADC0_EMUX_R&=~0xF000; //Use default processor 
ADC0_SSMUX3_R=6; // ADC input 6 at PD1 
ADC0_SSCTL3_R |=6; //take one sample at a time, set flag at 1st sample 
ADC0_ACTSS_R |=8; //Enable ADC0 seq3 
NVIC_EN0_R |= (1<<17); //IRQ of ADC0 SS3 
ADC0_IM_R |=8; //sample Sequencer 3 
ADC1_ACTSS_R &=~8; //Disable ADC1 seq3 
ADC1_EMUX_R&=~0xF000; //Use default processor 
ADC1_SSMUX3_R=7; //ADC input 7 at PD0 
ADC1_SSCTL3_R |=6; //take one sample at a time, set flag at 1st sample ADC1_ACTSS_R |=8; //Enable ADC1 seq3 
NVIC_EN1_R |= (1<<19); //IRQ of ADC1 SS3 
ADC1_IM_R |=8; //sample Sequencer 3 
} 
int main(void)
{ 
EnableInterrupts(); 
UART_Init(); 
Uart_Int_En(); 
PortF_Init(); 
GPIO_Int_En(); 
ADC_Init(); 
while(1) 
{ 
ADC0_PSSI_R |=8; 
ADC1_PSSI_R |=8; 
} 
} 
