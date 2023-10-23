#include <iostream>

#include <stdlib.h>
#include <stdbool.h>

using namespace std;

#define REPORT( X ) //printf( "%s = %d\n", #X, (X) )

bool solve()
{
  int s, v1, v2;
  cin >> s >> v1 >> v2;

  int n1 = s / v1, n2 = 0;

  s %= v1;
  n2 = s / v2;
  s %= v2;

  REPORT( n1 );
  REPORT( n2 );
  // printf( "%d\n", 1000 - n1 * v1 + n2 * v2 );
  REPORT( s );
  while ( s != 0 ) {
    if ( n1 == 0 ) {
      return false;
    }

    n1--;
    s += v1;
    // while ( s > 0 ) {
      n2 += s / v2;
      s -= (s / v2) * v2;
    // }

    REPORT( n1 );
    REPORT( n2 );
    // printf( "%d\n", 1000 - ( n1 * v1 + n2 * v2 ) );
    REPORT( s );
  }

  cout << n1 << " " << n2 << endl;
  return true;
}

int main()
{
  if ( !solve() ) {
    cout << "Impossible" << endl;
  }
}
