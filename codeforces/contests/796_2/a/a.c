#include <stdio.h>

int getMin( int n )
{
  for ( int i = 1;; i++ ) {
    if ( ( n & i ) > 0 && ( n ^ i ) > 0 ) {
      // printf( "%d:%d\n", n, i );
      // printf( "%d:%d\n", ( n & i ) > 0 , ( n | i ) > 0 );
      return i;
    }
  }
}

int main()
{
  int t;
  scanf( "%d", &t );

  for ( int i = 0; i < t; i++ ) {
    int n;
    scanf( "%d", &n );

    printf( "%d\n", getMin( n ) );
  }
}
