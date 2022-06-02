#include <stdio.h>

int getMid( int min, int max ) {
    return ( min + max ) / 2;
}

int main()
{
    char str[ 3 ];
    
    int min = 1, max = 1000000;
    
    int mid = getMid( min, max );
    while ( min != max ) {
        printf( "%d\n", mid );
        // fflush( stdout );
        
        scanf( "%s", str );
        
        if ( str[ 0 ] == '>' ) {
            min = mid;
            min += str[ 1 ] == '=' ? 0 : 1;
        } else if ( str[ 0 ] == '<' ) {
            max = mid;
            max -= str[ 1 ] == '=' ? 0 : 1;
        }

        int newMid = getMid( min, max );
        mid = newMid == mid ? mid + 1 : newMid;
    }
    
    printf( "! %d\n", min );
}
