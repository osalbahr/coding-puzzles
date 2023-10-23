#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
  double r, h1, h2;
  cin >> r >> h1 >> h2;
  r = 1000 * r;

  double theta = acos( r/(r+h1) ) + acos( r/(r+h2) );
  double dist = theta / (2*M_PI) * (r / 1000) * 2*M_PI;
  cout << dist << endl;
}

int main()
{
  int t;
  cin >> t;
    
  while ( t-- ) {
    solve();
  }
}
