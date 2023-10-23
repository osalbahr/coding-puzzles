#include <stdio.h>
#include <string.h>

int main()
{
  char idealString[ 3 * 100 + 1 ];
  idealString[ 0 ] = '\0';
  char inputString[ 3 * 100 + 1 ];

  int n;
  
  scanf( "%d %s", &n, inputString );

  char str[ 3 + 1 ];
  for ( int i = 1; i <= n; i++ ) {
    sprintf( str, "%d", i );
    strcat( idealString, str );

    if ( strncmp( idealString, inputString, strlen( idealString ) ) ) {
      printf( "%d\n", i );
      break;
    }
  }
}
