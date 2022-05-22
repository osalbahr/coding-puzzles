#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// This time, in vim
int main()
{
  long result = 0;
  char current[ 50 + 1 ];
  
  while( scanf( "%s", current ) == 1 ) {
    long temp;
    sscanf( current + 40, "%ld", &temp );
    result += temp;
    result %= 10000000000;
  }

  printf( "Ans: %ld\n", result ); 

  return EXIT_SUCCESS;
}
