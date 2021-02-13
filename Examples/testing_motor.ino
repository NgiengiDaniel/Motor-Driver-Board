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
    Serial.println( "FWD" );
  digitalWrite( latch_pin, LOW );
  shiftOut( data_pin, clock_pin, LSBFIRST, 0b10000000 );
  digitalWrite( latch_pin, HIGH );
  
  delay( 1000 );

    Serial.println( "BACK" );
  digitalWrite( latch_pin, LOW );
  shiftOut( data_pin, clock_pin, LSBFIRST, 0b01000000 );
  digitalWrite( latch_pin, HIGH );
  
  delay( 1000 );

  Serial.println( "BREK" );
  digitalWrite( latch_pin, LOW );
  shiftOut( data_pin, clock_pin, LSBFIRST, 0b11000000 );
  digitalWrite( latch_pin, HIGH );
  
  delay( 1000 );

  Serial.println( "COAST" );
  digitalWrite( latch_pin, LOW );
  shiftOut( data_pin, clock_pin, LSBFIRST, 0b00000000 );
  digitalWrite( latch_pin, HIGH );
  
  delay( 1000 );
}
