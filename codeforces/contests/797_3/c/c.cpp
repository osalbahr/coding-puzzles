#include <iostream>

#include <stdlib.h>
#include <stdbool.h>

using namespace std;

int max( int a, int b ) {
  return a >= b ? a : b;
}

void solve( int n, int *s, int *f )
{
  int result;
  for ( int i = 0; i < n; i++, cout << result << " " ) {
    int start;
    if ( i == 0 ) {
      start = s[ i ];
    } else {
      start = max( s[ i ], f[ i - 1 ] );
    }

    result = f[ i ] - start;
  }

  cout << endl;
}

int main()
{
  int t;
  cin >> t;
    
  while ( t-- ) {
    int n;
    cin >> n;

    int *s = (int *)malloc( n * sizeof( int ) );
    int *f = (int *)malloc( n * sizeof( int ) );

    for ( int i = 0; i < n; i++ ) {
      cin >> s[ i ];
    }
    
    for ( int i = 0; i < n; i++ ) {
      cin >> f[ i ];
    }
    
    solve( n, s, f );
    
    free( s );
    free( f );
  }
}
