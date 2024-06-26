// #define DEBUG

#include <iostream>
#include <vector>
#include <set>
#include <queue>

#include <stdlib.h>
#include <stdbool.h>

using namespace std;

#ifdef DEBUG
#define REPORT( X ) cout << #X << " = " << X << endl;
#define REPORTP( P ) printf( "%s = %d (%d,%d)\n", #P, grid[ P.row ][ P.col ], P.row + 1, P.col + 1 )
#else
#define REPORT( X )
#define REPORTP( P )
#endif

typedef pair<int,int> pi;
#define row first
#define col second

int rows, cols;
pi endPoint;
vector<pi> moves = { {-1, 0}, {0, -1}, {0, 1}, {1, 0 } };

pi operator+( const pi& a, const pi& b )
{
  return { a.first + b.first,
          a.second + b.second };
}

static bool legal( pi p )
{
  if ( p.first < 0 || p.first >= rows )
    return false;
  if ( p.second < 0 || p.second >= cols )
    return false;
  return true;
}

typedef struct {
  int heightDiff;
  pi src;
  pi point;
} MoveInfo;

bool operator>( const MoveInfo& lhs, const MoveInfo& rhs )
{
  return lhs.heightDiff > rhs.heightDiff;
}

vector<vector<int>> grid;
set<pi> visited;

priority_queue<MoveInfo, vector<MoveInfo>, greater<MoveInfo>> toVisit;

// Debugging 3.in
#ifdef DEBUG
static void printQ()
{
  auto cpy = toVisit;
  while ( !cpy.empty() ) {
    auto& cur = cpy.top();
    auto& src = cur.src;
    auto& point = cur.point;
    printf( "Q: %d (%d,%d)[%d] -> (%d,%d)[%d]\n", cur.heightDiff,
            src.row + 1, src.col + 1, grid[ src.row ][ src.col ],
            point.row + 1, point.col + 1, grid[ point.row ][ point.col ] );
    cpy.pop();
  }
}

static void printGrid()
{
  for ( int r = 0; r < rows; r++ ) {
    for ( int c = 0; c < cols; c++ ) {
      pi p = { r, c };
      if ( visited.count( p ) > 0 )
        printf( "X%2dX ", grid[ r ][ c ] );
      else
        printf( "(%2d) ", grid[ r ][ c ] );
    }
    cout << endl;
  }

  cout << endl;
}
#endif

static int getMin( pi& start )
{
  // Can be elimated using recursion
  int minLadder = 0;
  int height = grid[ start.row ][ start.col ];
  visited.insert( start );
  for ( pi move : moves ) {
    pi newPoint = start + move;
    if ( legal( newPoint ) && visited.count( newPoint ) == 0 ) {
      // How much to climb
      int heightDiff = grid[ newPoint.row ][ newPoint.col ] - height;
      toVisit.push( { heightDiff, start, newPoint } );
    }
  }

  while ( !toVisit.empty() ) {
    const MoveInfo current = toVisit.top();
    toVisit.pop();
    start = current.point;
    // Already visited (could use a map)
    if ( visited.count( start ) > 0 ) {
      continue;
    }
  
    minLadder = max( minLadder, current.heightDiff );
    if ( start == endPoint )
      return minLadder;

    visited.insert( start );
    height = grid[ start.row ][ start.col ];
    for ( pi move : moves ) {
      pi newPoint = start + move;
      if ( legal( newPoint ) && visited.count( newPoint ) == 0 ) {
        REPORTP( newPoint );
        // How much to climb
        int heightDiff = grid[ newPoint.row ][ newPoint.col ] - height;
        REPORT( heightDiff );
        toVisit.push( { heightDiff, start, newPoint } );
      }
    }
  }

  return minLadder;
}

int main()
{
  cin >> rows >> cols;
  grid.resize( rows );
  for ( auto& row : grid )
    row.resize( cols );
  
  for ( int i = 0; i < rows; i++ )
    for ( int j = 0; j < cols; j++ )
      cin >> grid[ i ][ j ];
    
  endPoint = { rows - 1, cols - 1 };
  pi start = { 0, 0 };
  cout << getMin( start ) << endl;
}
