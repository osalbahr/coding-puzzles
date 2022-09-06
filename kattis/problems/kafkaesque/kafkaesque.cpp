#include <iostream>
#include <vector>
#include <algorithm>

#include <stdlib.h>
#include <stdbool.h>

#define REPORT( X ) //printf( "%s = %d\n", #X, (X) )

using namespace std;

int main()
{
  int k;
  cin >> k;
  vector<int> v( k );
  for ( int i = 0; i < k; i++ ) {
    cin >> v[ i ];
  }

  int c = 0, result = 0;
  while ( c < k ) {
    int i = min_element( v.begin(),v.end() ) - v.begin();
    REPORT( i );
    v[ i ] = 1000;
    c++;

    int j = min_element( v.begin(),v.end() ) - v.begin();
    while ( j > i ) {
      v[ j ] = 1000;
      c++;
      if ( c == k ) {
        break;
      }
      i = j;
      j = min_element( v.begin(),v.end() ) - v.begin();
    }

    result++;
  }

  cout << result << endl;
}
