#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double distance( pair<int, int> k, pair<int, int> o )
{
  int x = abs( k.first - o.first );
  int y = abs( k.second - o.second );
  return sqrt( x*x + y*y );
}

int main()
{
  pair<int, int> ki;
  pair<int, int> oi;
  pair<int, int> kf;
  pair<int, int> of;
  cin >> ki.first >> ki.second;
  cin >> oi.first >> oi.second;
  cin >> kf.first >> kf.second;
  cin >> of.first >> of.second;
  cout << max( distance( ki, oi ), distance( kf, of ) ) << endl;
}
