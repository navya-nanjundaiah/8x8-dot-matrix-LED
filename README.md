# 8x8-dot-matrix-LED
Used the PortB, PortC and PortD of the TM4C123GH6PM launch board to drive 8x8 dot matrix LED to simulate pedestrian traffic lights(stop sign and Walk sign )
## Circuit Diagram

<img src="/Capture.PNG?raw=true">
## Components Required
- TM4C123GH6PM launch board
- 8X8 Matrix LED
- USB Cable
- Jumper wires
## Steps Invovled
- Intialize Port B  as the output
```
SYSCTL_RCGCGPIO_R |= 0x02; 
GPIO_PORTB_DIR_R |= ~0xFF; 
GPIO_PORTB_DEN_R |= 0xFF;
```
- Intialize as Port C and Port D as output as well
```
//Port C
SYSCTL_RCGCGPIO_R |= 0x04;// Enable PortC clock
GPIO_PORTC_DIR_R &= ~0xF0;// Set PC7-4as input
GPIO_PORTC_DEN_R |= 0xF0;// set PC7~4as digital pins
// Port D
SYSCTL_RCGCGPIO_R |= 0x08;// Enable PortD clock
GPIO_PORTD_DIR_R |= 0x0F;// setPD3~0asoutput
GPIO_PORTD_DEN_R |= 0x0F;// set PD3~0as digitalpins
```
- Intialize Port C and Port D as Pull register
```
GPIO_PORTC_PUR_R |= 0xF0;// set PC7~4as pull-ups
GPIO_PORTD_pur_R |= 0x0F;// set PD3~0 as open drain
```
- Iatialize port B as open drain
```
GPIO_PORTB_PDR_R=0XFF;//open drain

```
- In the loop we write to turn on a stop sign for 30 seconds, then display the pattern of walk sign for 30 seconds, and then repeat.

