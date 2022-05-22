#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Works for 2 and higher
static int hasDivisors( int divisors )
{
  int current = 0;
  for ( int i = 1;; i++ ) {
    current += i;

    // Detect overflow
    if ( current < 0 ) {
      printf( "%d%d\n", current, i );
      exit( 1 );
    }

    int count = 0;
    int cap = sqrt( current );
    for ( int j = 1; j <= cap; j++ ) {
      if ( current % j == 0 ) {
        count += 2;
        if ( j == cap ) {
          count--;
        }
      }

      if ( count >= divisors ) {
        return current;
      }
    }
  }    
}

int main( int argc, char *argv[] )
{
  int targest = 501;
  printf( "Least number with %d divisors is %d\n", targest, hasDivisors( targest ) );

  return EXIT_SUCCESS;
}
