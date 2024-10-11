# Template for AVR projects

This repository contains a template that can be used to set up a C project for an AVR microcontroller.
The example uses avr5 setting for the avr-gcc `mmcu` option clocked at 16MHz

## Before you start

You can use CMake with the provided CMakeLists.txt file.
Before starting, make sure you edit some of the variables within the `CMakeLists.txt` file:

- replace path to the VLCB library (example uses relative path to the repository root)
- **MCU**, the MCU in the AVR part format specified by avrdude, a complete list can be accessed through the 
```avrdude -p ?``` command
- **CLOCK_FREQ**, the clock frequency at which the MCU is configured tho run at; the default can be inferred by the MCU 
datasheet together with the fuse configuration.
- **PROJ_NAME**, the name of the project, and of the generated executables.
- **PROG_STR**, defaults to atmelice (ATMEL ICE in JTAG mode), and should contain the programmer identifier in the 
avrdude format; a complete list can be accessed through the ```avrdude -c ?``` command

You might also need to change the path to the compiler set by 
```cmake
set(CMAKE_C_COMPILER /usr/bin/avr-gcc)
set(CMAKE_ASM_COMPILER /usr/bin/avr-gcc)
```
note that you need to use the full path, otherwise the sub-project of vlcb will get confused and will not be able to
compile.

## Using CMake

```bash
mkdir build && cd build
cmake .. -B . # Defaults to a debug build
cmake .. -B . -DCMAKE_BUILD_TYPE=Release # If you want a release build
```

# Credits
- this repo is a modified fork of https://github.com/antima/avr-template