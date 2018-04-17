#include <stdio.h>
/**

:) credit.c exists.
:) credit.c compiles.
:( identifies 378282246310005 as AMEX expected "AMEX\n", not "\nResult (15 di..."
:( identifies 371449635398431 as AMEX expected "AMEX\n", not "\nResult (15 di..."
:( identifies 5555555555554444 as MASTERCARD expected "MASTERCARD\n", not "\nResult (16 di..."
:( identifies 5105105105105100 as MASTERCARD expected "MASTERCARD\n", not "\nResult (16 di..."
:( identifies 4111111111111111 as VISA expected "VISA\n", not "\nResult (16 di..."
:( identifies 4012888888881881 as VISA expected "VISA\n", not "\nResult (16 di..."
:( identifies 1234567890 as INVALID expected "INVALID\n", not "\nResult (10 di..."
:( identifies 369421438430814 as INVALID expected "INVALID\n", not "\nResult (15 di..."
:( identifies 4062901840 as INVALID expected "INVALID\n", not "\nResult (10 di..."
:( identifies 5673598276138003 as INVALID expected "INVALID\n", not "\nResult (16 di..."
:( identifies 4111111111111113 as INVALID expected "INVALID\n", not "\nResult (16 di..."
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

   Checksums:
   1. Multiply every other digit by 2, starting with second-last digit
   2. Add those products together
   3. Add that sum to the sum of all the other digits
   4. If last digit is 0, the number is valid
*/

int * getCardNumber(void);
int validateCardNumber(int *);

int main(void)
{

  int i, digits, *card, valid_number = 0;

  card = getCardNumber();
  digits = card[0];
  valid_number = validateCardNumber(card);

  printf("\n");

  if ( valid_number != 0 )
    printf("INVALID - checksum = %d\n", valid_number);
  else if ( card[1] == 3 && (card[2] == 4 || card[2] == 7) && digits == 15 )
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
  int length = p[0];
  int first_sum = 0;
  int final_sum = 0;
  int i;

    printf("\np[i] p[i+1] first_sum final_sum\n");
  for (i = length - 1; i > 0; i = i - 2)
  {
    first_sum += p[i] * 2;
    final_sum += p[i + 1];
    printf("%d %d %d %d\n", p[i], p[i+1], first_sum, final_sum);
  }
    
  return (first_sum + final_sum)%10;
}
