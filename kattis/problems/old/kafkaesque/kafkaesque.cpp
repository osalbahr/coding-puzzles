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
    v[ i ] = 1000; // Dummy "clear cell" value, since k <= 100
    c++;

    // If the next minimum is in front of you, got get the signature
    int j;
    for (; ( j = min_element( v.begin(),v.end() ) - v.begin() ) > i; v[ j ] = 1000, c++, i = j );
    result++;
  }

  cout << result << endl;
}
