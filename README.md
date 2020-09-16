# btnSDebouncing.h

btnSDebouncing.h is a header only lib that implements simple software debouncing for push buttons.

## How use:

In your file where a button will be used:

```c
    #define BTNSDEBOUCINH_H
    #include "btnSDebouncing.h"
```

## What's in the lib

A button data type and a function to read the button.

### Button: type[struct]

Structure containing button data, where:

- int pin: The board pin where the button is connected
- int state: The state of the button, ```HIGH``` or ```LOW```
- int lastState: The last state of the button, ```HIGH``` or ```LOW```
- unsigned long lastDebounceTime: The last time of  the boucing, initialize with ```0```;

### readDButton: type[function]

Function that performs button reading without bouncing

```c
/*! @brief button reading without bouncing
 *  @param [Button] *btn - The adress of the button data
 *  @param [unsigned long] debounceDelay - The delay of the boucing, if pass NULL the default is 50 ms
 *  @return bool
 */
bool readDButton(Button *btn, unsigned long debounceDelay);
```

if the button is presses, return ```true```
