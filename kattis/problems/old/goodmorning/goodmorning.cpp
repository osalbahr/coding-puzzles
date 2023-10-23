#include <iostream>
#include <set>

using namespace std;

set<int> poss;

int rows = 4;
int cols = 3;

char grid[ 4 ][ 3 ] =
  { { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 },
    { -1, 0, -1 } };

int main()
{
  for ( int i = 0; i < 4; i++ ) {
    for ( int j = 0; i < 3; j++ ) {
      int start = grid[ i ][ j ];
      if ( start == -1 )
        break;

      poss.insert( start );
      goRight( start, i, j );
      goDown( start, i, j );
    }
  }

  int t;
  cin >> t;

  while ( t-- ) {
    
  }
}
