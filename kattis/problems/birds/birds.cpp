#include <iostream>
#include <set>

#include <stdlib.h>
#include <stdbool.h>

using namespace std;

int adder( int gap, int d ) {
  if ( gap < 0 ) {
    return 0;
  }

  return gap / d + 1;
}

int main()
{
  long long l, d, n;
  cin >> l >> d >> n;
  set<long long> s;
  for ( int i = 0; i < n; i++ ) {
    long long bird;
    cin >> bird;
    s.insert( bird );
  }

  if ( n == 0 ) {
    cout << adder ( l - 12,  d ) << endl;
    return 0;
  }

  long long total = 0;
  set<long long>::iterator it = s.begin();
  total += adder( *it - 6 - d, d );

  long long last = *( --s.end() );
  total += adder( l - last - 6 - d, d );

  if ( n == 1 ) {
    cout << total << endl;
    return 0;
  }

  while ( it != --s.end() ) {
    long long current = *it;
    long long next = *( ++it );

    total += adder( next - current - 2 * d, d );
  }

  cout << total << endl;
  return 0;
}
