#include <stdio.h>

int getMinXor( n )
{
  for ( int i = 1;; i <<= 1 ) {
    // printf("A");
    if ( ( n ^ i ) > 0 ) {
      return i;
    }
  }
}

int getMin( int n )
{
  int result = 0;
  for ( int i = 1;; i <<= 1 ) {
    // printf("B");
    if ( ( n & i ) > 0 /* && ( n ^ i ) > 0 */ ) { // Why infinite loop?
      result += i;
      break;
    }
  }

  if ( ( n ^ result ) > 0 ) {
    return result;
  } else {
    return result + getMinXor( n );
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
