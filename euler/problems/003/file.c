#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// True if j has a factor k
static bool isFactor( long j, long k )
{
    return j % k == 0;
}

static bool isPrime( long n )
{
    for ( long i = 2; i < sqrt( n ); i++ ) {
        if ( isFactor( n, i ) ) {
            return false;
        }
    }

    return true;
} 

int main()
{
    long target = 600851475143;
    long largest = -1;
    long limit = sqrt( target );

    for ( long i = 3; i < limit; i += 2 ) {
        if ( isFactor( target, i ) &&  isPrime( i ) ) {
            largest = i;
            target /= i;
            limit = sqrt( target );
        }
    }

    printf( "Largest prime factor: %ld\n", target );

    return EXIT_SUCCESS;
}
