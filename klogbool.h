#pragma once

#if __STDC_VERSION__ <= 199901
	#include <stdint.h>
	typedef uint8_t bool;
	#define true 1
	#define false 0
#else
	#include <stdbool.h>
#endif
