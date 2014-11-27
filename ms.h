#ifndef __MS_H_INCLUDED__
#define __MS_H_INCLUDED__

#include <stdint.h>
#include "X.h"

	typedef int8_t MSTYPE;

	void is_ms_init();
	void is_ms_finalize();
	_Bool is_ms(MSTYPE ms[X*X]);

#endif /* __MS_H_INCLUDED__ */
