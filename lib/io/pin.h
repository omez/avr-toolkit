/*
 * pin.h
 *
 *  Created on: 05 окт. 2015 г.
 *      Author: OmeZ
 */

#ifndef AVR_TOOLKIT_LIB_IO_PIN_H_
#define AVR_TOOLKIT_LIB_IO_PIN_H_

#define AVR_TOOLKIT_MAKE_PIN(port, index) typedef PortPin<port, 0> port##index;

/**
 * PortPin template class
 */
template<class PORT, unsigned char PIN> class PortPin {
public:
	typedef PORT Port;
	enum {
		Number = PIN
	};
	static void set() {
		PORT::set(1 << PIN);
	}
	static void set(unsigned char val) {
		if (val) {
			set();
		} else {
			clear();
		}
	}
	static void setDir(unsigned char val) {
		if (val) {
			setDirWrite();
		} else {
			setDirRead();
		}
	}
	static void clear() {
		PORT::clear(1 << PIN);
	}
	static void toggle() {
		PORT::toggle(1 << PIN);
	}
	static void setDirRead() {
		PORT::dirClear(1 << PIN);
	}
	static void setDirWrite() {
		PORT::dirSet(1 << PIN);
	}
	static bool isset() {
		return PORT::pinRead() & (unsigned char) (1 << PIN);
	}
};

/**
 * Inversed pin implementation
 *
 */
template<class PORT, unsigned char PIN>
class PortPinInversed : PortPin<PORT, PIN> {

public:
	static void clear() {
		PortPin<PORT, PIN>::set();
	}

	static void set() {
		PortPin<PORT, PIN>::clear();
	}

	static bool isset() {
		return !PortPin<PORT, PIN>::isset();
	}
};

#endif /* LIB_IO_PIN_H_ */
