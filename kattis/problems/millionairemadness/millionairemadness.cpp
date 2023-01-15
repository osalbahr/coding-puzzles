#include <iostream>
#include <vector>
#include <set>
#include <queue>

#include <stdlib.h>
#include <stdbool.h>

using namespace std;

#define REPORT( X ) cout << #X << " = " << X << endl;

typedef pair<int,int> pi;

int rows, cols;
vector<pi> moves;

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

vector<vector<int>> grid;
set<pi> visited;

typedef struct {
  int heightDiff;
  int idx;
} MoveInfo;

bool my_less_than( const MoveInfo& a, const MoveInfo& b ) {
  return a.heightDiff < b.heightDiff;
}

static bool getMin( pi start, int ladder )
{
  int height = grid[ start.first ][ start.second ];
  vector<pi> candidates;
  vector<MoveInfo> infos;
  for ( pi move : moves ) {
    pi current = start + move;
    int idx = 0;
    if ( legal( current ) && visited.insert( current ).second ) {
      int newHeight = grid[ current.first ][ current.second ];
      MoveInfo info = { newHeight - height, idx++ };
      candidates.push_back( current );
      infos.push_back( info );
    }
  }

  sort( infos.begin(), infos.end(), my_less_than );

  return false;
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
  
  vector<int> diffs = { 0, 1, -1 };
  for ( int diff : diffs )
    for ( int diff2 : diffs )
      if ( diff != 0 && diff2 != 0 )
        continue;
      else
        moves.push_back( { diff, diff2 } );
  
  cout << getMin( { 0, 0 }, 0 ) << endl;
}
