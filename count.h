#ifndef __COUNT_H_INCLUDED__
#define __COUNT_H_INCLUDED__

#include <gmp.h>

	extern mpz_t count_right, count_all;

	void count_init();
	void estimate_ms_count();
	char* get_estimated_ms_count_str();
	char* get_incremental_count_str(mpz_t count);

#define count_increment(count) mpz_add_ui(count, count, 1)

#endif /* __COUNT_H_INCLUDED__ */
