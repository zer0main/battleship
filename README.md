battleship
==========

[![Build Status][build-status]][travis]
[![License][license]](LICENSE)

Classic battleship game.
[Rules][rules]

## Instruction

### Download battleship

You just need to [download][download] executable for Windows, Mac or Linux.

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

For more build options see [additional
instructions](build).

[download]: https://github.com/zer0main/battleship/releases/latest
[rules]: https://en.wikipedia.org/wiki/Battleship_%28game%29
[license]: https://img.shields.io/badge/License-GPL2-brightgreen.png
[travis]: https://travis-ci.org/zer0main/battleship
[build-status]: https://travis-ci.org/zer0main/battleship.png?branch=master

