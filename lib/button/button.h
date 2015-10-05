/*
 * button.h
 *
 *  Created on: 4 окт. 2015 г.
 *      Author: OmeZ
 */

#ifndef AVR_TOOLKIT_BUTTON_BUTTON_H_
#define AVR_TOOLKIT_BUTTON_BUTTON_H_

#include "../utils/circular_buffer.h"


template<unsigned int bufferSize, typename cycleCounterType,
		unsigned int clickPressCycles, unsigned int longClickPressCycles>
class Button {

private:
	typedef unsigned char bufferT;
	CircularBuffer<bufferT, bufferSize> buffer;
	enum buttonState {
		idle = 0, singleClk = 1, longClck = 2
	} state;

	cycleCounterType press_cycles;

public:
	static const bufferT SINGLE_CLICK = 1;
	static const bufferT DOUBLE_CLICK = 2;
	static const bufferT LONG_CLICK = 3;

	bufferT currentState;

	enum clickState {
		keyUp = 1, keyDown = 0
	};

	Button() {
		state = idle;
		press_cycles = 0;
		currentState = 0;
	}

	bool trigger(bufferT click) {
		currentState = click;
		return true;
		//return this->buffer.push(click);
	}

	bool hasEvents() {
		return !this->buffer.empty();
	}

	bufferT getEvent() {
		return buffer.shift();
	}

	void update(clickState st) {
		switch (state) {
		case idle:
			onIdle(st);
			break;
		case singleClk:
			onSingleClick(st);
			break;
		case longClck:
			onLongClick(st);
			break;
		}
	}

private:

	void onIdle(clickState st) {
		switch (st) {
		case keyDown:
			state = singleClk;
			press_cycles++;
			break;
		case keyUp:
			// do nothing in this case, keep idle
			break;
		}
	}

	void onSingleClick(clickState st) {
		switch (st) {
		case keyDown:
			press_cycles++;
			if (press_cycles >= longClickPressCycles) {
				state = longClck;
				press_cycles -= longClickPressCycles;
				trigger(LONG_CLICK);
			}
			break;
		case keyUp:
			if (press_cycles > clickPressCycles) {
				trigger(SINGLE_CLICK);
			}
			press_cycles = 0;
			state = idle;
		}
	}

	void onLongClick(clickState st) {
		switch (st) {
		case keyDown:
			press_cycles++;
			if (press_cycles >= longClickPressCycles) {
				press_cycles -= longClickPressCycles;
				trigger(LONG_CLICK);
			}
			break;

		case keyUp:
			state = idle;
			press_cycles = 0;
			break;
		}
	}

};

#endif /* AVR_TOOLKIT_BUTTON_BUTTON_H_ */
