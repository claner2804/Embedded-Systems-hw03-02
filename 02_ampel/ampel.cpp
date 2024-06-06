
#include "ampel.h"

Ampel::Ampel()
	: js(JS_X_PIN, JS_Y_PIN, 0),
	  rgb(1, RGB_LED_PIN, NEO_GRB + NEO_KHZ800) {}

void Ampel::begin() {
	js.begin();
	rgb.begin();
	pinMode(PIR_PIN, INPUT);
}

void Ampel::loop() {

	auto now = millis();
	js.update();
	bool buttonPressed = false;
	if (js.getButton() && !lastButtonState) {
		buttonPressed = true;
		lastButtonState = true;
	} else if (!js.getButton()) {
		lastButtonState = false;
	}
	bool pir_state = false;
	if (digitalRead(PIR_PIN) && !lastPIRState) {
		pir_state = true;
		lastPIRState = true;
	} else if (!digitalRead(PIR_PIN)) {
		lastPIRState = false;
	}
	auto brightness = analogRead(BRIGHTNESS_PIN);

	if (brightness < 300) {
		if (ampelEnabled) {
			ampelEnabled = false;
			nextBlinkTime = 0;
			lastBlinkState = false;
		}
	} else {
		if (!ampelEnabled) {
			state = 0;
			stateChanged = true;
			ampelEnabled = true;
		}
	}

	if (ampelEnabled) {
		switch (state) {
			// Rotphase
			case 0: {
				if (stateChanged) {
					rgb.setPixelColor(0, 200, 0, 0);
					rgb.show();
					stateChanged = false;
					nextStateChangeTime = now + 7000;
				} else if (now >= nextStateChangeTime || buttonPressed) {
					state = 1;
					stateChanged = true;
				}
				if (pir_state) {
					nextStateChangeTime += 5000;
				}
			} break;
			// Gelbphase 1
			case 1: {
				if (stateChanged) {
					rgb.setPixelColor(0, 200, 200, 0);
					rgb.show();
					stateChanged = false;
					nextStateChangeTime = now + 3000;
				} if (now >= nextStateChangeTime) {
					state = 2;
					stateChanged = true;
				}
			} break;
			// Grünphase
			case 2: {
				if (stateChanged) {
					rgb.setPixelColor(0, 0, 200, 0);
					rgb.show();
					stateChanged = false;
					nextStateChangeTime = now + 5000;
				} else if (now >= nextStateChangeTime) {
					state = 3;
					stateChanged = true;
				}
				if (buttonPressed) {
					nextStateChangeTime += 5000;
				} else if (pir_state) {
					state = 4;
					stateChanged = true;
				}
			} break;
			// Grün Blinkend
			case 3: {
				if (stateChanged) {
					stateChanged = false;
					nextStateChangeTime = now + 2000;
				} else if (now >= nextStateChangeTime) {
					state = 4;
					stateChanged = true;
				}
				if (now >= nextBlinkTime) {
					nextBlinkTime = now + 500;
					if (lastBlinkState) {
						rgb.setPixelColor(0, 0, 0, 0);
						rgb.show();
						lastBlinkState = false;
					} else {
						rgb.setPixelColor(0, 0, 200, 0);
						rgb.show();
						lastBlinkState = true;
					}
				}
			} break;
			// Gelbphase 2
			case 4: {
				if (stateChanged) {
					rgb.setPixelColor(0, 200, 200, 0);
					rgb.show();
					stateChanged = false;
					nextStateChangeTime = now + 3000;
				} if (now >= nextStateChangeTime) {
					state = 0;
					stateChanged = true;
				}
			} break;
			default:
				break;
		}
	} else {
		if (now >= nextBlinkTime) {
			nextBlinkTime = now + 500;
			if (lastBlinkState) {
				rgb.setPixelColor(0, 0, 0, 0);
				rgb.show();
				lastBlinkState = false;
			} else {
				rgb.setPixelColor(0, 200, 200, 0);
				rgb.show();
				lastBlinkState = true;
			}
		}
	}

}
