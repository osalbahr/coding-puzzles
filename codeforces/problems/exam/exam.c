#include <stdio.h>
#include <stdlib.h>

int main()
{
  int d;
  int sumTime;

  scanf( "%d %d", &d, &sumTime );

  int minTime[ 30 ];
  int maxTime[ 30 ];

  int maxPossible = 0;
  int minPossible = 0;
  for ( int i = 0; i < d; i++ ) {
    scanf( "%d %d", &minTime[ i ], &maxTime[ i ] );
    maxPossible += maxTime[ i ];
    minPossible += minTime[ i ];
  }

  if ( maxPossible < sumTime || minPossible > sumTime ) {
    printf( "NO\n" );
    return EXIT_SUCCESS;
  } else {
    printf( "YES\n" );
  }

  sumTime -= minPossible;
  for ( int i = 0; i < d; i++ ) {
    int current = minTime[ i ];

    if ( sumTime > 0 ) {
      sumTime -= maxTime[ i ] - current;
      current = maxTime[ i ];
      if ( sumTime < 0 ) {
        current += sumTime;
      }
    }

    printf( "%d ", current );
  }
  printf( "\n" );
}
