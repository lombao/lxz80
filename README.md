# lx80
Z80 Emulator suite
- A z80 emulator as a shared library
- A Z80 assembler
- An Amstrad CPC 6128 emulator

# IMPORTANT !! STATUS: THIS IS A WORK IN PROGRESS
- Z80 emulator. It is almost complete. Beta status.
- Z80 assembler. It is working altough I want to refactor some of the code
- Amstrad CPC 6128 emulator. It is a work in progress. BIOS and BASIC works.

# HOW TO COMPILE IT
Classical autotools

./configure
make
sudo make install

The default PREFIX is /usr/local

The resulting objects are
- /usr/local/bin/lxzasm     ( The assembler )
- /usr/local/bin/lxcpc6128  ( The Amtrad emulator )
- /usr/local/lib/lx80.so    ( The z80 emulator )
- /usr/local/include/lx80.h ( Thhe header for the shared library )


# Requirements
* SDL2 for the Amstrad Emulator
* Flex and Bison for the Assembbler

# BSD and other *UX Compatibility
LX80 has been developed on Linux platforms, but ideally it should run 
on *BSD systems. I've not been very careful about portability but I am 
willing to accept patches and suggestions to improve that aspect. 


# Bugs, suggestions and comments
Please , send them to me cesar dot lombao at gmail dot com . As I do
not expect being bombarded by emails I will probably answer them all.

# Documentation
Please see the /doc folder

# TO DO
- Create a pkg config file for the project
- Refine the use of interruptions on the emulator
- Create a "virtual" Z80 system for testing/development with GUI
- Add examples/code/tests
- Documentation
- Improve the autotools setup ( I suspect there are some errors )
- Add macros to the lxzasm