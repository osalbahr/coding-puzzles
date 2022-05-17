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

static int getPrime( int targetN )
{
    int n = 1;
    int currentPrime = 2;

    for ( int i = 3; n < targetN; i += 2 ) {
        if ( isPrime( i ) ) {
            n++;
            currentPrime = i;
        }
    }

    return currentPrime;
}

int main()
{
    int n = 2;
    int prime = 5;
    prime = getPrime( n );

    // printf( "The %d'th prime is %d\n", n, prime );

    // for ( int i = 1; i < 11; i++ ) {
    //     printf( "The %d'th prime is %d\n", i, getPrime( i ) );
    // }

    printf( "The %d'th prime is %d\n", 10001, getPrime( 10001 ) );

    return EXIT_SUCCESS;
}
