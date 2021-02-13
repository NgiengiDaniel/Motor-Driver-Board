# Motor-Driver-Board
A simple Circuit / PCB that drives 4 DC brushed motors with a wide input voltage range. 
This board aims to simplify wiring when testing motors with a micro-controller.

## Specs

* The board can control motors using 3 MCU GPIO pins by using an 8bit shift register (74hc595). 
* Maximum current for each motor is 1A.
* Input voltage range theoretically is 2.5V - 21V. Design constraints make it 6V minimum for the 5V regulator to provide power to the shift register.

## Code example
```C
//This test code controls 1 DC, connected on output 1 of the board.
//To control more motors, shift 8 bits in groups of 2 according to the output number.

const int latch_pin = 5, clock_pin = 4, data_pin = 16;
void setup() 
{
  pinMode( latch_pin,OUTPUT );
  pinMode( clock_pin,OUTPUT );
  pinMode( data_pin,OUTPUT );
  Serial.begin(9600);
}

void loop() 
{
  Serial.println( "Moving forward" );
  digitalWrite( latch_pin, LOW );
  shiftOut( data_pin, clock_pin, LSBFIRST, 0b10000000 );
  digitalWrite( latch_pin, HIGH );
  
  delay( 1000 );

  Serial.println( "Moving backwards" );
  digitalWrite( latch_pin, LOW );
  shiftOut( data_pin, clock_pin, LSBFIRST, 0b01000000 );
  digitalWrite( latch_pin, HIGH );
  
  delay( 1000 );

  Serial.println( "Motor brake" );
  digitalWrite( latch_pin, LOW );
  shiftOut( data_pin, clock_pin, LSBFIRST, 0b11000000 );
  digitalWrite( latch_pin, HIGH );
  
  delay( 1000 );

  Serial.println( "COAST" );
  digitalWrite( latch_pin, LOW );
  shiftOut( data_pin, clock_pin, LSBFIRST, 0b00000000 );
  digitalWrite( latch_pin, HIGH );
  
  delay( 1000 );

```


