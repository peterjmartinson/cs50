/**
 * Runs credit card numbers through a validation algorithm
 * 2018 (c) Peter Martinson
 * 
 * 1. Multiply every other digit by 2, starting at the penultimate digit
 * 2. Add all digits of the above products together
 * 3. Add the above sum to the sum of all the other digits
 * 4. If the last digit of this final sum is zero, the number is valid
 * 
 * Note:  For step 1, the maxiumum product is 9*9=18.  So, for products greater
 * than 9, the sum of digits is the same as the last digit minus nine.  For
 * example, take 15.  1+5 = 6 = 15-9.
 */
#include <stdio.h>

int * getCardNumber(void);
int validateCardNumber(int *);

int main(void)
{
  int digits, *card, valid_number = 0;

  card = getCardNumber();
  digits = card[0];
  valid_number = validateCardNumber(card);

  if (valid_number != 0)
    printf("INVALID\n");

  else if (card[1] == 3 && (card[2] == 4 || card[2] == 7) && digits == 15)
    printf("AMEX\n");

  else if (card[1] == 5 && (card[2] >= 1 && card[2] <= 5) && digits == 16)
    printf("MASTERCARD\n");

  else if (card[1] == 4 && (digits == 13 || digits == 16))
    printf("VISA\n");

  else
    printf("INVALID\n");

  return 0;
}

int * getCardNumber()
{

  printf("Number: ");

  int c, digits = 0, redo_flag = 0, *return_pointer;
  static int card_number[17];

  while ((c=getchar()) != EOF && c != '\n')
  {
    if (c < '0' || c > '9' || digits > 15)
    {
      redo_flag = 1;
    }
    else
    {
      card_number[++digits] = c - 48;
    }
  }

  card_number[0] = digits;

  return_pointer = card_number;

  // if the number is bad, recurse
  if (redo_flag == 1)
  {
    return_pointer = getCardNumber();
  }

  return return_pointer;

}

int validateCardNumber(int *p)
{
  int length = p[0], sum = 0, i;

  for (i = length - 1; i >= 0; i = i - 2)
  {
    if (i != 0) // This prevents first element from being counted
    {
      if (p[i] * 2 >= 10)
        sum += p[i] * 2 - 9;
      else
        sum += p[i] * 2;
    }
    sum += p[i + 1];
  }
    
  return sum % 10;
}
