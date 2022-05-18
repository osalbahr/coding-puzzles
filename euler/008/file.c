#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define LINE_LENGTH 50
#define LINES 20

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
    int count = 13;

    long largest = 0;
    char line[ LINE_LENGTH + 1 ];
    while ( fscanf( input, "%s", line ) == 1 ) {
        long current = largestProduct( line, count );
        if ( current > largest ) {
            largest = current;
        }
    }

    printf( "Largest product of %d\nadjacesnt numbers: %ld\n", count, largest );

    fclose( input );
    return EXIT_SUCCESS;
}
