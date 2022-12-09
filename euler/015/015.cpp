#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

map<pair<int,int>, long> paths;

long depth = 0;

// n x n has n x n + 1 corners
int size = 2 + 1;
// Recursively get the number of pahts
// (i, j) -> (size-1, size-1)
static long getPaths( int i, int j )
{
  auto it = paths.find( { i, j } );
  if ( it != paths.end() )
    return it->second;

  depth++;
  // printf( "size = %d, i = %d, j = %d, depth = %d\n", size, i, j, depth );
  // cout << i << endl;
  // cout << j << endl;
  // cout << endl;

  if ( i == size - 1 && j == size - 1 )
    return 1;
  
  // Shortcut
  if ( i == j )
    return 2 * getPaths( i + 1, j );
  
  long total = 0;

  // Try right
  if ( i + 1 < size ) {
    if ( i + 1 < size )
      total += getPaths( i + 1, j );
  }
  
  // Try down;
  if ( j + 1 < size )
    total += getPaths( i, j + 1 );

  paths[ { i, j } ] = total;
  return total;
}

int main( int argc, char *argv[] )
{
  if ( argv[ 1 ] )
    size = atoi( argv[ 1 ] ) + 1;

  cout << getPaths( 0, 0 ) << endl;
  cout << "depth = " << depth << endl;
}