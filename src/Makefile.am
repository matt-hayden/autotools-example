
lib_LTLIBRARIES=libfib.la
libfib_la_SOURCES=libfib.c
libfib_la_LIBADD = -lm
# Set an init function (like an entry point) that'll run with the shared lib is loaded
libfib_la_LDFLAGS = -Wl,-init,libfib_init

include_HEADERS=libfib.h

bin_PROGRAMS=fib
fib_SOURCES=fib.c
fib_LDADD=libfib.la
