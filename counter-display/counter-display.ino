/*
  7-Segment Display (Single) Countdown

  10 seconds countdown. When reach 0, it will alarm.

  Materials:
  1. Arduino UNO
  2. 7-Segment Display
  3. Passive buzzer
  4. breadboard and jumper wires

  DIAGRAM of the 7SD
   --
  |  |
   --
  |  |
   --  
  
  These are the pins I used:
  
     12
  11    13
     10 
  02    04
     03

*/

bool toggle = false;
int segments[] = {2, 3, 4, 5, 10, 11, 12, 13};
int cntr = 9;

int len = 0;
int N0[] = {2, 3, 4, 11, 12, 13};
int N1[] = {4, 13};
int N2[] = {12, 13, 10, 2, 3};
int N3[] = {12, 13, 10, 4, 3};
int N4[] = {11, 10, 13, 4};
int N5[] = {12, 11, 10, 4, 3};
int N6[] = {12, 11, 2, 3, 4, 10};
int N7[] = {12, 13, 4};
int N8[] = {11, 12, 13, 10, 2, 3, 4};
int N9[] = {12, 11, 10, 13, 4, 3};

int* arr[] = {N0, N1, N2};

const int MY_LED = 8;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(segments[i], OUTPUT);
    digitalWrite(segments[i], LOW);
  }
  
  pinMode(MY_LED, OUTPUT);
  digitalWrite(MY_LED, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
//  toggle = !toggle;
  
//  for (int i = 0; i < 8; i++) {
//    if (toggle == 1) {
//      digitalWrite(segments[i], HIGH);
//    } else {
//      digitalWrite(segments[i], LOW);
//    }
//  }

  
  
//  if (cntr >= 10) {
//    cntr = 0;
//    toggle = !toggle;
//  }
  if (cntr < 0) {
    cntr = 9;
    toggle = !toggle;
  }

//  if (toggle) {
//    digitalWrite(MY_LED, 1);
//  } else {
//    digitalWrite(MY_LED, LOW);
//  }
  
  for (int i = 0; i < 8; i++) {
    digitalWrite(segments[i], LOW);
  }
  
  
  if (cntr == 0) {
    len =  (sizeof(N0) / sizeof(N0[0]));
    for (int i = 0; i < len; i++) {
        digitalWrite(N0[i], HIGH);
    }
  }
  else if (cntr == 1) {
    len =  (sizeof(N1) / sizeof(N1[0]));
    for (int i = 0; i < len; i++) {
        digitalWrite(N1[i], HIGH);
    }
  }
  else if (cntr == 2) {
    len =  (sizeof(N2) / sizeof(N2[0]));
    for (int i = 0; i < len; i++) {
        digitalWrite(N2[i], HIGH);
    }
  }
  else if (cntr == 3) {
    len =  (sizeof(N3) / sizeof(N3[0]));
    for (int i = 0; i < len; i++) {
        digitalWrite(N3[i], HIGH);
    }
  }
  else if (cntr == 4) {
    len =  (sizeof(N4) / sizeof(N4[0]));
    for (int i = 0; i < len; i++) {
        digitalWrite(N4[i], HIGH);
    }
  }
  else if (cntr == 5) {
    len =  (sizeof(N5) / sizeof(N5[0]));
    for (int i = 0; i < len; i++) {
        digitalWrite(N5[i], HIGH);
    }
  }
  else if (cntr == 6) {
    len =  (sizeof(N6) / sizeof(N6[0]));
    for (int i = 0; i < len; i++) {
        digitalWrite(N6[i], HIGH);
    }
  }
  else if (cntr == 7) {
    len =  (sizeof(N7) / sizeof(N7[0]));
    for (int i = 0; i < len; i++) {
        digitalWrite(N7[i], HIGH);
    }
  }
  else if (cntr == 8) {
    len =  (sizeof(N8) / sizeof(N8[0]));
    for (int i = 0; i < len; i++) {
        digitalWrite(N8[i], HIGH);
    }
  }
  else if (cntr == 9) {
    len =  (sizeof(N9) / sizeof(N9[0]));
    for (int i = 0; i < len; i++) {
        digitalWrite(N9[i], HIGH);
    }
  }


  cntr --;
  
//  digitalWrite(MY_LED, LOW);
  if (cntr < 0) {
//    digitalWrite(MY_LED, HIGH);
    for (int i = 0; i < 10; i++) {
      tone(MY_LED, 1000 - ( i * 10 ));
      delay(100);
    }
  } else {
    noTone(MY_LED);
    delay(1000);
  }
  
}
