#include <stdio.h>
#include <stdlib.h>

int cmp( const void *aptr, const void *bptr )
{
    int const *a = (int *) aptr;
    int const *b = (int *) bptr;
    
    return *a - *b;
}

int main()
{
    int list[ 1000 ];
    
    int n;
    scanf( "%d", &n );
    
    for ( int i = 0; i < n; i++ ) {
        int x;
        scanf( "%d", &x );
        list[ i ] = x;
    }
    
    qsort( list, n, sizeof( int ), cmp );
    
    // Use maximal munch
    for ( int i = 0; i < n; i++ ) {
        int munch = 1;
        int j = i + 1;
        for ( j = i + 1; j < n; j++ ) {
            if ( list[ j - 1 ] == list[ j ] - 1 ) {
                munch++;
            } else {
                break;
            }
        }
        j--;
        
        if ( munch >= 3 ) {
            printf( "%d-%d ", list[ i ], list[ j ] );
            i = j;
        } else {
            printf( "%d ", list[ i ] );
        }
    }

    printf( "\n" );
}
