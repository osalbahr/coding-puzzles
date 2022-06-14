#include <iostream>
#include <iomanip>
#include <algorithm>

#include <stdlib.h>
#include <stdbool.h>

using namespace std;

#define N_MAX 100000000
#define M_PI 3.14159265358979323846

#define printList( list, n ) \
for ( int i = 0; i < n; i++ ) { \
  cout << list[ i ] << " "; \
} \
cout << endl;
// #define double long double

void solve( double *angles )
{
  int r, n;
  double d, m, s;
  cin >> r >> n >> d >> m >> s;

  cout << n << endl;

  double theta = d + m / 60 + s / 3600;

  double current = 0;
  for ( int i = 0; i < n; i++ ) {
    current += theta;
    current -= current >= 360 ? 360 : 0;
    angles[ i ] = current;
  }

  sort( angles, angles + n );

  double biggestDelta = -1;
  for ( int i = 0; i < n - 1; i++ ) {
    double currentDelta = angles[ i + 1 ] - angles[ i ];

    if ( currentDelta == 0 ) continue;

    biggestDelta = max( biggestDelta, currentDelta );
  }
  
  double specialDelta = 360 - ( angles[ n - 1 ] - angles[ 0 ] );
  biggestDelta = max( biggestDelta, specialDelta );
  
  cout << setprecision( 9 ) << M_PI * r * r * biggestDelta / 360 << endl;
}

int main()
{
  int m;
  cin >> m;

  double *angles = (double *)malloc( N_MAX * sizeof( double ) );
    
  while ( m-- ) {
    
    solve( angles );
  }
}
