#include "09_task_0203_button.h"

Button::Button (uint8_t pin) {
	currentState_ = 0;
    lastState_ = 0;
    pin_ = pin;
    pinMode(pin_, INPUT_PULLUP);
}

void Button::scanState() {
    lastState_ = currentState_;
    if (currentState_ != !digitalRead(pin_)) {
      delay(2);
      currentState_ = !digitalRead (pin_);
    }
    return currentState_;
}