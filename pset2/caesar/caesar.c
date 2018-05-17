/**
 * Produces a Caesarean encryption
 * 2018 (c) Peter Martinson
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isUpper(char letter);
int isLower(char letter);
void shiftUpper(char *letter, int key);
void shiftLower(char *letter, int key);
char * getString(char *string);
#define MAXLINE 256

// A-Z = 65-90
// a-z = 97-122

int main(int argc, const char *argv[])
{
  int i, key;
  char *str = malloc(MAXLINE);

  if (argc == 2)
    key = (int) strtol(argv[1], NULL, 10);
  else
    return 1;

  getString(str);

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

  printf("ciphertext: %s\n", str);

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
}

void shiftLower(char *letter, int key) {
  char l = *letter;
  char new_letter = (l - 97 + key)%26 + 97;
  *letter = new_letter;
}

char* getString(char *s)
{
  printf("plaintext: ");
  fgets(s, MAXLINE, stdin);
  if ((strlen(s) > 0) && (s[strlen (s) - 1] == '\n'))
    s[strlen(s) - 1] = '\0'; // Remove the newline
  return s;
}
