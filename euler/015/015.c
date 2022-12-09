#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int depth = 0;

// n x n has n x n + 1 corners
int size = 2 + 1;

typedef struct PointTag {
  int i;
  int j;
} Point;

// Recursively get the number of pahts
// (i, j) -> (size-1, size-1)
static long getPaths( int i, int j )
{
  depth++;
  // printf( "size = %d, i = %d, j = %d, depth = %d\n", size, i, j, depth );
  // cout << i << endl;
  // cout << j << endl;
  // cout << endl;

  if ( i == size - 1 && j == size - 1 )
    return 1;
  
  // Shortcut
  // if ( i == j )
  //   return 2 * getPaths( i + 1, j );
  
  long total = 0;

  // Try right
  if ( i + 1 < size ) {
    if ( i + 1 < size )
      total += getPaths( i + 1, j );
  }
  
  // Try down;
  if ( j + 1 < size )
    total += getPaths( i, j + 1 );

  return total;
}

int main( int argc, char *argv[] )
{
  if ( argv[ 1 ] )
    size = atoi( argv[ 1 ] );

  printf( "%ld\n", getPaths( 0, 0 ) );
  printf( "depth = %d\n", depth );
}