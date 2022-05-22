#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MILLION 1000000

static int nextCollatz( int n )
{
  if ( n % 2 == 0 ) {
    return n / 2;
  }

  int next = 3 * n + 1;
  
  // Detect overflow
  if ( ( next - 1 ) / 3 != n ) {
    printf( "Bad %d, next %d", n, next );
    exit( EXIT_FAILURE );
  }

  return next;
}

static int collatzLength( int n )
{
  int current = n;
  int length = 0;

  printf( "%d", n );
  while ( current != 1 ) {
    current = nextCollatz( current );
    printf( " -> %d", current );
    length++;
  }
  printf( "\n" );

  return length;
}

int main()
{
  int length = 0;
  int result;

  for ( int i = 1; i <= MILLION; i++ ) {
    int currentLength = collatzLength( i );
    printf( "For %d: length is %d\n", i, currentLength );

    if ( currentLength > length ) {
      result = i;
      length = currentLength;
    }
  }

  fprintf( stderr, "%d:%d\n", result, length );

  return EXIT_SUCCESS;
}
