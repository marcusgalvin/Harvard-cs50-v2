#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
  float changeOwed;

  do
  {
    //prompt user
    changeOwed = get_float("Change owed: ");
  } while (changeOwed < 0);

  //round() simply rounds up the float to the nearest int - from math.h header
  int cents = round(changeOwed * 100);

  int coins = 0;

  while (cents >= 25)
  {
    cents -= 25;
    coins++;
  }

  while (cents >= 10)
  {
    cents -= 10;
    coins++;
  }

  while (cents >= 5)
  {
    cents -= 5;
    coins++;
  }

  while (cents >= 1)
  {
    cents -= 1;
    coins++;
  }

  printf("minimum coins owed: %i\n", coins);
}
