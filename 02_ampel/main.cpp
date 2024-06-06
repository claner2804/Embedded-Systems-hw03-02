
#include <Arduino.h>
#include "ampel.h"

Ampel ampel;

void setup() {
	Serial.begin(115200);
	ampel.begin();
}

void loop() {
	ampel.loop();
}


