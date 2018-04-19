#include "libfib.h"

static int libfib_ok = 0;
static double phi, sr5;
static int64_t phi_low_memo[MAX_FI_INT64+1];


void
libfib_init() {
	sr5 = sqrt(5.L);
	phi = (1+sr5)/2.;
	phi_low_memo[0] = 0;
	phi_low_memo[1] = 1;
	for (size_t i=2; i < MAX_FI_INT64; i++) {
		phi_low_memo[i] = phi_low_memo[i-1]+phi_low_memo[i-2];
	}
	libfib_ok = 1;
}


int64_t
fibl(int n) {
	if (n < 0) return -1;
	if (MAX_FI_INT64-1 < n) return -2;
	return phi_low_memo[n];
}


double
fibf(int n) {
	if (n < 0)
#ifdef NAN
		return NAN;
#else
		return -1.;
#endif
	int64_t f = fibl(n);
	if (0 <= f) return (double)f; // This cast loses precision starting at n=78
	n += 1-MAX_FI_INT64;
	return fibl(MAX_FI_INT64-1)*pow(phi, n);
}
