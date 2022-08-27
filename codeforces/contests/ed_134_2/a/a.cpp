#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solve()
{
  string s, s2;
  cin >> s >> s2;
  s = s + s2;
  sort( s.begin(), s.end() );

  if ( count( s.begin(), s.end(), s[0] ) == 4 ) {
    return 0;
  }

  if ( s[0] == s[1] && s[2] == s[3] ) {
    return 1;
  }

  for ( int i = 0; i < 2; i++ ) {
    if ( count( s.begin(), s.end(), s[i] ) == 3 ) {
      return 1;
    }
  }

  for ( int i = 0; i < 3; i++ ) {
    if ( count( s.begin(), s.end(), s[i] ) == 2 ) {
      return 2;
    }
  }

  return 3;
}

int main()
{
  int t;
  cin >> t;
    
  while ( t-- ) {
    cout << solve() << endl;
  }
}
