#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//argc = arg count, argv = array of strings(chars)
int main(int argc, string argv[])
{

  //if there are not 2 commcand line args (./caesar, followed by the users plaintext), kill program
  if (argc != 2)
  {
    printf("Try Again, this cipher only accepts 2 arguments\n");
    return 1;
  }
  else
  {

    //atoi() returns the converted integer as an int value
    int key = atoi(argv[1]);

    //prompt the user for the word they want to encrypt with caesars cipher
    string plainText = get_string("plaintext: ");
    printf("cipertext: ");

    for (int i = 0, inputlength = strlen(plainText); i < inputlength; i++)
    {
      //first encrypt lower case
      //97 coresponds to 'a'
      if
        islower(plainText[i])
        {
          printf("%c", (((plainText[i] + key) - 97) % 26) + 97);
        }
      //then encrypt upper case
      //65 coresponds to 'A'
      else if
        isupper(plainText[i])
        {
          printf("%c", (((plainText[i] + key) - 65) % 26) + 65);
        }

      else
      {
        printf("%c", plainText[i]);
      }
    }
    printf("\n");

    return 0;
  }
}
