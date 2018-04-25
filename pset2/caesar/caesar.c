/**
 * Produces a Caesar encryption
 * 2018 (c) Peter Martinson
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int isUpper(char letter);
int isLower(char letter);
void shiftUpper(char *letter, int key);
void shiftLower(char *letter, int key);
char * getString(void);

static int MAXLENGTH = 1000;


// A-Z = 65-90
// a-z = 97-122

int main(int argc, const char *argv[])
{
  int i, key = (int) strtol(argv[1], NULL, 10);
  char str[] = "ABCDEF.GHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char *newstr;
  newstr = getString();

  printf("your string: %s\n", newstr);


  for (i = 0; str[i] != '\0'; i++)
  {
    if (isUpper(str[i]))
    {
      shiftUpper(str + i, key);
    }
    else if (isLower(str[i]))
    {
      shiftLower(str + i, key);
    }
    else
      ;
  }

  printf("new string: %s\n", str);

  return 0;
}

int isUpper(char letter) {
  int bool = 0;
  if (letter >= 65 && letter <= 90)
    bool = 1;
  return bool;
}

int isLower(char letter) {
  int bool = 0;
  if (letter >= 97 && letter <= 122)
    bool = 1;
  return bool;
}

void shiftUpper(char *letter, int key) {
  char l = *letter;
  char new_letter = (l - 65 + key)%26 + 65;
  *letter = new_letter;
  /* printf("shifting [%c] to [%c]\n", l, new_letter); */
}

void shiftLower(char *letter, int key) {
  char l = *letter;
  char new_letter = (l - 97 + key)%26 + 97;
  *letter = new_letter;
}

char * getString(void)
{
  int c, num_letters = 0;
  char *return_pointer;
  static char phrase[1000];

  printf("Phrase: ");

  while ((c=getchar()) != EOF && c != '\n')
  {
    phrase[++num_letters] = c;
  }

  return_pointer = phrase;

  return return_pointer;

}
