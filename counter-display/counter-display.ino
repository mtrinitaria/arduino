
// all segements
int segments[] = {2, 3, 4, 5, 10, 11, 12, 13};
// counter starts at 9 decrementing
int cntr = 9;

int len = 0;
// number variable with set of PINS.
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

const int BUZZER = 8;

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
  if (cntr < 0) {
    cntr = 9;
  }

  //  clear all led
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
  
  //  buzz and delay
  if (cntr < 0) {
    for (int i = 0; i < 10; i++) {
      tone(MY_LED, 1000 - ( i * 10 ));
      delay(100);
    }
  } else {
    noTone(MY_LED);
    delay(1000);
  }
  
}
