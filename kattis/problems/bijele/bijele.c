#include <stdio.h>

int main()
{
  int counts[] = { 1, 1, 2, 2, 2, 8 };

  int current;
  scanf( "%d", &current );
  printf( "%d", counts[ 0 ] - current );

  for ( int i = 1; i < 6; i++ ) {
    scanf( "%d", &current );
    printf( " %d", counts[ i ] - current );
  }

  printf( "\n" );
}
