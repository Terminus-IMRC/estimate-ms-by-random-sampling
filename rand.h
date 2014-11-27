#ifndef __RAND_H_INCLUDED__
#define __RAND_H_INCLUDED__

#include <stdint.h>

	void rand_init();
	void rand_finalize();
	uint8_t rand8();
	uint16_t rand16();
	uint32_t rand32();
	uint64_t rand64();

#endif /* __RAND_H_INCLUDED__ */
