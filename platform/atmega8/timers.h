/*
 * timer.h
 *
 *  Created on: 06 окт. 2015 г.
 *      Author: OmeZ
 */

#ifndef PLATFORM_ATMEGA8_TIMERS_H_
#define PLATFORM_ATMEGA8_TIMERS_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#include "../../lib/timer/interrupt.h"


class Timer0OverflowInterrupt {
public:
	static void enable() {
		TIMSK |= (1 << TOIE0);
	}

	static void disable() {
		TIMSK &= (0 << TOIE0);
	}
};

class Timer0CompAInterrupt {
public:
	static void enable() {
		TIMSK |= (1 << TOIE0);
	}

	static void disable() {
		TIMSK &= (0 << TOIE0);
	}
};


class Timer0 {

public:

	typedef Interrupt<Timer0OverflowInterrupt> overflowInterrupt;
	typedef Interrupt<Timer0OverflowInterrupt> overflowInterrupt1;

};

#endif /* PLATFORM_ATMEGA8_TIMERS_H_ */
