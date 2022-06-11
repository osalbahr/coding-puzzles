#include <iostream>
#include <string>

using namespace std;

int countWhite( int k, string str ) {
  int count = 0;

  for ( int i = 0; i < k; i++ ) {
    if ( str[ i ] == 'W' ) {
      count++;
    }
  }
  
  return count;
}

int solve( int n, int k, string str )
{
  int whiteCount = countWhite( k, str );
  
  int minCount = whiteCount;

  if ( minCount == 0 ) {
    return 0;
  }

  for ( int i = 1; i < n - k; i++ ) {
    char prev = str[ i - 1 ];
    char next = str[ i + k ];

    if ( prev < next ) {
      whiteCount++;
    } else if ( prev > next ) {
      whiteCount--;

      if ( whiteCount == 0 ) {
        return 0;
      }

      minCount = min( minCount, whiteCount );
    }

    
  }

  return minCount;
}

int main()
{
  int t;
  cin >> t;
  
  string str;
  while ( t-- ) {
    int n, k;
    cin >> n >> k >> str;

    cout << solve( n, k, str ) << endl;
  }
}
