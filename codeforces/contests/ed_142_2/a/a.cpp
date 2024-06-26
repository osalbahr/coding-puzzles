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

static void solve()
{
  int n;
  cin >> n;
  priority_queue<int> q;
  forn(n) {
    int num;
    cin >> num;
    q.push(num);
  }

  int count = 0;
  while ( !q.empty() && q.top() != 0 ) {
    count++;
    if ( q.top() >= 2) {
      q.pop();
    } else {
      int j = q.top();
      q.pop();
      if ( !q.empty() ) {
        int j = q.top();
        q.pop();
        q.push(j-1);
      }
      q.push(j-1);
    }
  }
  cout << count << endl;
}

int main()
{
  int t;
  cin >> t;
  forn(t)
    solve();
}
