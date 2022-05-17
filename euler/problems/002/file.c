#include <stdlib.h>
#include <stdio.h>

int fibb( int n )
{
    if ( n == 1 ) {
        return 1;
    }

    if ( n == 2 ) {
        return 2;
    }

    return fibb( n - 2 ) + fibb( n - 1 );
}

int main()
{
    // 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
    int total = 0;

    for ( int i = 1, current = fibb( i ); current <= 89; current = fibb( i++ ) ) {
        if ( current % 2 == 0 ) {
            total += current;
        }
    }

    printf( "Expected: %d\n", 2 + 8 + 34 );
    printf( "Actual: %d\n", total );


    return EXIT_SUCCESS;
}
