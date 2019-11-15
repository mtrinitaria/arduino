

int latchPin = 2; //pin 12 on the 595
int dataPin = 3; //pin 14 on the 595
int clockPin = 4; //pin 11 on the 595
int num = 0;
int KEY_1 = 8;
int BUZZ = 9;
int enable = true;


void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  pinMode(KEY_1, INPUT);
  pinMode(BUZZ, OUTPUT);
}
void loop() {
  if (digitalRead(KEY_1) == 1 && enable) {
    Serial.println("hello");
    digitalWrite(BUZZ, HIGH);
    delay(500);
    digitalWrite(BUZZ, LOW);
    num = 0;
    enable = false;
  }
  if (num >= 10) {
    num = 0;
  }
  displayNumber(num);

  num++;

}
void displayNumber(int n) {
//  Serial.println(n);
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
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 63);
  digitalWrite(latchPin, HIGH);

  goto last;

  //1
  return1:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 6);
  digitalWrite(latchPin, HIGH);
  
  goto last;

  //2
  return2:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 91);
  digitalWrite(latchPin, HIGH);
  
  goto last;

  //3
  return3:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 79);
  digitalWrite(latchPin, HIGH);
  
  goto last;

  //4
  return4:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 102);
  digitalWrite(latchPin, HIGH);
  
  goto last;

  //5
  return5:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 109);
  digitalWrite(latchPin, HIGH);
  
  goto last;

  //6
  return6:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 125);
  digitalWrite(latchPin, HIGH);
  
  goto last;

  //7
  return7:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 7);
  digitalWrite(latchPin, HIGH);
  
  goto last;

  //8
  return8:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 127);
  digitalWrite(latchPin, HIGH);
  
  goto last;

  //9
  return9:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 111);
  digitalWrite(latchPin, HIGH);
  
  goto last;

  last:

  delay(1000);
}
