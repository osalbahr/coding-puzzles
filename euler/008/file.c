#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define LINE_LENGTH 50
#define LINES 20

static int getProduct( char *line, int count )
{
    int product = 1;
    for ( int i = 0; i < count; i++ ) {
        product *= line[ i ] - '0';
    }

    return product;
}

static int largestProduct( char *line, int count )
{
    int largest = getProduct( line++, count );

    while( line[ count - 1 ] ) {
        int current = getProduct( ++line, count );

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

    int largest = 0;
    char line[ LINE_LENGTH + 1 ];
    while ( fscanf( input, "%s", line ) == 1 ) {
        int current = largestProduct( line, count );
        if ( current > largest ) {
            largest = current;
        }
    }

    printf( "Largest product of %d\nadjacesnt numbers: %d\n", count, largest );

    fclose( input );
    return EXIT_SUCCESS;
}
