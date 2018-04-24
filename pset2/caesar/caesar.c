#include <stdio.h>
#include <stdlib.h>

int isUpper(char letter);
int isLower(char letter);
int shiftUpper(char letter);
// A-Z = 65-90
// a-z = 97-122

int main(int argc, const char *argv[])
{
  int i, key = (int) strtol(argv[1], NULL, 10);
  char str[] = "It was the best of times, it was the worst of times.";


  for (i = 0; str[i] != '\0'; i++)
  {
    printf("%c (%d) ", str[i], str[i]);
    if (isUpper(str[i]))
    {
      printf("(upper), ");
    }
    else if (isLower(str[i]))
    {
      printf("(lower), ");
    }
    else
      printf("(symbol), ");

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

int shiftUpper(char letter) {
  return 0;
}
