#include "09_task_0203_led_rgb.h"

LedRgb::LedRgb (uint8_t pinR, uint8_t pinG, uint8_t pinB) {
	pinR_ = pinR;
    pinG_ = pinG;
    pinB_ = pinB;

    brightR_ = 0;
    brightG_ = 0;
    brightB_ = 0;
      
    pinMode(pinR_, OUTPUT);
    pinMode(pinG_, OUTPUT);
    pinMode(pinB_, OUTPUT);
}

uint8_t LedRgb::checkBright (uint8_t& bright, int8_t diff) {
    if (diff < 0) {
      if (bright == 0) {
        bright = 0;
      } else {
        bright = bright + diff;
      }
    }

    if (diff > 0) {
      if (bright == 250) {
        bright = 250;
      } else {
        bright = bright + diff;
      }
    }
    return bright;
}

void LedRgb::setColorR (int8_t diff) {
    brightR_ = checkBright(brightR_, diff);
    analogWrite(pinR_, brightR_);
}

void LedRgb::setColorG (int8_t diff) {
    brightG_ = checkBright(brightG_, diff);
    analogWrite(pinG_, brightG_);
}

void LedRgb::setColorB (int8_t diff) {
    brightB_ = checkBright(brightB_, diff);
    analogWrite(pinB_, brightB_);
}