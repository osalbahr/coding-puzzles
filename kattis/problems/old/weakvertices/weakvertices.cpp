#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve( int n )
{
  vector<int> r( n );
  vector< vector<int> > graph( n, r );

  for ( int i = 0; i < n; i++ )
    for ( int j = 0; j < n; j++ )
      cin >> graph[ i ][ j ];

  // Assume they are all weak
  set<int> weak;
  for ( int i = 0; i < n; i++ ) {
    weak.insert( i );
  }

  for ( int i = 0; i < n; i++ ) {
    if ( weak.count( i ) == 0 )
      continue;

    bool isWeak = true;
    for ( int j = 0; j < n && isWeak; j++ ) {
      for ( int k = 0; k < n && isWeak; k++ ) {
        if ( graph[ i ][ j ] == 1
            && graph[ i ][ k ] == 1
            && graph[ j ][ k ] == 1 ) {

          weak.erase( i );
          weak.erase( j );
          weak.erase( k );
          isWeak = false;
        }
      }
    }
  }

  set<int>::iterator it;
  for ( it = weak.begin(); it != weak.end(); it++ ) {
    cout << *it << " ";
  }
  cout << endl;
}

int main()
{
  int n;    
  while ( cin >> n && n != -1 ) {
    solve( n );
  }
}
