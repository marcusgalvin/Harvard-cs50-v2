#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{

  // ensure user only submits one command line argument, if more kill program
  if (argc > 2)
  {
    printf("You have entered an inocrrect amount of command line arguments, please only supply one word after ./vigenere\n");

    return 1;
  }

  else
  {
    // loop through the user inputed keyword and check if the charactered enetered are valid alphabet characters, else kill program
    // isalpha function ensures this
    string keyword = argv[1];
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {
      //check each char with [i]
      if (!isalpha(keyword[i]))
      {
        printf("You have eneterd a non alphabetical character, please only submit valid characters in your input\n");

        return 1;
      }
    }
  }
}