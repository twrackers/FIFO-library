# FIFO #

The `FIFO` class implements a _FIFO_ (first-in/first-out buffer) with a fixed capacity of bytes.  The FIFO is implemented with a [ring buffer](https://en.wikipedia.org/wiki/Circular_buffer "ring buffer").

Bytes are "pushed" into a FIFO one at a time, and they are "popped" back out with their push order preserved (first in, first out).  Pushes and pops may happen in any order, with two conditions.

1. Pushing into a full FIFO will cause the oldest byte in the FIFO to be lost.
2. Popping from an empty FIFO will return a zero byte.

If these behaviors are not desired, methods are provided to test if a FIFO is full or empty; it will often be neither.
An additional method is available to clear the current contents of the FIFO, leaving it empty.

Beware of creating a FIFO that's too large; because it resides in the processor's RAM, you're constrained by available RAM.  For example, an Arduino Uno has only 2048 bytes of RAM, and some of that will be used by other variables in your code and the libraries you use.

## Dependencies ##

The `FIFO` library has no dependencies on any other libraries.

## Examples ##

The `examples` directory contains a sample sketch, `FIFO_Test.ino`, to show how the `FIFO` class is used.  The example sketch has no dependencies besides the `FIFO` library.

## Installation ##

Instructions for installing the `FIFO` class can be found in file `INSTALL.md` in this repository at [https://github.com/twrackers/FIFO-library/blob/main/INSTALL.md](https://github.com/twrackers/FIFO-library/blob/main/INSTALL.md).

## Note ##

The `FIFO` library replaces the `RingBuffer` library (now deprecated) at [https://github.com/twrackers/RingBuffer-library](https://github.com/twrackers/RingBuffer-library).  New projects should use the `FIFO` library instead of `RingBuffer`.
