#include <stdio.h>

int main()
{
  int x;
  int y;
  int n;
  scanf( "%d%d%d", &x, &y, &n );

  for ( int i = 1; i <= n; i++ ) {
    if ( i % x == 0 && i % y == 0 ) {
      printf( "%s", "FizzBuzz\n" );
    } else if ( i % x == 0 ) {
      printf( "%s", "Fizz\n" );
    } else if ( i % y == 0 ) {
      printf( "%s", "Buzz\n" );
    } else {
      printf( "%d\n", i );
    }
  }
}
