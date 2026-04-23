# ccd

A tiny hex dumper written in C. Prints a file as offset, hex bytes,
and ASCII, similar to `xxd` or `hexdump`, but much, much smaller.

## Build

Compile into the current directory:

    make

Install to your home directory (no sudo needed):

    make install PREFIX=~/.local

Install system-wide:

    sudo make install

## Usage

    ccd <file>

## Example

    $ ccd /bin/ls
    00000000 7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 |.ELF............|
    00000010 03 00 3e 00 01 00 00 00 30 6d 00 00 00 00 00 00 |..>.....0m......|
    00000020 40 00 00 00 00 00 00 00 28 24 02 00 00 00 00 00 |@.......($......|
