#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define LENGTH 1000

static long getProduct( char *line, int count )
{
    long product = 1;
    for ( int i = 0; i < count; i++ ) {
        product *= line[ i ] - '0';
    }

    return product;
}

static long largestProduct( char *line, int count )
{
    long largest = getProduct( line++, count );

    while( line[ count - 1 ] ) {
        long current = getProduct( ++line, count );

        if ( current > largest ) {
            largest = current;
        }
    }

    return largest;
}

int main()
{
    FILE *input = fopen( "input.txt", "r" );
    int count = 4;

    char line[ 1000 + 1 ];
    int ch;
    for ( int i = 0; ( ch = fgetc( input ) ) != EOF; i++ ) {
        line[ i ] = ch;
    }

    long largest = largestProduct( line, count );

    printf( "Largest product of %d\nadjacesnt numbers: %ld\n", count, largest );

    fclose( input );
    return EXIT_SUCCESS;
}
