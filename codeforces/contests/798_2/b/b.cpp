#include <iostream>

#include <stdlib.h>
#include <stdbool.h>

using namespace std;

int cmp( const void *a, const void *b ) {
  return *(int *)a - *(int *)b;
}

bool solve()
{
  int n;
  cin >> n;

  if ( n == 1 ) {
    return false;
  }

  int listA[ 1000 ];
  int listB[ 1000 ];
  int listC[ 1000 ];

  for ( int i = 0; i < n; i++ ) {
    int current;
    cin >> current;
    listA[ i ] = current;
    listB[ i ] = current;
  }

  if ( n == 2 ) {
    cout << listA[ 1 ] << " " << listA[ 0 ];
    return true;
  }

  qsort( listB, n, sizeof( int ), cmp );

  int idx = 0;
  for ( int i = 0; i < n - 1; i++ ) {
    int j;
    for ( j = 0; listB[ j ] < 0 || listA[ idx ] == listB[ j ]; j++ ) {
      if ( j == n ) return false;
    }

    listC[ idx++ ] = listB[ j ];
    listB[ j ] = -1;
  }

  if ( listA[ n - 1 ] == listB[ n - 1 ] ) {
    listC[ n - 1 ] = listC[ n - 2 ];
    listC[ n - 2 ] = listB[ n - 1 ];
  } else {
    listC[ n - 1 ] = listB[ n - 1 ];
  }

  for ( int i = 0; i < n; i++ ) {
    cout << listC[ i ] << " ";
  }

  return true;
}

int main()
{
  int t;
  cin >> t;

  while ( t-- ) {
    
    if ( solve() ) {
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
