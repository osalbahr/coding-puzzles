#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static int sumOfSquares( int min, int max )
{
    int total = 0;

    for ( int i = min; i <= max; i++ ) {
        total += pow( i, 2 );
    }

    return total;
}

static int squareOfSum( int min, int max )
{
    int sum = 0;

    for ( int i = min; i <= max; i++ ) {
        sum += i;
    }

    return pow( sum, 2 );
}

static int problem6( int min, int max ) {
    return squareOfSum( min, max ) - sumOfSquares( min, max );
}

int main()
{
    int min = 1;
    int max = 10;
    int result = problem6( min, max );
    printf( "Up to 10: %d\n", result );

    max = 100;
    result = problem6( min, max );
    printf( "Up to 100: %d\n", result );

    return EXIT_SUCCESS;
}
