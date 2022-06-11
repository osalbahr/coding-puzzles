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
    str.append( a.erase( 0, 1 ) );
    c++;
  } else {
    str.append( b.erase( 0, 1 ) );
    c++;
  }
}

void getOther()
{
  if ( state == 1 ) {
    state = 2;
    str.append( b.erase( 0, 1 ) );
    c = 1;
  } else {
    state = 1;
    str.append( a.erase( 0, 1 ) );
    c = 1;
  }
}

void solve()
{
  int n, m, k;
  string a, b, str;
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

    state = a[ 0 ] < b[ 0 ] || ( a[ 0 ] == b[ 0 ] && a.length() < b.length() ) ? 1 : 2;

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
