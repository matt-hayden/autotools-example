# autotools-example
A minimal example of autotools packaging

## Steps for use:

```
autoreconf -iv
(in some build dir) .../configure (options)
make -j -l $(./get_build_load.sh) install
```
