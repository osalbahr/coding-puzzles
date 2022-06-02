#include <stdio.h>
#include <stdlib.h>

int getMin( char *str1, char *str2, int m )
{
    int min = 0;
    for ( int i = 0; i < m; i++ ) {
        min += abs( str1[ i ] - str2[ i ] );
    }
    
    return min;
}

int min( int a, int b )
{
    return a < b ? a : b;
}

int main()
{
    int t;
    scanf( "%d", &t );
    
    char strings[ 50 ][ 8 + 1 ];
    
    for ( int i = 0; i < t; i++ ) {
        int n, m;
        scanf( "%d %d", &n, &m );
        
        for ( int j = 0; j < n; j++ ) {
            scanf( "%s", strings[ j ] );
        }
        
        int result = 1000000;
        for ( int j = 0; j < n; j++ ) {
            for ( int k = j + 1; k < n; k++ ) {
                result = min( result, getMin( strings[ j ], strings[ k ], m ) );
            }
        }
        
        printf( "%d\n", result );
    }
}
