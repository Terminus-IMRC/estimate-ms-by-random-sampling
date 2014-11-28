#ifndef __COUNT_H_INCLUDED__
#define __COUNT_H_INCLUDED__

#include <stdint.h>
#include <inttypes.h>

	typedef uint64_t COUNTTYPE;
#define PRICOUNTTYPE PRIu64

	extern COUNTTYPE count_right, count_all;

	void count_init();
	void count_finalize();
	char* get_incremental_count_str(COUNTTYPE count);

#define count_increment(count) count+=1

#endif /* __COUNT_H_INCLUDED__ */
