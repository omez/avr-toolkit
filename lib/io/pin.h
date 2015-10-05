/*
 * pin.h
 *
 *  Created on: 05 окт. 2015 г.
 *      Author: OmeZ
 */

#ifndef LIB_IO_PIN_H_
#define LIB_IO_PIN_H_

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
	static unsigned char isSet() {
		return PORT::pinRead() & (unsigned char) (1 << PIN);
	}
};


#endif /* LIB_IO_PIN_H_ */
