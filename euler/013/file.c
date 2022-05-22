#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
  long result = 0;
  char current[ 50 + 1 ];
  
  while( scanf( "%s", current ) == 1 ) {
    // We only need three more, becauese 10 * 50 = 500
    current[ 10 + 3 ] = '\0';

    long temp;
    sscanf( current, "%ld", &temp );
    // printf( "%ld\n", temp );
    result += temp;
  }

  printf( "Ans: %ld\n", result ); 

  return EXIT_SUCCESS;
}
