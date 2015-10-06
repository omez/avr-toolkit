/*
 * port.h
 *
 *  Created on: 05 окт. 2015 г.
 *      Author: OmeZ
 */

#ifndef AVR_TOOLKIT_LIB_IO_PORT_H_
#define AVR_TOOLKIT_LIB_IO_PORT_H_

/**
 * Makes port definition
 */
#define AVR_TOOLKIT_MAKE_PORT(portName, ddrName, pinName, className, ID) \
class className{\
public:\
	typedef unsigned char DataT;\
private:\
	static volatile DataT &data()\
	{\
		return portName;\
	}\
	static volatile DataT &dir()\
	{\
		return ddrName;\
	}\
	static volatile DataT &pin()\
	{\
		return pinName;\
	}\
public:\
	static void write(DataT value)\
	{\
		data() = value;\
	}\
	static void clearAndSet(DataT clearMask, DataT value)\
	{\
		data() = (data() & ~clearMask) | value;\
	}\
	static DataT read()\
	{\
		return data();\
	}\
	static void dirWrite(DataT value)\
	{\
		dir() = value;\
	}\
	static DataT dirRead()\
	{\
		return dir();\
	}\
	static void set(DataT value)\
	{\
		data() |= value;\
	}\
	static void clear(DataT value)\
	{\
		data() &= ~value;\
	}\
	static void toggle(DataT value)\
	{\
		data() ^= value;\
	}\
	static void dirSet(DataT value)\
	{\
		dir() |= value;\
	}\
	static void dirClear(DataT value)\
	{\
		dir() &= ~value;\
	}\
	static void dirToggle(DataT value)\
	{\
		dir() ^= value;\
	}\
	static DataT pinRead()\
	{\
		return pin();\
	}\
	enum{Id = ID};\
	enum{Width=sizeof(DataT)*8};\
};


#endif /* LIB_IO_PORT_H_ */
