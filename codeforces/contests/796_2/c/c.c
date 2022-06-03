#include <stdio.h>

int main()
{
  int t;
  scanf( "%d", &t );

  char ch;
  scanf( "%*d %c", &ch );

  for (;;) {
    printf( "%c\n", ch );

    int n;
    while ( scanf( "%d", &n ) != 1 ) {
      if ( scanf( "%*s" ) == -1 ) {
        return 0;
      }
    }

    scanf( " %c", &ch );
  }
}
