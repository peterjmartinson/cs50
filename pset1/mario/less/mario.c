// mario (less)

#include <stdio.h>
#include <cs50.h>

int getHeight();
void printSpace(int n);
void printHash(int n);
void printNewLine();

int main(void)
{
  int max_height = getHeight();

  for (int current_height = 1; current_height <= max_height; current_height++)
  {
    printSpace(max_height - current_height);
    printHash(current_height + 1);
    printNewLine();
  }

}

/**
 * Prompts the user for a number between 0 and 23
*/
int getHeight()
{
  int h;

  do
  {
    h = get_int("height: ");
  } while (h < 0 || h > 23);
  return h;
}

/**
 * Prints n spaces
*/
void printSpace(int n)
{
  for(int i = 0; i < n; i++)
  {
    printf(" ");
  }
}

/**
 * Prints n `#` characters
*/
void printHash(int n)
{
  for(int i = 0; i < n; i++)
  {
    printf("#");
  }
}

/**
 * Prints a new line character
*/
void printNewLine()
{
  printf("\n");
}
