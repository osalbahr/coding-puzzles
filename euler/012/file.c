#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Works for 2 and higher
static int hasDivisors( int divisors )
{
  int current = 0;
  for ( int i = 1;; i++ ) {
    current += i;
    int temp = current;

    for ( int j = 1; temp != 1; j++ ) {
      int count = 0;

      if ( temp % j == 0 ) {
        temp /= j;
        count += 2;
      }

      if ( count >= divisors ) {
        return current;
      }
    }
  }    
}

// Solely in vim, this time
int main()
{
  printf( "Least number with %d divisors is %d", 5, hasDivisors( 5 ) );  

  return EXIT_SUCCESS;
}
