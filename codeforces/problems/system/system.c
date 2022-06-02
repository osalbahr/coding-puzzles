#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
  char arr[ 100000 ][ 32 + 1 ];
  int aux[ 100000 ] = {};
  
  int n;
  scanf( "%d", &n );

  char str[ 32 + 1 ];

  int idx = 0;
  bool found;
  for ( int i = 0; i < n; i++ ) {
    scanf( "%s", str );

    found = false;
    int j;
    for ( j = 0; j < idx; j++ ) {
      if ( strcmp( arr[ j ], str ) == 0 ) {
        aux[ j ]++;
        found = true;
        break;
      }
    }

    if ( found ) {
      printf( "%s%d\n", str, aux[ j ] );
    } else {
      strcpy( arr[ idx++ ], str );

      //// weird bug?
      // aux[ idx ]++;
      
      printf( "OK\n" );
    }
  }
}
