#include <stdio.h>

int main()
{
    int input;
    scanf( "%d", &input );

    int a = 0;
    int b = 1;
    
    for ( int i = 1; i < input; i++ ) {
      int newA = b;
      int newB = a;
      a += newA;
      b += newB;
      a -= newB;
    }
    
    printf( "%d %d\n", a, b );
}
