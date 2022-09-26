#include <iostream>
#include <set>
#include <vector>
#include <queue>

#include <cstdio>

using namespace std;

#define REPORT( X ) cout << #X << " = " << X << endl

void printGrid( vector<int> &grid )
{
  for ( int i = 0; i < 8; i++ ) {
    for ( int j = 0; j < 8; j++ ) {
      cout << grid[ 10 * i + j ] << " ";
    }
    cout << endl;
  }
  cout << "---------------" << endl;
}

void solve()
{
  string s;
  cin >> s;
  // letter = row
  // number = col
  int pos = ( s[ 0 ] - 'a' ) * 8 + ( s[ 1 ] - '1' );
  vector<int> moves;

  // Fill the moves vector
  for ( int i = -2; i <= 2; i += 4 )
    for ( int j = -1; j <= 1; j += 2 ) {
      moves.push_back( 10 * i + j );
      moves.push_back( i + j * 10 );
    }
  
  // Correct
  for ( int i = 0; i < moves.size(); i++ )
    cout << moves[ i ] << endl;

  vector<int> grid( 64, -1 );
  grid[ pos ] = 0;

  queue<int> hops;
  hops.push( pos );

  int found = 1;
  int dist = 0;
  // printGrid( grid );
  while ( dist != 10 ) {
    dist++;
    REPORT( dist );
    int size = hops.size();
    REPORT( size );
    for ( int i = 0; i < size; i++ ) {
      int oldPos = hops.front();
      hops.pop();
      for ( int j = 0; j < moves.size(); j++ ) {
        int newPos = oldPos + moves[ j ];
        if ( newPos < 0 || newPos >= 64 || newPos % 10 == 8 || newPos % 10 == 9 || grid[ newPos ] != -1 ) { continue; }
        grid[ newPos ] = dist;
        found++;
        hops.push( newPos );
      }
    }

    printGrid( grid );
  }

  int size = hops.size();
  // for ( int i = 0; i < size; i++ ) {
  //   cout << hops.front() << endl;
  //   hops.pop();
  // }
}

int main()
{
  int t;
  cin >> t;
    
  while ( t-- ) {
    solve();
  }
}
