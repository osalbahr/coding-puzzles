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
        for ( int j = 0; j < 20 - 4; j++ ) {
            int current = 1;
            for ( int k = 0; k < 4; k++ ) {
                current *= row[ j + k ];
            }
            rowLargest = max( rowLargest, current );
        }
        largest = max( largest, rowLargest );
    }

    return largest;
}

static int getLargestVertical( int grid[][ 20 ] )
{
    int largest = -1;

    for ( int j = 0; j < 20; j++ ) {
        int columnLargest = -1;
        for ( int i = 0; i < 20 - 3; i++ ) {
            int current = 1;
            for ( int k = 0; k < 4; k++ ) {
                current *= grid[ i + k ][ j ];
            }
            columnLargest = max( columnLargest, current );
        }
        largest = max( largest, columnLargest );
    }

    return largest;
}

static int getLargestDiagonal1( int grid[][ 20 ] )
{
    int largest = -1;

    for ( int i = 0; i < 20 - 4; i++ ) {
        int waveLargest = -1;
        for ( int j = 0; j < 20 - 4; j++ ){
            int current = 1;
            for ( int k = 0; k < 4; k++ ) {
                current *= grid[ i + k ][ j + k ]; 
            }
            waveLargest = max( waveLargest, current );
        }
        largest = max( largest, waveLargest );
    }

    return largest;
}

static int getLargestDiagonal2( int grid[][ 20 ] )
{
    int largest = -1;

    for ( int i = 0; i < 20 - 4; i++ ) {
        int waveLargest = -1;
        for ( int j = 20 - 1; j >= 4 - 1; j-- ) {
            int current = 1;
            for ( int k = 0; k < 4; k++ ) {
                current *= grid[ i - k ][ j - k ];
            }
            waveLargest = max( waveLargest, current );
        }
        largest = max( largest, waveLargest );
    }

    return largest;
}

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
    int largestVertical = getLargestVertical( grid );
    int largestDiagonal1 = getLargestDiagonal1( grid );
    int largestDiagonal2 = getLargestDiagonal2( grid );

    printf( "Largest horizontal: %d\n", largestHorizontal );
    printf( "Largest vertical: %d\n", largestVertical );
    int max12 = max( largestHorizontal, largestVertical );
    printf( "max of 1-2: %d\n", max12 );
    printf( "Largest diagonal1: %d\n", largestDiagonal1 );
    printf( "Largest diagonal2: %d\n", largestDiagonal2 );
    int max34 = max( largestDiagonal1, largestDiagonal2 );
    printf( "max of 3-4: %d\n", max34 );
    int maxAll = max( max12, max34 );
    printf( "max of all: %d\n", maxAll );

    return EXIT_SUCCESS;
}
