#include "headers/ioControl.h"

int currentBrightness = 0;
long lastReq = 10000;
int lastReturn;
int lastCounter;
int lastmvolts;

/*
  Initialize various GPIOs, should be done at bootup
*/
void initIO() {
  pinMode(GREEN_LEDS, OUTPUT);
  pinMode(VIBRATOR_OUT, OUTPUT);
  pinMode(PUSH_BUTTON_IN, INPUT);
  pinMode(LCD_BACKLIGHT_LOW, OUTPUT);
  pinMode(LCD_BACKLIGHT_MID, OUTPUT);
  pinMode(LCD_BACKLIGHT_HIGH, OUTPUT);
  ledOutput(false);
  motorOutput(false);
  //Disable flash
  pinMode(SPI_CE, OUTPUT);
  digitalWrite(SPI_CE, HIGH);

  //From battery.h
  pinMode(CHARGE_INDICATION, INPUT);
  pinMode(POWER_INDICATION, INPUT);
  pinMode(POWER_CONTROL, OUTPUT);
  digitalWrite(POWER_CONTROL, HIGH);

  setBrightness(3);
}

/*
  Get state of push button
  Returns true if button is pressed
  Will probably not need to be used when interrupts are fully implemented
*/
bool getButtonState() {
  return digitalRead(PUSH_BUTTON_IN);
}

/*
  Turn the status LED on or off (LED on the heartrate sensor board)
*/
void ledOutput(bool on) {
  digitalWrite(GREEN_LEDS, on);
}

/*
  Turn the vibration motor on or off
*/
void motorOutput(bool on) {
  digitalWrite(VIBRATOR_OUT, !on);
}

/*
  Set the backlight brightness between 0b000 (low) and 0b111 or 7 (high)
  Since the backlight pins are active low, we must first invert the brightness
  Then we get the value of each bit by shifting it accordingly
  Finally we write that value to the output pin
  For example: brightness = 4 (100)
  Invert = 011
  Shifting yields: LOW = 1, MID = 1, HIGH = 0
*/
void setBrightness(int brightness) {
  if (brightness >= 0 && brightness <= 7) {  //Make sure the brightness is in the correct range
    if (brightness > 0)
      currentBrightness = brightness;
    digitalWrite(LCD_BACKLIGHT_LOW, !(brightness & 1));
    digitalWrite(LCD_BACKLIGHT_MID, !((brightness >> 1) & 1));
    digitalWrite(LCD_BACKLIGHT_HIGH, !((brightness >> 2) & 1));
  }
}

/*
  Get current brightness
*/
int getBrightness() {
  return currentBrightness;
}

/*
  Increment brightness
*/
void incBrightness() {
  if (getBrightness() < 7) {
    setBrightness(getBrightness() + 1);
  }
}

/*
  Decrement brightness
*/
void decBrightness() {
  if (getBrightness() > 0) {
    setBrightness(getBrightness() - 1);
  }
}

/* 
Quickly flash green LEDs for debugging */
void ledPing() {
  digitalWrite(GREEN_LEDS, HIGH);
  delay(5);
  digitalWrite(GREEN_LEDS, LOW);
}

int getBatteryPercent(){
  lastmvolts += map(get_battery_raw(), 496, 696, 3000, 4200);
  lastCounter++;
  if (millis() - lastReq > 10000) {
    lastReq = millis();
    lastReturn =  milliVoltToPercent(lastmvolts / lastCounter);
    lastCounter = 0;
    lastmvolts = 0;
    return lastReturn;
  }
  return lastReturn;
}

int milliVoltToPercent(float mvolts) {
  if ( mvolts >= 4145 ) return 99;
  else if ( mvolts > 4010 ) return (99 - (int16_t)(4145 - mvolts) / 13);
  else if ( mvolts > 3920 ) return (90 - (int16_t)(4010 - mvolts) / 9);
  else if ( mvolts > 3850 ) return (80 - (int16_t)(3920 - mvolts) / 7);
  else if ( mvolts > 3789 ) return (70 - (int16_t)(3850 - mvolts) / 6);
  else if ( mvolts > 3740 ) return (60 - (int16_t)(3789 - mvolts) / 4);
  else if ( mvolts > 3703 ) return (50 - (int16_t)(3740 - mvolts) / 3);
  else if ( mvolts > 3676 ) return (40 - (int16_t)(3703 - mvolts) / 2);
  else if ( mvolts > 3648 ) return (30 - (int16_t)(3676 - mvolts) / 2);
  else if ( mvolts > 3609 ) return (20 - (int16_t)(3648 - mvolts) / 3);
  else if ( mvolts > 3575 ) return (10 - (int16_t)(3609 - mvolts) / 6);
  else if ( mvolts > 3482 ) return ( 5 - (int16_t)(3575 - mvolts) / 18);
  else return 0;
}

float get_battery() {
  return map(get_battery_raw(), 496, 696, 3000, 4200) / 1000.0;
}

int get_battery_raw() {
  return analogRead(BATTERY_VOLTAGE);
}