#include <iostream>

#include <stdlib.h>
#include <stdbool.h>

using namespace std;

void solve()
{
  int n, m, k;
  string a, b, str;
  cin >> n >> m >> k >> a >> b;
  str = "";
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  cout << a << "\n" << b << endl;

  int state = 0;
  int count = 0;

  while ( a.length() > 0 && b.length() > 0 ) {
    string temp;
    if ( count == k ) {
      cout << "A" << endl;
      state = state == 1 ? 2 : 1;
      if ( state == 1 ) {
        temp = a.erase( 0, 1 );
      } else {
        temp = b.erase( 0, 1 );
      }
      str.append( temp );
      count = 1;
      continue;
    }

    if ( a[ 0 ] < b[ 0 ] ) {
      if ( state == 1 ) {
        temp = a.erase( 0, 1 );
        count++;
      } else {
        state = 1;
        count = 1;
        temp = a.erase( 0, 1 );
      }
    } else { // if ( b[ 0 ] < a[ 0 ] ) {
      if ( state == 2 ) {
        temp = b.erase( 0, 1 );
        count++;
      } else {
        state = 2;
        count = 1;
        temp = b.erase( 0, 1 );
      }
    }
    
    str.append( temp );
  }

  cout << str << endl;
}

int main()
{
  int t;
  cin >> t;
    
  while ( t-- ) {
    
    solve();
  }
}
