
import ctypes
import sys

libfib = ctypes.CDLL('/usr/local/lib/libfib.so')
libfib.fibl.restype = ctypes.c_longlong
libfib.fibf.restype = ctypes.c_double


def approx_fib(n):
    """Uses floating-point math -- attains only casual accuracy.
    
    Constant time.
    """
    f = libfib.fibf(n)
    try:
        return round(f)
    except ArithmeticError:
        return f


def _fib(n):
    """Wrapper for C library call"""
    f = libfib.fibl(n)
    if (f == -1):
        raise ValueError()
    if (f == -2):
        raise OverflowError()
    return f


def fibrange(*args):
    """Give the Fibonacci coefficients F(i) up until F(j)
    """
    r = range(*args)
    i = r.start
    b = 1
    while (1 < i):
        try:
            b = _fib(i)
            break
        except OverflowError:
            pass
        i -= 1
    a = _fib(i-1) if (i) else 0
    assert a+b
    while (i < r.stop):
        if (i in r):
            yield a
        a, b = b, a+b
        i += 1


def fib(n, m=93 if (sys.maxsize >> 62) else 47):
    """Exact integer math, slow in the worst case

    O(m) for m = n-93 or some big number
    """
    for a in fibrange(min(n, m), n+1):
        pass
    return a


if __name__ == '__main__':
    import timeit
    print("F(40)")
    print(timeit.timeit("fib(40)", setup='from __main__ import fib'))
    print("F(80)")
    print(timeit.timeit("fib(80)", setup='from __main__ import fib'))
    print("F(120)")
    print(timeit.timeit("fib(120)", setup='from __main__ import fib'))
