#include <iostream>
#include <vector>
#include <algorithm>

#include <stdlib.h>
#include <stdbool.h>

using namespace std;

void solve( vector<string> &v )
{
  int size = v.size();
  int maxLen = -1;
  for ( int i = 0; i < size; i++ ) {
    string s = v[ i ];
    reverse( s.begin(), s.end() );
    v[ i ] = s;
    maxLen = max( maxLen, (int)s.size() );
  }
  sort( v.begin(), v.end() );
  for ( int i = 0; i < size; i++ ) {
    string s = v[ i ];
    reverse( s.begin(), s.end() );
    v[ i ] = s;
  }
  for ( int i = 0; i < size; i++ ) {
    string s = v[ i ];
    string padding = "";
    int paddingLength = maxLen - s.size();
    for ( int i = 0; paddingLength > 0 && i < paddingLength; i++ ) {
      padding += " ";
    }
    cout << padding << s << endl;
  }
}

int main()
{
  vector<string> v;
  string s;
  while ( getline(cin, s) ) {
    if ( s.empty() ) {
      solve( v );
      cout << endl;
      v.clear();
    } else {
      v.push_back( s );
    }
  }

  solve( v );
}
