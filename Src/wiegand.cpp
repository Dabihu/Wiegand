/*
 * wiegand.cpp
 *
 *  Created on: 2019. júl. 20.
 *      Author: Dabi
 */

#include "wiegand.h"

Wiegand wiegand;

void Wiegand::SetCode(uint32_t code) {
	uint32_t i=0;
	uint32_t mask=1<<24;

	code <<=1;

	bool parity = false;		// 26..13 = Even parity
	while (i++<12) {
		if (code & mask)
			parity = !parity;
		mask>>=1;
	}
	if (parity)
		code|=1<<25;

	i=0;
	parity = true;				// 26..13 = Odd parity
	while (i++<12) {
		if (code & mask)
			parity = !parity;
		mask>>=1;
	}
	if (parity)
		code|=1;

	m_code=code << 6;
	m_bits=26;
}

bool Wiegand::ReadNextBit(bool &bit) {
	if (m_bits==0)
		return false;
	bit = m_code & 0x80000000;
	m_code<<=1;
	m_bits--;
	return true;
}

