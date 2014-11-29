#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void rand_init()
{
	return;
}

void rand_finalize()
{
	return;
}

uint8_t rand8()
{
	uint8_t r;

	r=(uint8_t)random();

	return r;
}

uint16_t rand16()
{
	uint16_t r;

	r=(uint16_t)random();

	return r;
}

uint32_t rand32()
{
	uint32_t r;

	r=(uint32_t)random();

	return r;
}

uint64_t rand64()
{
#if __WORDSIZE>=64/8
	uint64_t r;

	r=(uint64_t)random();

	return r;
#else
	fprintf(stderr, "%s:%d: error: random(3) of this system does not return 64-bit number\n", __FILE__, __LINE__);
	exit(EXIT_FAILURE);

	return 0;
#endif
}
