#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>

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

void solve()
{
  int r, n;
  double d, m, s;
  cin >> r >> n >> d >> m >> s;

  cout << n << endl;

  double theta = d + m / 60 + s / 3600;

  set<int> angles;
  double current = 0;
  for ( int i = 0; i < n; i++ ) {
    current += theta;
    current -= current >= 360 ? 360 : 0;
    angles.insert( current );
  }

  double biggestDelta = -1;
  set<int>::iterator it = angles.begin();
  double prev = *(it++);
  for ( int i = 0; i < n - 1; i++ ) {
    double next = *(it++);
    double currentDelta = next - prev;
    prev = next;

    biggestDelta = max( biggestDelta, currentDelta );
  }
  
  double specialDelta = 360 - ( *( --angles.end() ) - *angles.begin() );
  biggestDelta = max( biggestDelta, specialDelta );
  
  cout << setprecision( 9 ) << M_PI * r * r * biggestDelta / 360 << endl;
}

int main()
{
  int m;
  cin >> m;

  while ( m-- ) {
    
    solve();
  }
}
