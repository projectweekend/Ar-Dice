#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"


Adafruit_8x8matrix die1 = Adafruit_8x8matrix();
Adafruit_8x8matrix die2 = Adafruit_8x8matrix();

int PIN_FOR_DIE_1 = 7;
int PIN_FOR_DIE_2 = 8;


void setup() {

    randomSeed(analogRead(5));

    pinMode(PIN_FOR_DIE_1, INPUT_PULLUP);
    pinMode(PIN_FOR_DIE_2, INPUT_PULLUP);

    die1.begin(0x70);
    die2.begin(0x71);

    die1.clear();
    die2.clear();

}


void loop() {

    int pin1 = digitalRead(PIN_FOR_DIE_1);
    int pin2 = digitalRead(PIN_FOR_DIE_2);

    if (pin1 == LOW) {
        rollDie(die1);
    }

    if (pin2 == LOW) {
        rollDie(die2);
    }

}


void rollDie(Adafruit_8x8matrix die) {

    delay(100);

    for (int i=0; i<20; i++) {
        die.setTextSize(1);
        die.clear();
        die.setTextColor(LED_ON);
        die.setCursor(2,0);
        die.print(random(1, 7));
        die.writeDisplay();
        delay(50);
    }

}
