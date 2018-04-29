#include "libfib.h"

struct fib_memo_t {
	size_t len;
	int64_t *val;
};
static struct fib_memo_t fib_memo = { .len=INIT_MEMO_LEN };

void
libfib_init() {
	phi = (1+sqrtl(5.L))/2;

	fib_memo.val = (int64_t*)calloc(fib_memo.len, sizeof(int64_t));
	fib_memo.val[0] = 0;
	fib_memo.val[1] = 1;
	for (size_t i=2; i < fib_memo.len; i++) {
		fib_memo.val[i] = fib_memo.val[i-1]+fib_memo.val[i-2];
		if (fib_memo.val[i] < fib_memo.val[i-1]) { // Rely on overflow
			fib_memo.len = i;
			break;
		}
	}
	printf("fib_memo.len=%lu\n", fib_memo.len);
	fib_memo.val = (int64_t*)realloc(fib_memo.val, fib_memo.len*sizeof(int64_t));
	libfib_ok = true;
}


int64_t
fibl(int n) {
	if (n < 0) return -1;
	if (fib_memo.len-1 < n) return -2;
	return fib_memo.val[n];
}


long double
log_fibf(int n) {
	int64_t f = fibl(n);
	if (-2 == f) {
		n -= fib_memo.len-1;
		return logl(fibl(fib_memo.len-1))+phi*n;
	}
	if (f <= 0) {
		return -1.;
	}
	return logl(f);
}


long double
fibf(int n) {
	if (0 == n) return 0;
	long double rlog = log_fibf(n);
	if (rlog < 0.)
#ifdef NAN
		return NAN;
#else
		return 0.;
#endif
	return expl(rlog);
}
