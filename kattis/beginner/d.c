#include <stdio.h>
#include <math.h>

static int min( int a, int b, int c )
{
  int min1 = a <= b ? a : b;
  return min1 <= c ? min1 : c; 
}

int main()
{
  int t = 0, c = 0, g = 0;

  int ch;
    while ( ( ch = getchar() ) != '\n' ) {
      if ( ch == 'T' ) {
        t++;
      } else if ( ch == 'C' ) {
        c++;
      } else if ( ch == 'G' ) {
        g++;
      }
    }

  printf( "%d\n", t * t + c * c + g * g + 7 * min( t, c, g ) ); 
}
