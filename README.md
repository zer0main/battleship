battleship
==========

[![Build Status][build-status]][travis]
[![License][license]](LICENSE)

Classic battleship game.
[Rules][rules]

## Instruction

### Download battleship

You just need to [download][download] executable for Windows or Linux.

**Warning**. The installer and the program doesn't work
from a directory with non-ascii letters in name.

### Run dependencies (only for Linux users)

 - Qt library (version 4.6+)
 - Standard library of C language
 - Standard library of C++ language

### Simple build (for Linux and Windows)

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

### Advanced build

##### Windows

Windows executables are cross-compiled from Linux
using MinGW cross-compiler.

For Windows 32 bit:

```bash
$ export FILENAME_SUFFIX='windows32'
```

For Windows 64 bit:

```bash
$ export FILENAME_SUFFIX='windows64'
```

Install build requirements:

```bash
$ sudo ./build/windows/requirements.sh
```

Build the program:

```bash
$ source ./build/windows/build.sh
```

Create Installation Wizard for Windows:

```bash
$ source ./build/windows/package.sh
```

##### Linux

```bash
$ export FILENAME_SUFFIX='linux64'
```

Install build requirements:

```bash
$ sudo ./build/linux/requirements.sh
```

Build the program:

```bash
$ source ./build/linux/build.sh
$ source ./build/linux/package.sh
```

[download]: https://github.com/zer0main/battleship/releases/latest
[rules]: https://en.wikipedia.org/wiki/Battleship_%28game%29
[license]: https://img.shields.io/badge/License-GPL2-brightgreen.png
[travis]: https://travis-ci.org/zer0main/battleship
[build-status]: https://travis-ci.org/zer0main/battleship.png?branch=master
