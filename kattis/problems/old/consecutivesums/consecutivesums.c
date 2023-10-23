#include <stdio.h>
#include <stdbool.h>

bool possible( int n )
{
  bool flag = false;

  // If i even, mid = n / i + 0.5, first = ( mid - 0.5 ) - i / 2 (maybe)
  // If i odd, mid = n / i, first = mid - i / 2
  double mid;
  for ( int i = 2;; i++ ) {
    if ( i % 2 == 0 ) {
      mid = n / i + 0.5;
    } else {
      mid = n / i;
    }

    if ( mid * i > n ) {
      break;
    }
    if ( mid * i == n ) {
      if ( i % 2 == 0 ) {
        mid -= 0.5;
      }

      printf( " = ");
    }
  }

  return flag;
}

int main()
{
  int t;
  scanf( "%d", &t );

  int n;
  for ( int i = 0; i < t; i++ ) {
    scanf( "%d", &n );
    
    if ( !possible( n ) ) {
      printf( "IMPOSSIBLE\n" );
    }
  }
}
