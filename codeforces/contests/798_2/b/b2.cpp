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
  bool removed[ 1000 ] = {};
  int listA[ 1000 ];
  int listB[ 1000 ];
  int listC[ 1000 ];

  for ( int i = 0; i < n; i++ ) {
    int current;
    cin >> current;
    listA[ i ] = current;
    listB[ i ] = current;
  }

  qsort( listB, n, sizeof( int ), cmp );

  int idx = 0;
  for ( int i = 0; i < n; i++ ) {
    int j = 0;

    while ( removed[ j ] || listA[ idx ] == listB[ j ] ) {
      j++;
      if ( j == n ) return false;
    }

    listC[ idx++ ] = listB[ j ];
    removed[ j ] = true;
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
