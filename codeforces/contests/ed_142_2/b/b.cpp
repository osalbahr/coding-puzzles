#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>    // stringstream
#include <algorithm>  // sort
#include <queue>
#include <stack>
#include <numeric>      // std::accumulate

// C
#include <cstdio>
#include <cstdlib>  // atoi, malloc
#include <climits>  // INT_MIN
#include <ctype.h>  // isdigit
// #include <cstring>  // I mean, if you really wanted to

using namespace std;

// For debugging
#define REPORT( X ) cout << #X " = " << X << endl
// like echo -n
#define REPORTN( X ) cout << #X << " = " << ( X ) << ", "
#define REPORTP( M ) fprintf( stdout, "%s = (%d,%d)\n", #M, M.row, M.col )

// Aliasing
#define forn( X ) \
for ( int i_ = 0; i_ < ( X ); i_++ )

// Point syntactic sugar
typedef pair<int,int> pi;
// Grid
#define row first
#define col second
// Raw points
// #define x first
// #define y second
#define mp make_pair

// Apadted from
// https://stackoverflow.com/a/21956177/18633613
// (https://stackoverflow.com/questions/21956119/add-stdpair-with-operator)
pi operator+(const pi& a, const pi& b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

// Scaling
pi operator*(const int a, const pi& p) {
    return {a * p.first, a * p.second};
}




// Add program state (global variables) here

static void printAll( vector<int> v, int a, int b )
{
  REPORT( a );
  REPORT( b );
  forn(v.size())
    cout << v[i_] << ", ";
  cout << endl;
}

static void solve()
{
  // cout << "------" << endl;
  vector<int> j(4);
  forn(4)
    cin >> j[i_];

  int total = accumulate(j.begin(), j.end(), 0);
  
  // forn(4)
  //   cout << j[i_] << ", ";
  // cout << endl;

  int a = j[0], b = j[0];
  j[0] = 0;

  // cout << total << endl;
  for (;;) {
    // printAll(j, a, b);
    if ( j[1] > 0 && b > 0 ) {
      int c = min( j[1], b );
      a += c;
      j[1] -= c;
      b -= c;
    } else if ( j[2] > 0 && a > 0 ) {
      int c = min( j[2], a );
      b += c;
      j[2] -= c;
      a -= c;
    } else {
      break;
    }
  }

  // bad jokes
  if( a > 0 && b > 0 && j[3] > 0 ) {
    int c = min( a, b );
    c = min( c, j[3] );
    j[3] -= c;
  }

  int rem = accumulate(j.begin(), j.end(), 0);
  if ( rem > 0 )
    cout << total - rem + 1 << endl;
  else
    cout << total << endl;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
    solve();
}
