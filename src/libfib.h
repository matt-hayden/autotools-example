#pragma once

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

#define PHI		1.618033988749894848204586834365638117720309179805762862135L
#define MAX_FI_INT64	93
#define INIT_MEMO_LEN	100

void libfib_init();
static bool libfib_ok = false;
static long double phi;


int64_t fibl(int);
long double log_fibf(int);
long double fibf(int);
