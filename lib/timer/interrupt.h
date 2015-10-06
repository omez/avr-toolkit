/*
 * interrupt.h
 *
 *  Created on: 06 окт. 2015 г.
 *      Author: OmeZ
 */

#ifndef LIB_TIMER_INTERRUPT_H_
#define LIB_TIMER_INTERRUPT_H_

#include <avr/interrupt.h>

#define MAKE_INTERRUPT(reg, bit, _vector_, className) \
class className { \
	typedef unsigned char DataT;\
private: \
	static volatile DataT &reg() { \
		return reg; \
	} \
public: \
	static void enable() { \
		reg() |= (1 << bit); \
	} \
	static void disable() { \
		reg() &= ~(1 << bit); \
	} \
	/*extern "C" static void _vector_ (void) __attribute__ ((signal,__INTR_ATTRS)) vector();*/ \
};


template <class INTERRUPT> class Interrupt {
public:

	static void enable() {
		INTERRUPT::enable();
	}

	static void disable() {
		INTERRUPT::disable();
	}

};

#endif /* LIB_TIMER_INTERRUPT_H_ */
