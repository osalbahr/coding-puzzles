#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


// True if j has a factor k
static bool isFactor( long j, long k )
{
    return j % k == 0;
}

// No need to check if even; already taken care of
static bool isPrime( long n )
{
    for ( long i = 3; i <= sqrt( n ); i += 2 ) {
        if ( isFactor( n, i ) ) {
            return false;
        }
    }

    return true;
} 

int main()
{
    long total = 0;
    long cap = 2 * pow( 10, 6 );

    total += 2;

    for ( long i = 3; i < cap; i += 2 ) {
        if ( isPrime( i ) ) {
            total += i;
        }
    }

    printf( "Total = %ld", total );

    return EXIT_SUCCESS;
}
