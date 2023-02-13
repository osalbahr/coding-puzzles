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

map<int,set<int>> canGo;
map<pi,int> costs;

// static void print( int n, int k, vector<tuple<int,int,int>> r)
// {
//   cout << n << " " << k << endl;
//   for (const auto& [u, v, c] : r)
//     cout << u << " " << v << " " << c << endl;
// }

int main()
{
  int n, k;
  cin >> n >> k;
  vector<tuple<int,int,int>> r;
  int u, v, c;

  // Construct paths
  while (cin >> u >> v >> c) {
    canGo[u].insert(v);
    canGo[v].insert(u);
    costs[{u,v}] = c;
    costs[{v,u}] = c;

    r.push_back({u, v, c});
  }

  int maxSoFar = 0;
  set<pi> visitedEdge;
  for (int i = 1; i <= n; i++) {
    int n = *canGo[i].begin();
    // Oops
    if (visitedEdge.count({i,n}) > 0)
      continue;
    
    queue<pi> toVisit;
    for (int n : canGo[i])
      toVisit.push({i, n});

    int total = 0;
    while (!toVisit.empty()) {
      auto& [u, v] = toVisit.front();

      visitedEdge.insert({u, v});
      visitedEdge.insert({v, u});

      total += costs[{u, v}];

      for (int n : canGo[v]) {
        pi p = {v, n};
        if (visitedEdge.count(p) == 0)
          toVisit.push(p);
      }

      toVisit.pop();
    }

    maxSoFar = max(maxSoFar, total);
  }

  cout << maxSoFar << endl;
}
