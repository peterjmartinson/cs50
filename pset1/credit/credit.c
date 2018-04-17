#include <stdio.h>
/**

:) credit.c exists.
:) credit.c compiles.
:( identifies 378282246310005 as AMEX
    expected "AMEX\n", not "\nResult (15 di..."
:( identifies 371449635398431 as AMEX
    expected "AMEX\n", not "\nResult (15 di..."
:( identifies 5555555555554444 as MASTERCARD
    expected "MASTERCARD\n", not "\nResult (16 di..."
:( identifies 5105105105105100 as MASTERCARD
    expected "MASTERCARD\n", not "\nResult (16 di..."
:( identifies 4111111111111111 as VISA
    expected "VISA\n", not "\nResult (16 di..."
:( identifies 4012888888881881 as VISA
    expected "VISA\n", not "\nResult (16 di..."
:( identifies 1234567890 as INVALID
    expected "INVALID\n", not "\nResult (10 di..."
:( identifies 369421438430814 as INVALID
    expected "INVALID\n", not "\nResult (15 di..."
:( identifies 4062901840 as INVALID
    expected "INVALID\n", not "\nResult (10 di..."
:( identifies 5673598276138003 as INVALID
    expected "INVALID\n", not "\nResult (16 di..."
:( identifies 4111111111111113 as INVALID
    expected "INVALID\n", not "\nResult (16 di..."
:) rejects a non-numeric input of "foo"
:) rejects a non-numeric input of ""

*/
/**
 * Specifications:
   AMEX - 15 digits
     start with 34 or 37
   MC - 16 digits
     start with 51-55
   Visa - 13 or 16 digits
     start with 4
*/

int * getCardNumber(void);

int main(void)
{

  int i, digits, first_doublet, *card;

  card = getCardNumber();
  digits = card[0];
  first_doublet = card[2] + (10 * card[1]);

  printf("\n");

  printf("Result (%d digits):\n", *card);
  for (i = 1; i < *card + 1; i++) {
    printf("%d ", *(card + i));
  }
  printf("\n");

  // issue: storage is CHAR type, not INT - need to use CHAR codes!
  /* if ( first_doublet >= 51 && first_doublet <= 55  && digits == 16 ) */
    printf("MasterCard: %d\n", first_doublet);

  return 0;
  
}

int * getCardNumber()
{

  printf("Number: ");

  int c, digits = 0, redo_flag = 0, *return_pointer;
  static int card_number[16];

  while ( (c=getchar()) != EOF && c != '\n' )
  {
    if (c < '0' || c > '9' || digits > 15)
    { // If input is not a number, or too many digits
      redo_flag = 1;
    }
    else
    { // Otherwise, push onto the array
      card_number[++digits] = c-48;
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



