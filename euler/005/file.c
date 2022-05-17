#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    /*
        Well, the numbers 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        have prime factors 2^3, 3^2, 5, and 7
    */

   int upTo10 = pow( 2, 3 ) * pow( 3, 2 ) * 5 * 7;
   printf( "%d\n", upTo10 );

    /*
        Well, the numbers 1 to 20
        1, 2, 3, 4, 5
        6, 7, 8, 9, 10
        11, 12, 13, 14, 15
        16, 17, 18, 19, 20

        have prime factors 2^4, 3^2, 5, 7, 11, 13, 17
    */

    int upTo20 = pow( 2, 4 ) * pow( 3, 2 ) * 5 * 7 * 11 * 13 * 17 * 19;
    printf( "%d\n", upTo20 );

    // Check
    bool flag = true;
    for( int i = 1; i <= 20; i++ ) {
        char trueString[] = "True";
        char falseString[] = "False";

        char *resultString;
        if ( upTo20 % i == 0 ) {
            resultString = trueString;
        } else {
            resultString = falseString;
            flag = false;
        }

        printf( "%d: %s\n", i, resultString );
    }

    char success[] = "Success!";
    char failure[] = "Failure :(";
    char *resultString;
    if ( flag ) {
        resultString = success;
    } else {
        resultString = failure;
    }
    printf( "%s\n", resultString );

    return EXIT_SUCCESS;
}
