#pragma once
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

// sizeof(int64_t) < F(92)
#define MAX_FI_INT64  93

void libfib_init();
int64_t fibl(int);
double fibf(int);
