/*
 * circular_buffer.h
 *
 *  Created on: 4 окт. 2015 г.
 *      Author: OmeZ
 */

#ifndef UTILS_CIRCULAR_BUFFER_H_
#define UTILS_CIRCULAR_BUFFER_H_

template<typename T, unsigned char size>
class CircularBuffer {
private:
	typedef unsigned char pointerT;
	pointerT count;
	pointerT pos;
	T buffer[size];
public:

	CircularBuffer() {
		count = 0;
		pos = 0;
	}

	/**
	 * Adds item to end of buffer
	 */
	bool push(T item) {
		if (count >= size) {
			return false;
		}

		if (pos >= size - 1) {
			pos++;
		} else {
			pos = 0;
		}

		pos++;
		count++;
		buffer[pos] = item;

		return true;
	}

	/**
	 * Takes item from end of buffer
	 */
	T pop() {
		if (count <= 0) {
			return buffer[pos];
		}

		if (pos <= 0) {
			pos = size - 1;
		} else {
			pos--;
		}

		return buffer[pos];
	}

	/**
	 * Adds item to beginning of buffer
	 */
	bool unshift(T item) {
		if (count >= size) {
			return false;
		}

		count++;
		if (count > pos)
			buffer[size - 1 - pos + count] = item;
		else
			buffer[pos - count] = item;

		return true;
	}

	/**
	 * Takes item from beginning of buffer (FIFO)
	 *
	 */
	T shift() {
		if (count <= 0) {
			return buffer[pos];
		}

		count--;
		if ((count + 1) > pos) {
			return buffer[size - pos + count];
		} else {
			return buffer[pos - count + 1];
		}
	}

	/**
	 * Returns buffer elements count
	 */
	unsigned int lenght() {
		return count;
	}

	/**
	 * Returns true if buffer is empty
	 */
	bool empty() {
		return count == 0;
	}

};

#endif /* UTILS_CIRCULAR_BUFFER_H_ */
