#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
  // ensure proper usage
  if (argc != 3)
  {
    printf("Usage: copy infile outfile\n");
    return 1;
  }
}