/*
 * pinbutton.h
 *
 *  Created on: 06 окт. 2015 г.
 *      Author: OmeZ
 */

#ifndef AVR_TOOLKIT_UTILS_PINBUTTON_H_
#define AVR_TOOLKIT_UTILS_PINBUTTON_H_

#include "../lib/io/pin.h"
#include "button.h"

template <class Pin>
class PinButton : Button<> {

public:
	void update() {
		Button::update(Pin::isset());
	}

};

#endif /* AVR_TOOLKIT_UTILS_PINBUTTON_H_ */
