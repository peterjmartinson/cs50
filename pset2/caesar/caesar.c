#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char *argv[])
{
  int key = (int) strtol(argv[1], NULL, 10);

  printf("key: %d\n", key);

  return 0;
}

