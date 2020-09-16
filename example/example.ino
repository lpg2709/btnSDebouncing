#define BTNSDEBOUCINH_H
#include "btnSDebouncing.h"

const int ledPin = 25;
int ledState = HIGH;

Button _btn0 = {35, LOW, LOW, 0};
Button _btn1 = {34, LOW, LOW, 0};

void setup() {
  pinMode(_btn0.pin, INPUT);
  pinMode(_btn1.pin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {
  if(readDButton(&_btn0, NULL)){
    ledState = !ledState;
  }
  if(readDButton(&_btn1, NULL)){
    ledState = !ledState;
  }
  digitalWrite(ledPin, ledState);
}
