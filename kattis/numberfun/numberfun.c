#include <stdio.h>

int main()
{
    int n;
    scanf( "%d", &n );
    
    int a;
    int b;
    int c;
    int flag;
    for ( int i = 0; i < n; i++ ) {
        flag = 0;
        scanf( "%d %d %d", &a, &b, &c );

        if ( a + b == c ) {
            flag = 1;
        } else if ( a * b == c ) {
            flag = 1;
        } else if ( c * a == b || c * b == a ) {
            flag = 1;
        } else if ( a - b == c || a - b == -c ) {
            flag = 1;
        }
        
        if ( flag ) {
            printf( "Possible\n" );
        } else {
            printf( "Impossible\n" );
        }
    }
}
