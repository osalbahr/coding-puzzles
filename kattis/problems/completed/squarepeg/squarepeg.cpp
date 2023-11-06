#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double l, r;
  cin >> l >> r;

  double diameter = r * 2;

  double diagonal = l * sqrt(2);
  cout << ( diameter >= diagonal ? "fits" : "nope" ) << endl;
}
