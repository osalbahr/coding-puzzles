#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    for ( int i = 1; i < 998; i++ ) {
        for ( int j = i; j < 998; j++ ) {
            int k = 1000 - i - j;

            if ( pow( i, 2 ) + pow( j, 2 ) == pow( k, 2 ) ) {
                printf( "%d * %d * %d = %d", i, j, k, i * j * k );
            }
        }
    }

    return EXIT_SUCCESS;
}
