battleship
==========

[![Build Status][build-status]][travis]
[![License][license]](LICENSE)

Classic battleship game.
[Rules][rules]

### Linux

##### Run dependencies

 - Qt library (version 4.6+)
 - Standard library of C language
 - Standard library of C++ language

##### Build dependencies

 - All the run dependencies
 - cmake
 - make
 - C++ compiler

##### Build instructions

```bash
$ mkdir build-dir
$ cd build-dir
$ cmake /path/to/battleship
$ make
```

### Windows build

Windows executables are cross-compiled from Linux
using MinGW cross-compiler.
Special scripts will be written in the near future.

[rules]: https://en.wikipedia.org/wiki/Battleship_%28game%29
[license]: https://img.shields.io/badge/License-GPL2-brightgreen.png
[travis]: https://travis-ci.org/zer0main/battleship
[build-status]: https://travis-ci.org/zer0main/battleship.png?branch=master
