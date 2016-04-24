# Advanced build

## Mac

The mac version is compiled from Travis-CI.

## Windows

Windows executables are cross-compiled from Linux
using MinGW cross-compiler.

For Windows 32 bit:

```bash
$ export BATTLESHIP_PLATFORM='windows32'
```

For Windows 64 bit:

```bash
$ export BATTLESHIP_PLATFORM='windows64'
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
$ source build-dir/package.sh
```

## Linux

```bash
$ export BATTLESHIP_PLATFORM='linux64'
```

Install build requirements:

```bash
$ sudo ./build/linux/requirements.sh
```

Build the program:

```bash
$ source ./build/linux/build.sh
$ source build-dir/package.sh
```
