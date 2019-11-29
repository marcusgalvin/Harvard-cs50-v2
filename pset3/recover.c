#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdbool.h>
#include <stdint.h>
//recover.c

//each block is 512 bytes
#define BLOCK_SIZE 512

// unit8_t is shorthand for: a type of unsigned integer of length 8
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

  //make sure only 1 command line argument, if more kill program
  if (argc != 2)
  {
    printf("Please only supply one command line argument to this program\n");
    return 1;
  }

  //remember file names, store infile pointer to memory address of argv[1]
  //store as a string
  char *infile = argv[1];

  //open the card.raw file with fopen, if not return 2, kill program
  FILE *inptr = fopen(infile, "r");

  if (inptr == NULL)
  {
    printf("Sorry, cannot open file %s", infile);
    return 2;
  }

  //BYTE = 8 bits, buffer will store 518 bytes at once
  BYTE buffer[512];
  //counter for the jpeg image files
  int imageCount = 0;

  //declare an array called filename to give each jpeg a name of 8 chars
  char filename[8];
  //points to the location of each jpeg file
  FILE *outptr = NULL;

  while (true)
  {
    //read a 512 block of memory on the card
    //size_t is a data type can represent the size of any object in bytes, return type of sizeof
    //BLOCK_SIZE = 512
    size_t bytesRead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);

    //once the computer reads the entire card image, stop looping
    //the feof function tests the end-of-fle indicator for a given stream, also returns the value zero when end of the file has not occurred
    if (bytesRead == 0 && feof(inptr))
    {
      //break to end loop
      break;
    }

    //now check to see if we found JPEG with a bool data type called jpegFound
    //the below hexadecimals is what every JPEG begins with, buffer contains 512 bytes, so for example buffer[0] == the first byte in the JPEG
    bool jpegFound = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

    //if a second JPEG is found, close the file above
    if (jpegFound && outptr != NULL)
    {
      fclose(outptr);
      imageCount++;
    }

    // if a JPEG is found we have to open the file to write
    if (jpegFound)
    {
      //test jpeg
      //sprintf function writes the data in the string pointed to by str and returns the number of characters written to str, aka gives name
      //%3di, the % means to print the variable here, use at least 3 spaces, and the i means the variable is an int
      //image count is whats looping, and increasing/iterating

      sprintf(filename, "%03i.jpg", imageCount);
      //open a new file and give it is new filename
      outptr = fopen(filename, "w");
    }

    //write data into file anytime one is open
    //remeber that buffer points to the memeory address and outptr is the pointer to the object we are writing out to
    if (outptr != NULL)
    {
      fwrite(buffer, sizeof(BYTE), bytesRead, outptr);
    }
  }

  //close the last JPEG
  fclose(outptr);

  //close the infile aswell
  fclose(inptr);

  //done, return 0
  return 0;
}