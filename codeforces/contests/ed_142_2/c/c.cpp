#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>    // stringstream
#include <algorithm>  // sort
#include <queue>
#include <stack>

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

static pi minMax( vector<int> &v )
{
  pi idx;
  int minN = INT_MAX, maxN = INT_MIN;
  forn((int)v.size()) {
    int num = v[ i_ ];
    if ( num != i_ + 1 ) {
      if ( minN != min(minN, v[i_] ) ) {
        minN = min(minN, v[i_] );
        idx.first = i_;
      }
      if ( maxN != max(maxN, v[i_] ) ) {
        maxN = max(minN, v[i_] );
        idx.second = i_;
      }
    }
  }

  // REPORT( minN );
  // REPORT( idx.first );
  // REPORT( maxN );
  // REPORT( idx.second );

  if (minN != INT_MAX) {
    int temp = v[idx.first];
    v[idx.first] = v[idx.second];
    v[idx.second] = temp;
  }

  cout << minN << endl;
  cout << maxN << endl;

  return {minN, maxN};
}

static void printV(vector<int> v)
{
  for ( size_t idx = 0; idx < v.size(); idx++ ) {
    cout << v[idx] << ",";
  }
  cout << endl;
}

static void solve()
{
  int n;
  cin >> n;
  vector<int> v(n);
  forn(n)
    cin >> v[i_];

  int count = 0;
  while ( minMax(v).first != INT_MAX ) {
    printV(v);
    count++;
  }
  cout << count << endl;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
    solve();
}
