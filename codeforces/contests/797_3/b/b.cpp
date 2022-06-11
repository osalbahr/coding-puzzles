#include <iostream>

#include <stdlib.h>
#include <stdbool.h>

using namespace std;

bool solve( int n, int *a, int *b )
{
  int diff = -1;
  int maxZero = -1;
  
  for ( int i = 0; i < n; i++ ) {
    if ( b[ i ] > a[ i ] ) {
      return false;
    }
    
    int currentDiff = a[ i ] - b[ i ];
    
    if ( b[ i ] == 0 ) {
      maxZero = max( maxZero, currentDiff );

      if ( diff != -1 && maxZero > diff ) {
        return false;
      }

      continue;
    }

    if ( diff == -1 ) {
      diff = currentDiff;

      if ( maxZero > diff ) {
        return false;
      }

      continue;
    }

    if ( diff != currentDiff ) {
      return false;
    }
  }
  
  return true;
}

int main()
{
  int t;
  cin >> t;
    
  while ( t-- ) {
    int n;
    cin >> n;

    int *a = (int *)malloc( n * sizeof( int ) );
    int *b = (int *)malloc( n * sizeof( int ) );

    for ( int i = 0; i < n; i++ ) {
      cin >> a[ i ];
    }
    
    for ( int i = 0; i < n; i++ ) {
      cin >> b[ i ];
    }
    
    if ( solve( n, a, b ) ) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
    
    free( a );
    free( b );
  }
}
