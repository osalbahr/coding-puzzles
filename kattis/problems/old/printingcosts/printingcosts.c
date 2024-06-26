#include <stdio.h>

int main()
{
  char src[] = "0 9 6 24 29 22 24 3 12 12 17 13 7 7 4 10 22 19 22 23 21 27 26 16 23 26 8 11 10 14 10 15 32 24 29 20 26 26 20 25 25 18 18 21 16 28 25 26 23 31 28 25 16 23 19 26 18 14 22 18 10 18 7 8 3 23 25 17 25 23 18 30 21 15 20 21 16 22 18 20 25 25 13 21 17 17 13 19 13 24 19 18 12 18 9";

  int costs[ 95 ];

  // FILE *src = fopen( "costs.txt", "r" );
  
  // char skip;
  int pos = 0;
  int diff;
  for ( int i = 0; i < 95; i++ ) {
    // scanf ( src, "%d %c", &costs[ i ], &skip );
    sscanf( src + pos, "%d%n", &costs[ i ], &diff );
    pos += diff;
    // printf( "%d ", costs[ i ] );
  }
  
  int total = 0;
  int ch;
  while ( ( ch = getchar() ) != EOF ) {
    if ( ch == '\n' ) {
      printf( "%d\n", total );
      total = 0;
      continue;
    }

    int idx = ch - ' ';
    total += costs[ idx ];
  }
  
  // If last line did not end with \n
  if ( total != 0 ) {
    printf( "%d\n", total );
  }
}
