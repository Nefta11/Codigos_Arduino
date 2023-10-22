int pinA = 13;
int pinB = 12;
int pinC = 11;
int pinD = 10;
int pinE = 9;
int pinF = 8;
int pinG = 7;
int i = 0;
int j = 0;
int Arduino_Pins[7] = {pinA, pinB, pinC, pinD, pinE, pinF, pinG};
int Segment_Pins[10][7] = {{1, 1, 1, 1, 1, 1, 0}, // 0
                           {0, 1, 1, 0, 0, 0, 0}, // 1
                           {1, 1, 0, 1, 1, 0, 1}, // 2
                           {1, 1, 1, 1, 0, 0, 1}, // 3
                           {0, 1, 1, 0, 0, 1, 1}, // 4
                           {1, 0, 1, 1, 0, 1, 1}, // 5
                           {1, 0, 1, 1, 1, 1, 1}, // 6
                           {1, 1, 1, 0, 0, 0, 0}, // 7
                           {1, 1, 1, 1, 1, 1, 1}, // 8
                           {1, 1, 1, 1, 0, 1, 1}, // 9
};

int buttonPin1 = 1; // New button on digital pin 1
int buttonPin2 = 2; // Original button on digital pin 2

void setup() {
  // Set segment pins as OUTPUT
  for (j = 0; j < 7; j++) {
    pinMode(Arduino_Pins[j], OUTPUT);
  }

  // Set button pins as INPUT_PULLUP
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
}

void loop() {
  // Check if button 1 is pressed (change from 9 to 0)
  if (digitalRead(buttonPin1) == LOW) {
    while (digitalRead(buttonPin1) == LOW) {
    }
    i--; // Decrease i
  }

  // Check if button 2 is pressed (change from 0 to 9)
  if (digitalRead(buttonPin2) == LOW) {
    while (digitalRead(buttonPin2) == LOW) {
    }
    i++; // Increase i
  }

  // Ensure i is within the range of 0 to 9
  if (i < 0) {
    i = 9;
  }
  if (i > 9) {
    i = 0;
  }

  // Display the current digit
  for (j = 0; j < 7; j++) {
    digitalWrite(Arduino_Pins[j], Segment_Pins[i][j]);
  }

  delay(100);
}
