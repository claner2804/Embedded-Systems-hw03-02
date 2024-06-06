
#ifndef AMPEL_H_
#define AMPEL_H_

#include "JoystickHigh.h"
#include <Adafruit_NeoPixel.h>


#define BRIGHTNESS_PIN	A2
#define PIR_PIN			5
#define RGB_LED_PIN 	A4
#define JS_X_PIN		A0
#define JS_Y_PIN		A1


class Ampel {
public:
	Ampel();

	void begin();
	void loop();

private:
	JoystickHigh js;
	Adafruit_NeoPixel rgb;
	uint8_t state = 0;
	uint32_t nextStateChangeTime = 0;
	bool stateChanged = true;
	bool lastButtonState = false;
	bool lastPIRState = false;
	bool lastBlinkState = false;
	uint32_t nextBlinkTime = 0;
	bool ampelEnabled = true;

};

#endif /* AMPEL_H_ */
