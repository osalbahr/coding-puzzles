#include <stdio.h>

int main()
{
  int counts[ 41 ] = {};

  int faces1;
  int faces2;

  scanf( "%d%d", &faces1, &faces2 );

  for ( int i = 1; i <= faces1; i++ ) {
    for ( int j = 1; j <= faces2; j++ ) {
      counts[ i + j ]++;
    }
  }

  int max = faces1 + faces2;
  int maxCount = 0;
  for ( int i = 1; i <= max; i++ ) {
    int current = counts[ i ];
    if ( current > maxCount ) {
      maxCount = current;
    }
  }
  
  for ( int i = 1; i <= max; i++ ) {
    if ( counts[ i ] == maxCount ) {
      printf( "%d\n", i );
    }
  }
}
