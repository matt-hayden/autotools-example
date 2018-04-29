# autotools-example
A minimal example of autotools packaging

## Steps for use:

```
MAXLOAD=$(awk "BEGIN { print $(nproc) - 0.5 }")
autoreconf -iv
(in some build dir) .../configure (options)
make -j -l $MAXLOAD install
```
