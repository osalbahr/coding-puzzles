#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static bool isPalindrome( char *str )
{
    int length = strlen( str );

    for ( int i = 0; i < length / 2; i++ ) {
        if ( str[ i ] != str[ length - i - 1 ] ) {
            return false;
        }
    }

    return true;
}

int main()
{
    // Enough to hold 999 * 999
    char str[ 7 ];

    // printf( "%d%d\n", isPalindrome( "9009"), isPalindrome( "9109" ) );

    int largest = -1;

    for ( int i = 100; i < 1000; i++ ) {
        for ( int j = i; j < 1000; j ++ ) {
            int product = i * j;
            sprintf( str, "%d", product );
            if ( product > largest && isPalindrome( str ) ) {
            // if ( isPalindrome( str ) && product > largest ) {

                largest = product;
            }
        }
    }

    printf( "Largest 3 by 3 palindrome: %d\n", largest );

    return EXIT_SUCCESS;
}
