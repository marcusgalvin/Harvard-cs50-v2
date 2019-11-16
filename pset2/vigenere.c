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
    // loop through the user inputed keyword and check if the characters enetered are valid alphabet characters, else kill program
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

  // Store key as string, set keyLen to get the length of it
  string key = argv[1];
  int keyLen = strlen(key);

  // Get the users input to encrypt
  string test = get_string("test input")
      string plaintext = get_string("plaintext: ");

  // Loop through the length of plaintext
  for (int i = 0, j = 0, plaintextlength = strlen(plaintext); i < plaintextlength; i++)
  {
    // Get key for this letter
    int letterKey = tolower(key[j % keyLen]) - 'a';

    // Keep case of letter
    if (isupper(plaintext[i]))
    {
      // Get modulo number and add to appropriate case
      printf("%c", 'A' + (plaintext[i] - 'A' + letterKey) % 26);

      // Only increment j when used
      j++;
    }
    else if (islower(plaintext[i]))
    {
      printf("%c", 'a' + (plaintext[i] - 'a' + letterKey) % 26);
      j++;
    }
    else
    {
      // return unchanged
      printf("%c", plaintext[i]);
    }
  }

  printf("\n");

  return 0;
}
