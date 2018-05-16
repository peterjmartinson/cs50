/**
 * Produces a Caesar encryption
 * 2018 (c) Peter Martinson
 * 
 */
/**
:) caesar.c exists.
:) caesar.c compiles.
:( encrypts "a" as "b" using 1 as key expected "ciphertext: b\n", not "argc: 2\nyour s..."
:( encrypts "barfoo" as "yxocll" using 23 as key expected "ciphertext: yxo...", not "argc: 2\nyour s..."
:( encrypts "BARFOO" as "EDUIRR" using 3 as key expected "ciphertext: EDU...", not "argc: 2\nyour s..."
:( encrypts "BaRFoo" as "FeVJss" using 4 as key expected "ciphertext: FeV...", not "argc: 2\nyour s..."
:( encrypts "barfoo" as "onesbb" using 65 as key expected "ciphertext: one...", not "argc: 2\nyour s..."
:( encrypts "world, say hello!" as "iadxp, emk tqxxa!" using 12 as key expected "ciphertext: iad...", not "argc: 2\nyour s..."
:( handles lack of argv[1] timed out while waiting for program to exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isUpper(char letter);
int isLower(char letter);
void shiftUpper(char *letter, int key);
void shiftLower(char *letter, int key);
char * getString(char *string);
/* char * getString(void); */



// A-Z = 65-90
// a-z = 97-122

int main(int argc, const char *argv[])
{
  int i, key;
  if (argc == 2)
    key = (int) strtol(argv[1], NULL, 10);
  else
    return 0;
  char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char newstr[100];
  char output_str[1000];
  getString(newstr);
  printf("your string: %s\n", newstr);


  for (i = 0; newstr[i] != '\0'; i++)
  {
    if (isUpper(newstr[i]))
    {
      shiftUpper(newstr + i, key);
    }
    else if (isLower(newstr[i]))
    {
      shiftLower(newstr + i, key);
    }
    else
      ;
  }

  printf("new string: %s\n", newstr);

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
  printf("Phrase: ");
  scanf("%99s", s);
  return s;
}
