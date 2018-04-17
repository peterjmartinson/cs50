#include <stdio.h>


int * getCardNumber(void);
int validateCardNumber(int *);

int main(void)
{

  int i, digits, *card, valid_number = 0;

  card = getCardNumber();
  digits = card[0];
  valid_number = validateCardNumber(card);

  printf("\n");

  if ( card[1] == 3 && (card[2] == 4 || card[2] == 7) && digits == 15 )
    printf("AMEX\n");
  else if ( card[1] == 5 && (card[2] >= 1 && card[2] <= 5) && digits == 16 )
    printf("MC\n");
  else if ( card[1] == 4 && (digits == 13 || digits == 16 ) )
    printf("Visa\n");
  else
    printf("INVALID\n");

  return 0;
  
}

int * getCardNumber()
{

  printf("Number: ");

  int c, i, digits = 0, redo_flag = 0, *return_pointer;
  static int card_number[16];

  while ( (c=getchar()) != EOF && c != '\n' )
  {
    if (c < '0' || c > '9' || digits > 15)
    { // If input is not a number, or too many digits
      redo_flag = 1;
    }
    else
    { // Otherwise, push onto the array
      card_number[++digits] = c - 48;
    }
  }

  // First element of array stores length of number
  card_number[0] = digits;

  // Hand address of first element to a pointer
  return_pointer = card_number;

  // if the number is bad, recurse
  if (redo_flag == 1)
  {
    return_pointer = getCardNumber();
  }

  return return_pointer;

}

int validateCardNumber(int *p) {
  return 0;
}
