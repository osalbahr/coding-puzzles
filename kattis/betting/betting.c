#include <stdio.h>

int main()
{
 double a;
 scanf( "%lf", &a );
 printf( "%f\n%f\n", 100 / a, 100 / ( 100 - a ) );
}
