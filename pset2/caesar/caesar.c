#include <stdio.h>
#include <stdlib.h>

int isUpper(char letter);
int isLower(char letter);
void shiftUpper(char *letter, int key);
void shiftLower(char *letter, int key);
// A-Z = 65-90
// a-z = 97-122

int main(int argc, const char *argv[])
{
  int i, key = (int) strtol(argv[1], NULL, 10);
  char str[] = "ABCDEF.GHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


  for (i = 0; str[i] != '\0'; i++)
  {
    printf("%c (%d) ", str[i], str[i]);
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

  printf("\n");
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
  printf("shifting [%c] to [%c]\n", l, new_letter);
}

void shiftLower(char *letter, int key) {
  char l = *letter;
  char new_letter = (l - 97 + key)%26 + 97;
  printf("shifting [%c] to [%c]\n", l, new_letter);
}
