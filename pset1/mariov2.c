#include <stdio.h>
#include <cs50.h>

int main(void)
{
  //declare height as an integer
  int height;

  do
  {
    //promt user for a number (height) between the number 1 and 23
    height = get_int("please enter a number between 1 and 23: ");
  }
  //make sure the user can only pick a number from 0-23, if not ask again
  while (height < 0 || height > 23);

  for (int row = 0; row < height; row++)
  {
    for (int collum = 0; collum < height; collum++)
    {
      if (row + collum >= height - 1)
      {
        printf("#");
      }
      else

        printf(" ");
    }
    printf("\n");
  }
}