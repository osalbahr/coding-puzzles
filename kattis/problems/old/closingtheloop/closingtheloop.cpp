#include <iostream>
#include <algorithm>
#include <vector>

#include <stdlib.h>

#define REPORT( X ) printf( "%s = %d\n", #X, (X) )

using namespace std;

int solve()
{
  int s;
  cin >> s;
  vector<int> b;
  vector<int> r;

  for ( int i = 0; i < s; i++ ) {
    string str;
    cin >> str;
    int size = str.size();
    char color = str[ size - 1 ];
    str = str.substr( 0, size - 1 );
    int current = stoi( str );

    if ( color == 'B' ) {
      b.push_back( current );
    } else {
      r.push_back( current );
    }
  }

  if ( b.size() == 0 || r.size() == 0 ) {
    return 0;
  } 

  sort( b.begin(), b.end() );
  sort( r.begin(), r.end() );

  int ib = b.size() - 1, ir = r.size() - 1;
  int result = 0;
  char startColor;
  if ( b[ ib ] > r[ ir ] ) {
    result += b[ ib-- ];
    startColor = 'B';
  } else {
    result += r[ ir-- ];
    startColor = 'R';
  }

  char currentColor = startColor;
  int knots = 1;
  for (; ;) {
    if ( currentColor == 'R' ) {
      result += b[ ib-- ];
      knots++;
      currentColor = 'B';
      if ( ir == -1 ) break;
    } else {
      result += r[ ir-- ];
      knots++;
      currentColor = 'R';
      if ( ib == -1 ) break;
    }
  }

  if ( startColor == currentColor ) {
    if ( currentColor == 'R' ) {
      result -= r[ ir + 1 ];
    } else {
      result -= b[ ib + 1 ];
    }
    knots--;
  }

  return result - knots;
}

int main()
{
  int t;
  cin >> t;
    
  for ( int i = 1; i <= t; i++ ) {
    cout << "Case #" << i << ": " << solve() << endl;
  }
}
