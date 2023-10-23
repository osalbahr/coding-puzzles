#include <stdio.h>

int main()
{
  int x[ 3 ];
  int y[ 3 ];
  
  for ( int i = 0; i < 3; i++ ) {
    scanf( "%d%d", &x[ i ], &y[ i ] );
  }
  
  int x4 = x[ 0 ];
  int y4 = y[ 0 ];
  
  int countx = 0;
  int county = 0;
  
  for ( int i = 0; i < 3; i++ ) {
    if ( x4 == x[ i ] ) {
      countx++;
    }
    
    if ( y4 == y[ i ] ) {
      county++;
    }
  }
  
  if ( countx == 2 ) {
    if ( x[ 0 ] != x[ 1 ] ) {
      x4 = x[ 1 ];
    } else {
      x4 = x[ 2 ];
    }
  }

  if ( county == 2 ) {
    if ( y[ 0 ] != y[ 1 ] ) {
      y4 = y[ 1 ];
    } else {
      y4 = y[ 2 ];
    }
  }

  printf( "%d %d\n", x4, y4 );
}
