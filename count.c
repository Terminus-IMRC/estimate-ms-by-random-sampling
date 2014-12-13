#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "X.h"
#include "count.h"

COUNTTYPE count_right, count_all;
static int max_figures_of_count;
static _Bool count_init_done=0;

void count_init()
{
	if(!count_init_done){
		count_right=0;
		count_all=0;

		/* log10(2^(sizeof(COUNTTYPE)*8))
			 <=> (sizeof(COUNTTYPE)*8)*log10(2)
			 <=> (sizeof(COUNTTYPE)*8)*(log(2)/log(10)) */
		max_figures_of_count=ceil((sizeof(COUNTTYPE)*8)*(log(2)/log(10)));
		/* and in case of negative */
		max_figures_of_count+=1;

		count_init_done=!0;
	}

	return;
}

void count_finalize()
{
	return;
}

char* get_incremental_count_str(COUNTTYPE count)
{
	char *s;

	s=(char*)malloc((max_figures_of_count+1)*sizeof(char));
	if(s==NULL){
		fprintf(stderr, "%s:%d: error: failed to allocate s\n", __FILE__, __LINE__);
		exit(EXIT_FAILURE);
	}

	sprintf(s, "%"PRICOUNTTYPE, count);

	return s;
}
