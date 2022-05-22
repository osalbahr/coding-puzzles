#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MILLION 1000000

static long nextCollatz( long n )
{
  if ( n % 2 == 0 ) {
    return n / 2;
  }

  long next = 3 * n + 1;
  
  // Detect overflow
  if ( ( next - 1 ) / 3 != n ) {
    printf( "Bad %ld, next %ld", n, next );
    exit( EXIT_FAILURE );
  }

  return next;
}

static int collatzLength( int n )
{
  long current = n;
  int length = 0;

  // printf( "%d", n );
  while ( current != 1 ) {
    current = nextCollatz( current );
    // printf( " -> %ld", current );
    length++;
  }
  // printf( "\n" );

  return length;
}

int main()
{
  int length = 0;
  int result;

  for ( int i = 1; i <= MILLION; i++ ) {
    int currentLength = collatzLength( i );
    // printf( "For %d: length is %d\n", i, currentLength );

    if ( currentLength > length ) {
      result = i;
      length = currentLength;
      fprintf( stderr, "%d:%d\n", result, length );
    }
  }

  // fprintf( stderr, "%d:%d\n", result, length );

  return EXIT_SUCCESS;
}
