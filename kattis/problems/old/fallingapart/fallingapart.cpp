#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> v( n );

  for ( int i = 0; i < n; i++ ) {
    cin >> v[ i ];
  }
  sort( v.begin(), v.end() );
  
  int a = 0, b = 0;

  for ( int i = n - 1; i >= 0; i -= 2 ) {
    a += v[ i ];
  }
  
  for ( int i = n - 2; i >= 0; i -= 2 ) {
    b += v[ i ];
  }

  cout << a << " " << b << endl;
}
