// PACKAGE_STRING
#include <stdio.h>

#include "libfib.h"

int
main() {
	//libfib_init(); // might be necessary if static linking
	double f = fibf(0)
	     , ae=0.
	     , e;
	double p2 = 1.
	     , p1 = f;
	printf("i\tF(i)\taccumulated error\n");
	for (int i = 1; i < 111; i++) {
		f = fibf(i);
		e = f-p1-p2;
		ae += e;

		printf("%d\t%.0f\t%.0f\n", i, f, ae);
		p2 = p1;
		p1 = f;
	}
}
