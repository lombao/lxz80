## LXZ80
Z80 Emulator suite, composed by a Z80 emulator, an assembler and a small
tool to run z80 binaries.

- A Z80 emulator as a shared library 	( liblxz80.so )
- A Z80 assembler  			( lxzasm )
- A Z80 run engine			( lxzrun )

# Why ?
Why not. Next question

# HOW TO COMPILE
 
./autogen.sh
./configure
make
sudo make install

( note: the default PREFIX is /usr/local , but you can change it with the --prefix switch )

The resulting objects are
- $prefix/bin/lxzasm     
- $prefix/bin/lxzrun
- $prefix/lib64/lx80.so    
- $prefix/include/lxz80.h 
- $prefix/share/lxz80/examples ( some .asm files to test and try both lxzasm and lxzrun )
- $prefix/lib64/pkgconfig/lxz80.pc 

The build requirements are:
- Obviously, autoconf and automake
- flex and bison
- any non-prehistoric glibc will suffice

# BSD and other Compatibility
LXZ80 has been developed on Linux platforms, but ideally it should run 
on BSD systems with minor or none changes at all, I did not test that myself.
Should anyone wants to send me any pacth or suggestion for improvement I will 
gladly accepted it. The same applies for OSX.
Other OS are out of my interest or scope and they will not be supported.

# Bugs, suggestions and comments
Please , send them to me: cesar dot lombao at gmail dot com . As I do
not expect being bombarded by emails I will probably answer them all.

# Documentation
Additional documentation in the /doc folder

