/*
 * atmega8.h
 *
 *  Created on: 05 окт. 2015 г.
 *      Author: OmeZ
 */

#ifndef PLATFORM_ATMEGA8_H_
#define PLATFORM_ATMEGA8_H_

#include <avr/io.h>
#include "../lib/io.h"

// Ports definition
MAKE_PORT(PORTA, DDRA, PINA, PortA, "A")
MAKE_PORT(PORTB, DDRB, PINB, PortB, "B")
MAKE_PORT(PORTC, DDRC, PINC, PortC, "C")
MAKE_PORT(PORTD, DDRD, PIND, PortD, "D")

// pin configuration
typedef PortPin<PortA, 0> PortA0;
typedef PortPin<PortA, 1> PortA1;
typedef PortPin<PortA, 2> PortA2;
typedef PortPin<PortA, 3> PortA3;
typedef PortPin<PortA, 4> PortA4;
typedef PortPin<PortA, 5> PortA5;
typedef PortPin<PortA, 6> PortA6;
typedef PortPin<PortA, 7> PortA7;
typedef PortPin<PortA, 8> PortA8;

typedef PortPin<PortB, 0> PortB0;
typedef PortPin<PortB, 1> PortB1;
typedef PortPin<PortB, 2> PortB2;
typedef PortPin<PortB, 3> PortB3;
typedef PortPin<PortB, 4> PortB4;
typedef PortPin<PortB, 5> PortB5;
typedef PortPin<PortB, 6> PortB6;
typedef PortPin<PortB, 7> PortB7;
typedef PortPin<PortB, 8> PortB8;

typedef PortPin<PortC, 0> PortC0;
typedef PortPin<PortC, 1> PortC1;
typedef PortPin<PortC, 2> PortC2;
typedef PortPin<PortC, 3> PortC3;
typedef PortPin<PortC, 4> PortC4;
typedef PortPin<PortC, 5> PortC5;
typedef PortPin<PortC, 6> PortC6;
typedef PortPin<PortC, 7> PortC7;
typedef PortPin<PortC, 8> PortC8;

typedef PortPin<PortD, 0> PortD0;
typedef PortPin<PortD, 1> PortD1;
typedef PortPin<PortD, 2> PortD2;
typedef PortPin<PortD, 3> PortD3;
typedef PortPin<PortD, 4> PortD4;
typedef PortPin<PortD, 5> PortD5;
typedef PortPin<PortD, 6> PortD6;
typedef PortPin<PortD, 7> PortD7;
typedef PortPin<PortD, 8> PortD8;


#endif /* PLATFORM_ATMEGA8_H_ */
