/*PIOB Example for Arduino Due
 * by Brendan Aguiar 
 * Version 0.1
 * Due Manual: tinyurl.com/55vn5pzb
 * Description: This program uses Arduino Due register assignments for PIO output for an LED.
 * Pins in use:  Description:
 * D13           LED output (PB27)
 */
 
//PIOB Assignments for LED
volatile unsigned long* PIO_WPMR = (unsigned long*)0x400E10E4;//PIO Write Protect Mode
volatile unsigned long* PIO_OER = (unsigned long*)0x400E1010;//Output Enable
volatile unsigned long* PIO_SODR = (unsigned long*)0x400E1030;//Set Output Data
volatile unsigned long* PIO_CODR = (unsigned long*)0x400E1034;//Clear Output Data
volatile unsigned long* PIO_ODSR = (unsigned long*)0x400E1038;//Output Status

void setup()
{
  // set the digital pin as output:
  set_LED();
}

void loop() 
{
  *PIO_SODR = 0x08000000;
  delay(1000);
  *PIO_CODR = 0x08000000;
  delay(1000);
}
void set_LED()
{
  *PIO_WPMR = 0x50494F00;
  *PIO_OER = 0x08000000; //PB27 set to Output (Digital 13 for Arduino Due)
}
