#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <libbrahe/prng.h>

static brahe_prng_state_t st;

void rand_init()
{
	bool r;

	if((r=brahe_prng_init(&st, BRAHE_PRNG_MARSENNE_TWISTER, BRAHE_UNKNOWN_SEED))==false){
		fprintf(stderr, "%s:%d: error: brahe_prng_init failed\n", __FILE__, __LINE__);
		exit(EXIT_FAILURE);
	}

	return;
}

void rand_finalize()
{
	brahe_prng_free(&st);

	return;
}

uint8_t rand8()
{
	uint8_t r;

	r=(uint8_t)brahe_prng_next(&st);

	return r;
}

uint16_t rand16()
{
	uint16_t r;

	r=(uint16_t)brahe_prng_next(&st);

	return r;
}

uint32_t rand32()
{
	uint32_t r;

	r=(uint32_t)brahe_prng_next(&st);

	return r;
}

uint64_t rand64()
{
	fprintf(stderr, "%s:%d: error: libbrahe_mersenne does not support 64-bit random number\n", __FILE__, __LINE__);
	exit(EXIT_FAILURE);

	return 0;
}
