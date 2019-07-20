/*
 * wiegand.h
 *
 *  Created on: 2019. júl. 20.
 *      Author: Dabi
 */

#ifndef WIEGAND_H_
#define WIEGAND_H_

#include <stdint.h>

class Wiegand {
  public:
	void SetCode(uint32_t code);
	bool ReadNextBit(bool &bit);
  private:
	uint32_t m_code;
	uint8_t m_bits;
};

extern Wiegand wiegand;

#endif /* WIEGAND_H_ */
