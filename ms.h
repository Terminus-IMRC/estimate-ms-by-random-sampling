#ifndef __MS_H_INCLUDED__
#define __MS_H_INCLUDED__

#include <stdint.h>
#include <inttypes.h>
#include "X.h"

	typedef int8_t MSTYPE;
#define PRIMSTYPE PRIu8

	void is_ms_init();
	void is_ms_finalize();
	_Bool is_ms(MSTYPE ms[X*X]);

#endif /* __MS_H_INCLUDED__ */
