#include <iostream>

#include <stdlib.h>
#include <stdbool.h>

using namespace std;

int n, m, k;
string a, b, str;

int state, c;

void getOne()
{
  if ( state == 1 ) {
    str.push_back( a[ 0 ] );
    a.erase( 0, 1 );
    c++;
  } else {
    str.push_back( b[ 0 ] );
    b.erase( 0, 1 );
    c++;
  }
}

void getOther()
{
  if ( state == 1 ) {
    state = 2;
    str.push_back( b[ 0 ] );
    b.erase( 0, 1 );
    c = 1;
  } else {
    state = 1;
    str.push_back( a[ 0 ] );
    a.erase( 0, 1 );
    c = 1;
  }
}

void solve()
{
  cin >> n >> m >> k >> a >> b;
  str = "";
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  state = a[ 0 ] < b[ 0 ] || ( a[ 0 ] == b[ 0 ] && a.length() < b.length() ) ? 1 : 2;
  c = 0;

  while ( a.length() > 0 && b.length() > 0 ) {
    if ( c == k ) {
      getOther();
      continue;
    }

    int newState = a[ 0 ] < b[ 0 ] || ( a[ 0 ] == b[ 0 ] && a.length() < b.length() ) ? 1 : 2;
    if ( state != newState ) {
      state = newState;
      c = 0;
    }

    getOne();
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
