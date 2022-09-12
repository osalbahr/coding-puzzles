#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

long long fact( long long n )
{
  if ( n == 0 ) {
    return 1;
  }

  return n * fact( n - 1 );
}

long long solve( string s )
{
  map<char, long long> m;

  for ( long long i = 0; i < s.size(); i++ ) {
    m[ s[ i ] ]++;
  }

  long long result = fact( s.size() );

  map<char, long long>::iterator it;
  for ( it = m.begin(); it != m.end(); it++ ) {
    result /= fact( it->second );
  }

  return result;
}

int main()
{
  string s;
  while ( getline( cin, s ) ) {
    cout << solve( s ) << endl;
  }
}
