#include <iostream>
#include <iomanip>      // std::setprecision

#include <stdlib.h>
#include <stdbool.h>

using namespace std;

int main()
{
  float r, c;
  cin >> r >> c;
  float bigger = r;
  float smaller = r - c;
  cout << setprecision( 2 + 6 ) << ( smaller * smaller ) / ( bigger * bigger ) * 100 << endl;
}
