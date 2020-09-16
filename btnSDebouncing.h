/*
 * Author: Leonardo Padilha Guarezi
 * Github: https://github.com/lpg2709
 *   repository: https://github.com/lpg2709/btnSDebouncing
 *
 * Simple software deboucing lib for Arduino and esp32
 *
 * How use:
 *   #define BTNSDEBOUCINH_H
 *   #include "btnSDebouncing.h"
 *
 */
#ifdef BTNSDEBOUCINH_H

typedef struct stc_btn{
   int pin;
   int state;
   int lastState;
   unsigned long lastDebounceTime;
}Button;

/*! @brief button reading without bouncing
 *  @param [Button] *btn - The adress of the button data
 *  @param [unsigned long] debounceDelay - The delay of the boucing, if pass NULL the default is 50 ms
 *  @return bool
 */
bool readDButton(Button *btn, unsigned long debounceDelay){
  if(debounceDelay == NULL)
    debounceDelay = 50;

  int reading = digitalRead(btn->pin);

  if (reading != btn->lastState) {
    btn->lastDebounceTime = millis();
  }

  if ((millis() - btn->lastDebounceTime) > debounceDelay) {
    if (reading != btn->state) {
      btn->state = reading;

      if (btn->state == HIGH) {
        btn->lastState = reading;
        return true;
      }
    }
  }

  btn->lastState = reading;
  return false;
}

#endif // BTNSDEBOUCINH_H

