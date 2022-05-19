#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static int max( int a, int b )
{
    return a >= b ? a : b;
}

static int getLargestHorizontal( int grid[][ 20 ] )
{
    int largest = -1;

    for ( int i = 0; i < 20; i++ ) {
        int *row = grid[ i ];
        int rowLargest = -1;
        for ( int j = 0; j < 20 - 3; j++ ) {
            int current = 1;
            for ( int k = 0; k < 4; k++ ) {
                current *= row[ j + k ];
            }
            rowLargest = max( rowLargest, current );
        }
        largest = max( largest, rowLargest );
    }
}

// static int getLargestVertical( int grid[][ 20 ] )
// {

// }

// static int getLargestDiagonal1( int grid[][ 20 ] )
// {

// }

// static int getLargestDiagonal2( int grid[][ 20 ] )
// {

// }

int main()
{
    int grid[ 20 ][ 20 ];

    FILE *input = fopen( "grid_20by20.txt", "r" );

    for ( int i = 0; i < 20; i++ ) {
        for ( int j = 0; j < 20; j++ ) {
            int current;
            fscanf( input, "%d", &current );
            grid[ i ][ j ] = current;
        }
    }

    // // Test grid
    // for ( int i = 0; i < 20; i++ ) {
    //     for ( int j = 0; j < 20; j++ ) {
    //         printf( "%d ", grid[ i ][ j ] );
    //     }

    //     printf( "\n" );
    // }

    int largestHorizontal = getLargestHorizontal( grid );
    // int largestVertical = getLargestVertical( grid );
    // int largestDiagonal1 = getLargestDiagonal1( grid );
    // int largestDiagonal2 = getLargestDiagonal2( grid );

    return EXIT_SUCCESS;
}
