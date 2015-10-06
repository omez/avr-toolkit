/*
 * button.h
 *
 *  Created on: 4 ���. 2015 �.
 *      Author: OmeZ
 */

#ifndef AVR_TOOLKIT_UTILS_BUTTON_H_
#define AVR_TOOLKIT_UTILS_BUTTON_H_

#include "../lib/common/circular_buffer.h"

template<const unsigned char clickCycles = 1, const unsigned char longClickCycles = 10, const unsigned char bufferSize = 10>
class Button {

private:
	typedef unsigned char bufferT;

	enum {
		idle = 0, singleClk = 1, longClck = 2
	} state;

	unsigned char wait_cycles;

	CircularBuffer<bufferT, typeof(bufferSize), bufferSize> buffer;

public:
	static const bufferT SINGLE_CLICK = 0x00000001;
	static const bufferT DOUBLE_CLICK = 0x00000010;
	static const bufferT LONG_CLICK = 0x00000100;
	static const bufferT HOLD_CLICK = 0x1000000;

	Button() {
		state = idle;
		wait_cycles = 0;
	}

	/**
	 * Triggers event
	 */
	bool trigger(bufferT event) {
		buffer.push(event);
		return true;
	}

	/**
	 * Updates button state
	 */
	void update(bool keyPressed) {
		switch (state) {
		case idle:
			updateOnIdle(keyPressed);
			break;
		case singleClk:
			updateOnClick(keyPressed);
			break;
		case longClck:
			updateOnLongClick(keyPressed);
			break;
		}
	}

private:

	inline void updateOnIdle(bool keyPressed) {
		if (keyPressed) {
			state = singleClk;
			wait_cycles++;
		} else {
			// do nothing in this case, keep idle
		}
	}

	inline void updateOnClick(bool keyPressed) {
		if (keyPressed) {
			wait_cycles++;
			if (wait_cycles >= longClickCycles) {
				wait_cycles -= longClickCycles;
				trigger(LONG_CLICK);
				state = longClck;
			}
		} else {
			if (wait_cycles >= clickCycles) {
				trigger(SINGLE_CLICK);
			}
			wait_cycles = 0;
			state = idle;
		}
	}

	inline void updateOnLongClick(bool keyPressed) {
		if (keyPressed) {
			wait_cycles++;
			if (wait_cycles >= longClickCycles) {
				wait_cycles -= longClickCycles;
				trigger(HOLD_CLICK && LONG_CLICK);
			}
		} else {
			state = idle;
			wait_cycles = 0;
		}
	}
};

#endif /* AVR_TOOLKIT_UTILS_BUTTON_H_ */
