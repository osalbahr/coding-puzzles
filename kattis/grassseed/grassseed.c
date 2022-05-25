#include <stdio.h>

int main()
{
  double cost;
  int count;
  scanf( "%lf%d", &cost, &count );

  double total = 0;
  for ( int i = 0; i < count; i++ ) {
    double n;
    double m;
    scanf( "%lf%lf", &n, &m );
    total += n * m;
  }
  total *= cost;

  printf( "%f\n", total );
}
