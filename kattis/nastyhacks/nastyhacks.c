#include <stdio.h>

int main()
{
    int without;
    int with;
    int cost;
    
    int n;
    scanf( "%d", &n );
    
    for ( int i = 0; i < n; i ++ ) {
        scanf( "%d%d%d", &without, &with, &cost );
        int diff = ( with - without ) - cost;
        
        if ( diff > 0 ) {
            printf( "%s\n", "advertise" );
        } else if ( diff < 0 ) {
            printf( "%s\n", "do not advertise" );
        } else { // diff == 0
            printf( "does not matter" );
        }
    }
}
