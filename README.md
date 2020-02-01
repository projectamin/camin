# camin

CAmin is a C++ implementation of the Amin spec, intends to follow the current Perl design and implementation patterns 
as much as possible to allow machine and filter knowledge to be transferable.

Requires: 
* libxml++
* libuv
* uriparser

Build: 
```
mkdir build && cd build && cmake ../ && make
```

OSX: 

Due to libffi being Cellar only via homebrew you need to add the pkg_config path explictly before running cmake.

```
export PKG_CONFIG_PATH=/usr/local/opt/libffi/lib/pkgconfig
```
