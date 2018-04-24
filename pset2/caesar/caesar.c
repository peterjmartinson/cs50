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
/* int * getString(void); */

// A-Z = 65-90
// a-z = 97-122

int main(int argc, const char *argv[])
{
  int i, key = (int) strtol(argv[1], NULL, 10);
  char str[] = "ABCDEF.GHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


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

/* int * getString(void) */
/* { */

/*   printf("Phrase: "); */

/*   int c, digits = 0, redo_flag = 0, *return_pointer; */
/*   static int card_number[17]; */

/*   while ((c=getchar()) != EOF && c != '\n') */
/*   { */
/*     if (c < '0' || c > '9' || digits > 15) */
/*     { */
/*       redo_flag = 1; */
/*     } */
/*     else */
/*     { */
/*       card_number[++digits] = c - 48; */
/*     } */
/*   } */

/*   card_number[0] = digits; */

/*   return_pointer = card_number; */

/*   // if the number is bad, recurse */
/*   if (redo_flag == 1) */
/*   { */
/*     return_pointer = getCardNumber(); */
/*   } */

/*   return return_pointer; */

/* } */
