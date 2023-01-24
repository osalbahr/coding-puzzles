#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool solve()
{
  int n;
  cin >> n;
  vector<int> nums( n );
  for ( int i = 0; i < n; i++ )
    cin >> nums[ i ];
  
  string str;
  cin >> str;
  map<int, char> myMap;
  for ( int i = 0; i < n; i++ ) {
    char ch = str[ i ];
    int num = nums[ i ];

    if ( myMap.count( num ) == 0 ) {
      myMap.insert( pair< int, char >( num, ch ) );
    } else if ( myMap[ num ] != ch ) {
      return false;
    }
  }

  return true;
}

int main()
{
  int t;
  cin >> t;
    
  while ( t-- ) {
    
    if ( solve() )
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
