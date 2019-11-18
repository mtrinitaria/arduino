
// Latch pin of 74HC595 (pin 12) is connected to Digital pin 5
int latchPin = 5; 

// Clock pin of 74HC595 (pin 11) is connected to Digital pin 6
int clockPin = 6;

// Data pin of 74HC595 (pin 14) is connected to Digital pin 4
int dataPin = 4;

byte leds = 0;    // Variable to hold the pattern of which LEDs are currently turned on or off

int DIG_1 = 2;
int DIG_2 = 3;
int DIG_3 = 7;
int DIG_4 = 8;

int SEG_A = 0;
int SEG_B = 1;
int SEG_C = 2;
int SEG_D = 3;
int SEG_E = 4;
int SEG_F = 5;
int SEG_G = 6;
int SEG_H = 7;

int ticker = 0;
int thousands = 0;
int hundreds= 0;
int tens= 0;
int ones = 0;

int tick = 5;
int isSecond = false;

int timer = 0;

/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup() 
{
  Serial.begin(9600);
  // Set all the pins of 74HC595 as OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  
  pinMode(DIG_1, OUTPUT);
  pinMode(DIG_2, OUTPUT);
  pinMode(DIG_3, OUTPUT);
  pinMode(DIG_4, OUTPUT);
}
/*
 * loop() - this function runs over and over again
 */
void loop() {
//  ticker = 1235;
  if ( timer % 50 == 0 ) {
    isSecond = true;
    ticker = random(0, 9999);
  } else {
    isSecond = false;
  }
  Serial.println(timer);
  thousands = int(ticker / 1000);
  hundreds  = int(ticker % 1000 / 100);
  tens      = int(ticker % 1000 % 100 / 10);
  ones      = int(ticker % 10);
//  Serial.println(String(thousands) + " " + String(hundreds) + " " + String(tens) + " " + String(ones));


  setDigit(1);
  displayNumber(thousands);
  delay(tick);

  setDigit(2);
  displayNumber(hundreds);
  delay(tick);
  
  setDigit(3);
  displayNumber(tens);
  delay(tick);
  
  setDigit(4);
  displayNumber(ones);
  delay(tick);
  
  

//  ticker ++;
  timer ++;

//  delay(1);
}

/*
 * updateShiftRegister() - This function sets the latchPin to low, then calls the Arduino function 'shiftOut' to shift out contents of variable 'leds' in the shift register before putting the 'latchPin' high again.
 */
void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}


void displayNumber(int n) {
  // Initially turns all the LEDs off, by giving the variable 'leds' the value 0
  // reset leds to 0 every tick
  leds = 0;

  switch (n) {
    case 0:
      goto return0;
      break;
    case 1:
      goto return1;
      break;
    case 2:
      goto return2;
      break;
    case 3:
      goto return3;
      break;
    case 4:
      goto return4;
      break;
    case 5:
      goto return5;
      break;
    case 6:
      goto return6;
      break;
    case 7:
      goto return7;
      break;
    case 8:
      goto return8;
      break;
    case 9:
      goto return9;
      break;
    default:
      // statements
    break;
  }

  //0
  return0:
    // Set the bit that controls that LED in the variable 'leds'
    bitSet(leds, SEG_A);
    bitSet(leds, SEG_B);
    bitSet(leds, SEG_C);
    bitSet(leds, SEG_D);
    bitSet(leds, SEG_E);
    bitSet(leds, SEG_F);
    updateShiftRegister();

  goto last;

  //1
  return1:
    bitSet(leds, SEG_B);
    bitSet(leds, SEG_C);
    updateShiftRegister();
  
  goto last;

  //2
  return2:
    bitSet(leds, SEG_A);
    bitSet(leds, SEG_B);
    bitSet(leds, SEG_G);
    bitSet(leds, SEG_E);
    bitSet(leds, SEG_D);
    updateShiftRegister();
  
  goto last;

  //3
  return3:
    bitSet(leds, SEG_A);
    bitSet(leds, SEG_B);
    bitSet(leds, SEG_G);
    bitSet(leds, SEG_C);
    bitSet(leds, SEG_D);
    updateShiftRegister();
  
  goto last;

  //4
  return4:
    bitSet(leds, SEG_F);
    bitSet(leds, SEG_G);
    bitSet(leds, SEG_B);
    bitSet(leds, SEG_C);
    updateShiftRegister();
  
  goto last;

  //5
  return5:
    bitSet(leds, SEG_A);
    bitSet(leds, SEG_F);
    bitSet(leds, SEG_G);
    bitSet(leds, SEG_C);
    bitSet(leds, SEG_D);
    updateShiftRegister();
  
  goto last;

  //6
  return6:
    bitSet(leds, SEG_A);
    bitSet(leds, SEG_F);
    bitSet(leds, SEG_E);
    bitSet(leds, SEG_D);
    bitSet(leds, SEG_C);
    bitSet(leds, SEG_G);
    updateShiftRegister();
  
  goto last;

  //7
  return7:
    bitSet(leds, SEG_A);
    bitSet(leds, SEG_B);
    bitSet(leds, SEG_C);
    updateShiftRegister();
  
  goto last;

  //8
  return8:
    bitSet(leds, SEG_A);
    bitSet(leds, SEG_B);
    bitSet(leds, SEG_C);
    bitSet(leds, SEG_D);
    bitSet(leds, SEG_E);
    bitSet(leds, SEG_F);
    bitSet(leds, SEG_G);
    updateShiftRegister();
  
  goto last;

  //9
  return9:
    bitSet(leds, SEG_A);
    bitSet(leds, SEG_B);
    bitSet(leds, SEG_C);
    bitSet(leds, SEG_D);
    bitSet(leds, SEG_F);
    bitSet(leds, SEG_G);
    updateShiftRegister();
  
  goto last;

  last:

    delay(0);
}


// set digits LOW to light the LED because it's negative
void setDigit(int n) {
  digitalWrite(DIG_1, HIGH);
  digitalWrite(DIG_2, HIGH);
  digitalWrite(DIG_3, HIGH);
  digitalWrite(DIG_4, HIGH);
  if ( n == 1 ) {
    digitalWrite(DIG_1, LOW);
  }
  else if ( n == 2 ) {
    digitalWrite(DIG_2, LOW);
  }
  else if ( n == 3 ) {
    digitalWrite(DIG_3, LOW);
  }
  else if ( n == 4 ) {
    digitalWrite(DIG_4, LOW);
  }
}
