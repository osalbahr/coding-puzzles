#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>    // stringstream
#include <algorithm>  // sort
#include <queue>
#include <stack>
#include <list>

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

// https://codeforces.com/contest/1777/submission/190315240
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

static void solve()
{
  int n;
  cin >> n;
  int n1, n2;
  cin >> n1;
  // n1 %= 2;
  int count = 0;
  while( --n ) {
    cin >> n2;
    // n2 %= 2;
    count += (n1 %2) == (n2 % 2);
    n1 = n2;
  }

  // int count = 0;
  // forn( n - 1 ) {
  //   count += l[i_] == l[i_ + 1];
  // }
  cout << count << endl;
}

int main()
{
  fast();

  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}
