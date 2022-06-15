# learncpp
Walking through [LearnCpp.com](https://www.learncpp.com/)

## Requirements

Either of the two build environments:

1. llvm-mingw from https://github.com/mstorsjo/llvm-mingw
2. GCC from https://github.com/mmozeiko/build-gcc-mingw

## Usage

LLVM build works, has smaller output binary and tooling folder is smaller. Use `Terminal` => `Run default task` (`CTRL + SHIFT + B`) to run non-debug build. Debugging works, but I'm unable to get the configuration to work when the terminal requests user input (`cin >>`). Normal, line-by-line debugging works, local variables are also visible in the debug window.

The GCC version makes it possible to debug even when user input is requested.