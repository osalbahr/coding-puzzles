#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define LINE_LENGTH 50
#define LINES 20

static int largestProduct( char *line, int count )
{
    int index = 0;
    int largest = 1;

    // Multiply first count digits
    for ( int i = 0; i < count; i++ ) {
        largest *= line[ index++ ] - '0';
    }

    // Get new ones as you go, dropping first, adding last
    int current = largest;
    while ( line[ index ] ) {
        current /= line[ index - count ] - '0';
        current *= line[ index++ ] - '0';

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

    int largest = -1;
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
