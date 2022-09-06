#include <iostream>
#include <cmath>
#include <iomanip>

#include <stdlib.h>
#include <stdbool.h>

using namespace std;

#define PI 3.14159265358979323846

// Vaccum = 2/3 * PI * 0.25 * big^3 - 2/3 * PI * 0.25 * small^3


void solve( int d, int v )
{
  cout << setprecision( 9 ) << -cbrt( ( v - (double)2/3 * PI * 0.25 * pow( d, 3 ) ) / ( (double)2/3 * PI * 0.25 ) ) << endl;
}

int main()
{
  int d, v;
    
  while ( cin >> d >> v && d != 0 ) {
    solve( d, v );
  }
}
