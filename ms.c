#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "X.h"
#include "ms.h"

static uint8_t *c;

void is_ms_init()
{
	c=(uint8_t*)malloc((X+X+2)*sizeof(uint8_t));
	if(c==NULL){
		fprintf(stderr, "%s:%d: error: failed to allocate c\n", __FILE__, __LINE__);
		exit(EXIT_FAILURE);
	}

	return;
}

_Bool is_ms(MSTYPE *ms)
{
	int i, j;
	_Bool u[X*X]={0};

	for(i=0; i<X*X; i++){
		if(!((ms[i]>=0)&&(ms[i]<X*X)))
			return 0;
		if(u[ms[i]])
			return 0;
		u[ms[i]]=!0;
	}

	memset(c, (uint8_t)0, X+X+2);

	for(i=0; i<X; i++){
		for(j=0; j<X; j++){
			c[0*X+j]+=ms[j*X+i];
			c[1*X+j]+=ms[j+i*X];
		}
		c[X+X+0]+=ms[i+i*X];
		c[X+X+1]+=ms[(X-1-i)+i*X];
	}

	for(i=0; i<X+X+2; i++)
		if(c[i]!=OneLine)
			return 0;
	
	return !0;
}

#ifdef TEST
int main()
{
	int i;

#if X==3
	MSTYPE a1[X*X]={	\
		1,8,3,	\
		6,4,2,	\
		5,0,7 };
	MSTYPE a2[X*X]={	\
		0,1,2,	\
		3,4,5,	\
		6,7,8	};
	MSTYPE a3[X*X]={	\
		5,5,5,	\
		5,5,5,	\
		5,5,5	};
#elif X==4
	MSTYPE a1[X*X]={	\
		 1, 8,15, 6,	\
		14, 4, 3, 9,	\
		 5,11,12, 2,	\
		10, 7, 0,13	};
	MSTYPE a2[X*X]={	\
		 0, 1, 2, 3,	\
		 4, 5, 6, 7,	\
		 8, 9,10,11,	\
		12,13,14,15	};
	MSTYPE a3[X*X]={	\
		 7, 7, 7, 7,	\
		 7, 7, 7, 7,	\
		 7, 7, 7, 7,	\
		 7, 7, 7, 7	};
#else
#error This X is not supported. Add the test data by yourself.
#endif

	is_ms_init();

	for(i=0; i<10; i++){
		if(!is_ms(a1)){
			fprintf(stderr, "%s:%d: error: test failed with a1 #%d\n", __FILE__, __LINE__, i);
			exit(EXIT_FAILURE);
		}
		
		if(is_ms(a2)){
			fprintf(stderr, "%s:%d: error: test failed with a2 #%d\n", __FILE__, __LINE__, i);
			exit(EXIT_FAILURE);
		}

		if(is_ms(a3)){
			fprintf(stderr, "%s:%d: error: test failed with a3 #%d\n", __FILE__, __LINE__, i);
			exit(EXIT_FAILURE);
		}
	}

	printf("%s:%d: test succeeded\n", __FILE__, __LINE__);

	return 0;
}
#endif /* TEST */
