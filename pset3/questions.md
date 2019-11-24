## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

The use cases for the above are to define how many bits are in each data type.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 8
DWORD = 32
LONG = 32
WORD = 16

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

Ascii

## What's the difference between `bfSize` and `biSize`?

bfSize = The size, in bytes, of the bitmap file.
biSize = the size of the BITMAPINFOHEADER only. It is 40 bytes.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount defines how dark/light each color will be.

## Why might `fopen` return `NULL` in `copy.c`?

This may occur if the file that fopen is trying to write to doesn't exist.

## Why is the third argument to `fread` always `1` in our code?

TODO

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

TODO

## What does `fseek` do?

fseek() function is used to move file pointer position to the given location.

## What is `SEEK_CUR`?

SEEK_CUR – It moves file pointer position to given location