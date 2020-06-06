#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
void LED_Init(void);
void One_Second_Delay(void);
void main(void)
{
LED_init();
One_Second_Delay();
uint8_t row, col;
GPIO_PORTB_DATA_R = 0x00;// clear portb bits 
for(;;)
{
Col1 = GPIO_PORTC_DATA_R & 0xF0;// clear portC 7~4 bits
Col2 = GPIO_PORTD_DATA_R & 0xF0;// clear portC 7~4 bits
//walk symbol
for(int i=1;i<30;i++)
{
Row =7;
GPIO_PORTB_DATA_R = 0x70;
GPIO_PORTC_DATA_R = 0x60;
GPIO_PORTC_DATA_R = 0Xff;
One_Second_Delay(5000);//5ms second

Row =6;
GPIO_PORTB_DATA_R = 0xBf;
GPIO_PORTC_DATA_R = 0x60;
GPIO_PORTC_DATA_R = 0Xff;
One_Second_Delay(5000);//5ms second

Row=5;
GPIO_PORTB_DATA_R = 0xDF;
GPIO_PORTC_DATA_R = 0x30;
GPIO_PORTC_DATA_R = 0Xff;
One_Second_Delay(5000);//5ms second

Row =4;
GPIO_PORTB_DATA_R = 0xEF;
GPIO_PORTC_DATA_R = 0x70;
GPIO_PORTC_DATA_R = 0Xfc;
One_Second_Delay(5000);//5ms second

Row =3;
GPIO_PORTB_DATA_R = 0x70;
GPIO_PORTC_DATA_R = 0x60;
GPIO_PORTC_DATA_R = 0X0A;
One_Second_Delay(5000);//5ms second

Row =2;
GPIO_PORTB_DATA_R = 0xFB;
GPIO_PORTC_DATA_R = 0x60;
GPIO_PORTC_DATA_R = 0X03;
One_Second_Delay(5000);//5ms second

Row =1;
GPIO_PORTB_DATA_R = 0xFD;
GPIO_PORTC_DATA_R = 0x60;
GPIO_PORTC_DATA_R = 0X02;
One_Second_Delay(5000);//5ms second
Row=0;
GPIO_PORTB_DATA_R = 0xFE;
GPIO_PORTC_DATA_R = 0x20;
GPIO_PORTC_DATA_R = 0X02;
One_Second_Delay(5000);//5ms second

}
// stop signal
for(int i=1;i<30;i++)
{
Row=7;
GPIO_PORTB_DATA_R = 0x70;
GPIO_PORTC_DATA_R = 0x10;
GPIO_PORTC_DATA_R = 0X08;
One_Second_Delay(5000);//5ms second

Row =6;
GPIO_PORTB_DATA_R = 0xBf;
GPIO_PORTC_DATA_R = 0x10;
GPIO_PORTC_DATA_R = 0X08;
One_Second_Delay(5000);//5ms second

Row =5;
GPIO_PORTB_DATA_R = 0xDF;
GPIO_PORTC_DATA_R = 0x30;
GPIO_PORTC_DATA_R = 0X0c;
One_Second_Delay(5000);//5ms second

Row =4;
GPIO_PORTB_DATA_R = 0xEF;
GPIO_PORTC_DATA_R = 0x50;
GPIO_PORTC_DATA_R = 0X05;
One_Second_Delay(5000);//5ms second

Row =3;
GPIO_PORTB_DATA_R = 0x70;
GPIO_PORTC_DATA_R = 0x10;
GPIO_PORTC_DATA_R = 0X08;
One_Second_Delay(5000);//5ms second

Row =2;
GPIO_PORTB_DATA_R = 0xFB;
GPIO_PORTC_DATA_R = 0x60;
GPIO_PORTC_DATA_R = 0X03;
One_Second_Delay(5000);//5ms second

Row =1;
GPIO_PORTB_DATA_R = 0xFD;
GPIO_PORTC_DATA_R = 0x30;
GPIO_PORTC_DATA_R = 0X02;
One_Second_Delay(5000);//5ms second

Row =0;
GPIO_PORTB_DATA_R = 0xFE;
GPIO_PORTC_DATA_R = 0x40;
GPIO_PORTC_DATA_R = 0X02;
One_Second_Delay(5000);//5ms second
}
}
void LED_init(void)
{
SYSCTL_RCGCGPIO_R |= 0x04;// Enable PortC clock
SYSCTL_RCGCGPIO_R |= 0x08;// Enable PortD clock
GPIO_PORTC_DIR_R &= ~0xF0;// Set PC7-4as input
GPIO_PORTC_DEN_R |= 0xF0;// set PC7~4as digital pins
GPIO_PORTC_PUR_R |= 0xF0;// set PC7~4as pull-ups
GPIO_PORTD_DIR_R |= 0x0F;// setPD3~0asoutput
GPIO_PORTD_DEN_R |= 0x0F;// set PD3~0as digitalpins
GPIO_PORTD_pur_R |= 0x0F;// set PD3~0 as open drain
SYSCTL_RCGCGPIO_R |= 0x02; 
GPIO_PORTB_DIR_R |= ~0xFF; 
GPIO_PORTB_DEN_R |= 0xFF;
GPIO_PORTB_PDR_R=0XFF;//open drain
}
// One Second Delay
void One_Second_Delay(void)
{ 
NVIC_ST_CTRL_R = 0;            // (1) disable SysTick during setup
NVIC_ST_RELOAD_R = 16000000-1;   // (2) Reload Value goes here
NVIC_ST_CTRL_R |= 0x5;         // (4) enable SysTick with core clock
while((NVIC_ST_CTRL_R & (1<<16)) == 0)
;                          // Monitoring bit 16 to be set
NVIC_ST_CTRL_R = 0;// (4) Disabling SysTick Timer
}
