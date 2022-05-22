#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Works for 2 and higher
// static int hasDivisors( int divisors )
// {
//   int current = 0;
//   for ( int i = 1;; i++ ) {
//     current += i;
//     // if ( i % 100 == 0 )
//     //   printf( "current: %d\n", current );

//     // Detect overflow
//     if ( current < 0 ) {
//       printf( "%d%d\n", current, i );
//       exit( 1 );
//     }

//     int count = 0;
//     for ( int j = 1; j <= current; j++ ) {
//       if ( current % j == 0 ) {
//         count += 1;
//       }

//       if ( count >= divisors ) {
//         return current;
//       }
//     }
//   }    
// }

static int hasDivisors( int divisors )
{
  int current = 0;
  for ( int i = 1;; i++ ) {
    current += i;
    // if ( i % 100 == 0 )
    //   printf( "current: %d\n", current );

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


// Solely in vim, this time
int main( int argc, char *argv[] )
{
  for ( int i = 1; i <= atoi(argv[ 1 ]); i++ ) {
    printf( "Least number with %d divisors is %d\n", i, hasDivisors( i ) );  
  }

  return EXIT_SUCCESS;
}
