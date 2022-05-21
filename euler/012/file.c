#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Works for 2 and higher
static int hasDivisors( int divisors )
{
  int current = 0;
  for ( int i = 1;; i++ ) {
    current += i;
    int count = 0;
    for ( int j = 1; j <= current; j++ ) {
      if ( current % j == 0 ) {
        count += 1;
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
  for ( int i = 2; i <= 10; i++ ) {
    printf( "Least number with %d divisors is %d\n", i, hasDivisors( i ) );  
  }

  return EXIT_SUCCESS;
}
