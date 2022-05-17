#include <stdlib.h>
#include <stdio.h>

int main()
{
    // Naive approach, I know
    int total = 0;

    for ( int i = 1; i < 1000; i++ ) {
        if ( i % 3 == 0 || i % 5 == 0 )
            total += i;
    }

    printf( "Answer: %d\n", total );

    // Better: arithmetic sum formulas
    // Ans = sum_15 - (sum_3 + sum_5)

    return EXIT_SUCCESS;
}
