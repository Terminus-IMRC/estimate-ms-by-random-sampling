#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include "NLOOPS.h"
#include "X.h"
#include "rand.h"
#include "count.h"
#include "ms.h"

void cmrs_init()
{
	rand_init();
	count_init();
	is_ms_init();

	return;
}

void cmrs_finalize()
{
	rand_finalize();
	count_finalize();
	is_ms_finalize();

	return;
}

void cmrs()
{
	int i, j;
	MSTYPE a[X*X];

	for(i=0; i<NLOOPS; i++){
		for(j=0; j<X*X; j++){
			a[j]=rand8()%(X*X);

#ifdef PRINT_MS
			printf("%2"PRIMSTYPE"%c", a[j], j%X==X-1?'\n':' ');
#endif /* PRINT_MS */
		}
#ifdef PRINT_MS
		puts("------------");
#endif /* PRINT_MS */
		count_increment(count_all);
		if(is_ms(a))
			count_increment(count_right);
	}

	return;
}
