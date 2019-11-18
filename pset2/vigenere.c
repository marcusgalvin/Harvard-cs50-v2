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

  //get user input: plaintext
  string plainText = get_string("plaintext: ");
  printf("cipertext: ");

  //the key = argv[1]
  string key = argv[1];
  //store the keys length as an int
  int keyLength = strlen(key);

  //'a' = 65
  //'A' = 97

  // Loop through the user's input: plaintext
  for (int i = 0, j = 0, n = strlen(plainText); i < n; i++)
  {
    // Get key for this letter
    int letterKeyIndex = tolower(key[j % keyLength]) - 'a';

    // for uppercase
    if (isupper(plainText[i]))
    {
      printf("%c", 'A' + (plainText[i] - 'A' + letterKeyIndex) % 26);
      j++;
    }
    //for lower case
    else if (islower(plainText[i]))
    {
      printf("%c", 'a' + (plainText[i] - 'a' + letterKeyIndex) % 26);
      j++;
    }
    else
    {
      // else return plaintext non changed
      printf("%c", plainText[i]);
    }
  }

  printf("\n");

  return 0;
}
