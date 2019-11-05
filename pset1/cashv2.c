#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
  //declare change owed as an int
  int cents_owed;

  //use a do while loop and prompt user for the amt of change owed
  do
  {
    float dollars_owed = get_float("Change owed: ");
    //the round function is available through the <math.h> header
    cents_owed = round(dollars_owed * 100);
  } while (cents_owed <= 0);

  //using modulo you can determine how many coins can be owed per denomination of coin
  //mod the amt of change the user input and then divide it by the amount of each coin (quarter, dime, nickle, penny)

  int quarters = cents_owed / 25;
  int dimes = (cents_owed % 25) / 10;
  int nickels = ((cents_owed % 25) % 10) / 5;
  int pennies = ((cents_owed % 25) % 10) % 5;

  //add all the rounded amounts together and you have the least number of EACH coins to return

  printf("%d\n", quarters + dimes + nickels + pennies);
}